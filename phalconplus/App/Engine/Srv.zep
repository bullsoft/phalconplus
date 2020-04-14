namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Module\AbstractModule as AppModule;

use PhalconPlus\Rpc\Server\AbstractServer;
use PhalconPlus\Rpc\Server\SimpleServer;
use PhalconPlus\Rpc\Yar as YarServerPlus;

use Phalcon\Di\Injectable;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Http\ResponseInterface as HttpResponse;
use Yar_Server;

class Srv extends Injectable implements AppEngine
{
    protected appModule = null;
    protected handler = null;

    public function __construct(<AppModule> appModule, <BaseApplication> handler = null)
    {
        let this->appModule = appModule;

        var di = appModule->di();
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

        var moduleConf = appModule->{"config"}();
        if moduleConf->application->handler == "yar" {
            let this->handler = new Yar_Server(backendSrv);
        } else {
            let this->handler = new YarServerPlus(di);
            this->handler->setServer(backendSrv);
            this->handler->setEventsManager(di->get("eventsManager"));
        }
    }
    
    public function exec() -> <HttpResponse>
    {
        ob_start();
        this->handler->handle();
        var content = ob_get_clean();
        var response = this->getDI()->get("response");
        response->setStatusCode(200, "OK");
        response->setContent(content);
        return response;
    }

    public function setHandler(object handler) -> <AppEngine>
    {
        if likely (handler instanceof BaseApplication) || (handler instanceof Yar_Server) {
            let this->handler = handler;
        } else {
            throw new BaseException("Application must be instance of phalcon\\appliction or yar_server");
        }
        
        return this;
    }
    
    public function handler() -> object
    {
        return this->handler;
    }

    public function getHandler() -> object
    {
        if unlikely empty(this->handler) {
            throw new BaseException("Sorry, empty handler");
        }
        return this->handler;
    }
}