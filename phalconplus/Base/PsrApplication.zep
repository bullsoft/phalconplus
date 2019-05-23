//<?php
namespace PhalconPlus\Base;
use Phalcon\Mvc\Application as BaseApplication;
use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\ResponseInterface;
use Phalcon\DiInterface;

class PsrApplication extends BaseApplication
{
    protected request = null {
        set, get
    };

    public function __construct(<DiInterface> dependencyInjector = null, <ServerRequestInterface> request = null)
    {
        parent::__construct(dependencyInjector);
        let this->request = request;
    }

    public function handle(var request = null)  -> <ResponseInterface>
    {
        if unlikely ! (request instanceof ServerRequestInterface) {
            if !empty this->request {
                let request = this->request;
            } else {
                throw new \PhalconPlus\Base\Exception("request in PsrApplication must instance of \\Psr\\Http\\Message\\ServerRequestInterface");
            }
        }

        if !class_exists("\\GuzzleHttp\\Psr7\\Response") {
            throw new \PhalconPlus\Base\Exception("PsrApplication depends on GuzzleHttp\\Psr7\\Response");
        }

        // get Phalcon\Http\Response
        var response;
        let response = <\Phalcon\Http\Response> parent::handle(request->getUri()->getPath());

        // convert to Psr7
        var content = call_user_func([response, "getContent"]); // @TODO: parse error when invoke getContent through "->"
        var headers = response->getHeaders()->toArray();
        var status = response->getStatusCode();
        var reason = response->getReasonPhrase();
        return new \GuzzleHttp\Psr7\Response(status?status:200, headers, content, "1.1", reason?reason:"OK");
    }
    
}