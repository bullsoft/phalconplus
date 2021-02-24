namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use Phalcon\Di\Injectable;
use Phalcon\Application\AbstractApplication as BaseApplication;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use Phalcon\Http\ResponseInterface as HttpResponse;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Mvc\Application as MvcHandler;
use PhalconPlus\Mvc\PsrApplication as PsrHandler;

use Psr\Http\Message\ServerRequestInterface;

class Web extends AbstractEngine
{
    public function __construct(<AppModule> appModule, <BaseApplication> handler = null)
    {
        if is_null(handler) {
            let handler = new MvcHandler();
        }
        parent::__construct(appModule, handler);
    }

    /**
    * @request a uri string (for \Phalcon\Mvc\Application) or Psr\Http\Message\Request
    */
    public function exec(var uri = null) -> <HttpResponse>
    {
        if this->handler instanceof PsrHandler {
            var request;
            if is_object(uri) && uri instanceof ServerRequestInterface {
                let request = uri;
            } else {
                string className = "GuzzleHttp\\Psr7\\ServerRequest";
                let request = {className}::fromGlobals();
            }
            return this->handler->handle(request);
        } elseif this->handler instanceof MvcHandler {
            return this->handler->handle(strval(uri));
        }

        throw new BaseException("Handler for Web-Engine must be PsrHandler or MvcHandler");
    }
}