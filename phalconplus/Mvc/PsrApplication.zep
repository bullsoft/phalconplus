//<?php
namespace PhalconPlus\Mvc;
use Phalcon\Mvc\Application as BaseApplication;
use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\ResponseInterface;
use Phalcon\DiInterface;
use Psr\Http\Message\UploadedFileInterface;
use Phalcon\Http\Cookie;

class PsrApplication extends BaseApplication
{
    protected psrRequest = null {
        set, get
    };

    protected nativeRequest = null {
        get
    };

    public function __construct(<DiInterface> dependencyInjector = null, <ServerRequestInterface> psrRequest = null)
    {
        parent::__construct(dependencyInjector);
        let this->_sendHeaders = false;
        let this->_sendCookies = false;
        let this->psrRequest = psrRequest;
        // Phalcon\Http\Request
        let this->nativeRequest = new \PhalconPlus\Http\NonPsrRequest(psrRequest);
    }

    public function __destruct()
    {
        if this->nativeRequest {
            this->nativeRequest->removeTmpFiles();
        }
    }

    public function handle(string uri = null) -> <ResponseInterface> | boolean
    {
        var psrRequest;

        if empty this->_dependencyInjector {
            throw new \PhalconPlus\Base\Exception("there is no di(dependency injector) in PsrAppliction");
        }

        if !empty this->psrRequest {
            let psrRequest = this->psrRequest;
        } else {
            throw new \PhalconPlus\Base\Exception("request in PsrApplication must instance of \\Psr\\Http\\Message\\ServerRequestInterface");
        }
        
        if !class_exists("\\GuzzleHttp\\Psr7\\Response") {
            throw new \PhalconPlus\Base\Exception("PsrApplication depends on GuzzleHttp\\Psr7\\Response");
        }

        this->_dependencyInjector->setShared("request", this->nativeRequest);

        // get request uri-path
        var reqUri = psrRequest->getUri()->getPath();
        // get Phalcon\Http\Response
        var response;

        ob_start();
        let response = <\Phalcon\Http\Response> parent::handle(reqUri);
        var stdout = ob_get_clean();

        var headers = this->mapHeaders(response);
        var status = response->getStatusCode();
        var reason = response->getReasonPhrase();

        ob_start();
        response->send();
        var content = ob_get_clean();

        if !empty stdout {
            let content = stdout . content;
        }
        
        var psrResponse;
        let psrResponse = new \GuzzleHttp\Psr7\Response(status?status:200, headers, content, psrRequest->getProtocolVersion(), reason?reason:"OK");

        if !isset(headers["Content-Length"]) {
            let psrResponse = psrResponse->withAddedHeader("Content-Length", strlen(content));
        }

        return psrResponse;
    }

    protected function mapHeaders(<\Phalcon\Http\Response> response)
    {
        var headers = response->getHeaders()->toArray();
        
        var rawHeaders = headers_list();
        var h, pos, nativeHeaders = [];
        for h in rawHeaders {
            let pos = strpos(h, ":");
            if false !== pos {
                var name = substr(h, 0, pos);
                var value = trim(substr(h, pos + 1));
                if isset(nativeHeaders[name]) {
                    if !is_array(nativeHeaders[name]) {
                        let nativeHeaders[name] = [nativeHeaders[name]];
                    }
                    let nativeHeaders[name][] = value;
                } else {
                    let nativeHeaders[name] = value;
                }
            }
        }
        // after reading all headers we need to reset it, so next request
        // operates on a clean header.
        header_remove();
        let headers = array_merge(nativeHeaders, headers);
        
        if isset(nativeHeaders["Set-Cookie"]) {
            let headers["Set-Cookie"] = is_array(nativeHeaders["Set-Cookie"])?nativeHeaders["Set-Cookie"]:[nativeHeaders["Set-Cookie"]];
        } else {
            let headers["Set-Cookie"] = null;
        }
        return headers;
    }
}