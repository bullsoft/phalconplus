//<?php
namespace PhalconPlus\Base;
use Phalcon\Mvc\Application as BaseApplication;
use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\ResponseInterface;
use Phalcon\DiInterface;
use Psr\Http\Message\UploadedFileInterface;
use Phalcon\Http\Cookie;

class PsrApplication extends BaseApplication
{
    protected request = null {
        set, get
    };

    protected post = [] {
        set, get
    };

    protected tempFiles = [] {
        get
    };

    public function __construct(<DiInterface> dependencyInjector = null, <ServerRequestInterface> request = null)
    {
        parent::__construct(dependencyInjector);
        let this->request = request;
    }

    public function handle(string uri = null) -> <ResponseInterface> | boolean
    {
        var uri, request;

        if !empty this->request {
            let request = this->request;
        } else {
            throw new \PhalconPlus\Base\Exception("request in PsrApplication must instance of \\Psr\\Http\\Message\\ServerRequestInterface");
        }

        // Phalcon\Http\Request
        var nativeRequest;
        let nativeRequest = new \PhalconPlus\Base\PsrRequest(request);
        this->getDI()->setShared("request", nativeRequest);

        if !class_exists("\\GuzzleHttp\\Psr7\\Response") {
            throw new \PhalconPlus\Base\Exception("PsrApplication depends on GuzzleHttp\\Psr7\\Response");
        }

        var cookies = [], cookie;

        let cookies = nativeRequest->getCookies();
        var nativeHeaders = nativeRequest->getHeaders();
        
        if !empty cookies {
            if isset cookies[session_name()] {
                session_id(cookies[session_name()]);
            }
        }

        let uri = request->getUri()->getPath();
        // get Phalcon\Http\Response
        var response;
        let response = <\Phalcon\Http\Response> parent::handle(uri);

        // convert to Psr7
        var content = call_user_func([response, "getContent"]); // @TODO: parse error when invoke getContent through "->"
        var headers = response->getHeaders()->toArray();
        var status = response->getStatusCode();
        var reason = response->getReasonPhrase();
        
        if session_status() == PHP_SESSION_ACTIVE  {
            if !isset(cookies[session_name()]) {
                let cookie = new Cookie(session_name(), session_id(), time() + 3600, "/", nativeRequest->getHttpHost());
                var cookieHeader = sprintf("%s=%s", cookie->getName(), cookie->getValue());
                if cookie->getPath() {
                    let cookieHeader .= "; Path=" . cookie->getPath();
                }
                if cookie->getDomain() {
                    let cookieHeader .= "; Domain=" . cookie->getDomain();
                }
                if cookie->getExpiration() {
                    let cookieHeader .= "; Expires=" . gmdate("D, d-M-Y H:i:s", cookie->getExpiration() + date("Z")). " ". date("T");
                }
                let headers["Set-Cookie"][] = cookieHeader;
            }
        }
    
        // after reading all headers we need to reset it, so next request
        // operates on a clean header.
        // header_remove();
        // for cookie in response->getCookies() {
        //     var cookieHeader = sprintf("%s=%s", cookie->getName(), cookie->getValue());
        //     if cookie->getPath() {
        //         let cookieHeader .= "; Path=" . cookie->getPath();
        //     }
        //     if cookie->getDomain() {
        //         let cookieHeader .= "; Domain=" . cookie->getDomain();
        //     }
        //     if cookie->getExpiresTime() {
        //         let cookieHeader .= "; Expires=" . gmdate("D, d-M-Y H:i:s", cookie->getExpiresTime()). " GMT";
        //     }
        //     if cookie->getMaxAge() {
        //         let cookieHeader .= "; Max-Age=" . cookie->getMaxAge();
        //     }
        //     if cookie->isSecure() {
        //         let cookieHeader .= "; Secure";
        //     }
        //     if $cookie->isHttpOnly() {
        //         let cookieHeader .= "; HttpOnly";
        //     }
        //     let cookies[] = cookieHeader;
        // }
        // if isset(nativeHeaders["Set-Cookie"]) {
        //     let headers["Set-Cookie"] = array_merge((array)nativeHeaders["Set-Cookie"], cookies);
        // } else {
        //     let headers["Set-Cookie"] = cookies;
        // }
        
        return new \GuzzleHttp\Psr7\Response(status?status:200, headers, content, request->getProtocolVersion(), reason?reason:"OK");
    }
}