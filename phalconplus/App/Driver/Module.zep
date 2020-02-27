namespace PhalconPlus\App\Driver;
use PhalconPlus\App\App as SuperApp;
use Phalcon\Di\Injectable;
use Phalcon\Application as BaseApplication;
use Phalcon\Mvc\Application as MvcHandler;
use Phalcon\Http\Response as HttpResponse;

class Module extends Injectable implements AppDriver
{
    protected app;
    protected handler;
    protected autoHandle = true;

    public function __construct(<SuperApp> app, boolean autoHandle = true)
    {
        let this->autoHandle = autoHandle;
        let this->app = app;

        var di = app->getDI();

        this->setDI(di);
        let this->handler = new MvcHandler();
        this->handler->setDI(di);
        this->handler->setEventsManager(di->get("eventsManager"));
    }

    /**
    * @request a uri string (for \Phalcon\Mvc\Application) or Psr\Http\Message\Request
    */
    public function exec(var request = null) -> <HttpResponse> | <AppDriver>
    {
        // 如果不需要handle，则直接返回
        if !this->autoHandle { return this; }
        // Handle
        return this->handler->handle(request);
    }

    public function setHandler(object handler, boolean autoHandle = false) -> <AppDriver>
    {
        if likely handler instanceof BaseApplication {
            let this->handler = handler;
            let this->autoHandle = autoHandle;
        } else {
            throw new BaseException("Application must be instance of phalcon\\appliction");
        }
        return this;
    }

    // return object | null
    public function getHandler() -> object
    {
        if unlikely empty(this->handler) {
            throw new BaseException("Sorry, empty handler");
        }
        return this->handler;
    }
}