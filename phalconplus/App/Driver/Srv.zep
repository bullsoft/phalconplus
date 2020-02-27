namespace PhalconPlus\App\Driver;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Rpc\Server\AbstractServer;
use PhalconPlus\Rpc\Server\SimpleServer;
use Phalcon\Di\Injectable;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Http\Response as HttpResponse;
use Yar_Server;

class Srv extends Injectable implements AppDriver
{
    protected app;
    protected handler;
    protected autoHandle = true;

    public function __construct(<SuperApp> app, boolean autoHandle = true)
    {
        let this->autoHandle = autoHandle;
        let this->app = app;

        var di = this->app->getDI();
        this->setDI(di);

        var backendSrv = null;

        // Backend Server, Default is SimpleServer 
        if unlikely di->has("backendSrv") {
            let backendSrv = di->get("backendSrv");
            if ! (backendSrv instanceof AbstractServer) {
                throw new BaseException("Service object(DI[\"backendSrv\"]) must be type of \\PhalconPlus\\Rpc\\Server\\AbstractServer");
            }
        } else {
            let backendSrv = new SimpleServer(di);
            di->setShared("backendSrv", backendSrv);
        }

        var moduleConf = app->getPrimaryModuleDef()->getConfig();
        if moduleConf->application->handler == "yar" {
            let this->handler = new Yar_Server(backendSrv);
        } else {
            let this->handler = new YarServerPlus(di);
            this->handler->setServer(backendSrv);
            this->handler->setEventsManager(di->get("eventsManager"));
        }
    }
    
    public function exec() -> <HttpResponse> | <AppDriver>
    {
        // 如果不需要handle，则直接返回
        if !this->autoHandle { return this; }
        // Handle It
        ob_start();
        this->handler->handle();
        var content = ob_get_clean();
        var response = this->app->getDI()->get("response");
        // let response = new \Phalcon\Http\Response();
        response->setStatusCode(200, "OK");
        response->setContent(content);
        return response;
    }

    public function setHandler(object handler, boolean autoHandle = false) -> <AppDriver>
    {
        if likely (handler instanceof BaseApplication) || (handler instanceof Yar_Server) {
            let this->handler = handler;
            let this->autoHandle = autoHandle;
        } else {
            throw new BaseException("Application must be instance of phalcon\\appliction or yar_server");
        }
        
        return this;
    }

    public function getHandler() -> object
    {
        if unlikely empty(this->handler) {
            throw new BaseException("Sorry, empty handler");
        }
        return this->handler;
    }
}