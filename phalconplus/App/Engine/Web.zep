namespace PhalconPlus\App\Engine;
use PhalconPlus\App\App as SuperApp;
use Phalcon\Di\Injectable;
use Phalcon\Application\AbstractApplication as BaseApplication;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use Phalcon\Mvc\Application as MvcHandler;
use Phalcon\Http\ResponseInterface as HttpResponse;
use PhalconPlus\Base\Exception as BaseException;

class Web extends Injectable implements AppEngine
{
    protected appModule = null;
    protected handler = null;

    public function __construct(<AppModule> appModule, <BaseApplication> handler = null)
    {
        let this->appModule = appModule;

        var di = appModule->di();
        this->setDI(di);

        if is_null(handler) {
            let this->handler = new MvcHandler();
        } else {
            let this->handler = handler;    
        }

        this->handler->setDI(di);
        this->handler->setEventsManager(di->get("eventsManager"));
    }

    /**
    * @request a uri string (for \Phalcon\Mvc\Application) or Psr\Http\Message\Request
    */
    public function exec(var uri = null) -> <HttpResponse>
    {
        if !is_string(uri) || empty(uri) {
            let uri = null;
        }
        return this->handler->handle(uri);
    }

    public function setHandler(object handler) -> <AppEngine>
    {
        if likely handler instanceof BaseApplication {
            let this->handler = handler;
        } else {
            throw new BaseException("Application must be instance of phalcon\\application");
        }
        return this;
    }

    public function handler() -> object
    {
        return this->handler;
    }

    // return object | null
    public function getHandler() -> object
    {
        if unlikely empty(this->handler) {
            throw new BaseException("Sorry, empty web handler");
        }
        return this->handler;
    }
}