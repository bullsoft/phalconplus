namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Module\AbstractModule as AppModule;

use PhalconPlus\Rpc\Server\AbstractServer;
use PhalconPlus\Rpc\Server\SimpleServer;
use PhalconPlus\Rpc\SimpleService;
use PhalconPlus\Rpc\YarService;
use PhalconPlus\Rpc\AbstractService;
use Phalcon\Application\AbstractApplication as BaseApplication;

use Phalcon\Di\DiInterface;
use Phalcon\Di\Injectable;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Http\ResponseInterface as HttpResponse;

class Srv extends AbstractEngine
{
    public function __construct(<AppModule> appModule, <BaseApplication> handler = null)
    {
        var di = appModule->di();
        var moduleConf = appModule->{"config"}();

        if is_null(handler) {
            if moduleConf->application->handler == "yar" {
                let handler = new YarService();
            } else {
                let handler = new SimpleService();
            }
        }
        var backendSrv = this->newServer(di);
        handler->setServer(backendSrv);
        parent::__construct(appModule, handler);
    }

    private function newServer(<DiInterface> di) -> <AbstractServer>
    {
        // Backend Server, Default is SimpleServer
        var backendSrv;
        if unlikely di->has(AbstractServer::NAME) {
            let backendSrv = di->get(AbstractServer::NAME);
            if ! (backendSrv instanceof AbstractServer) {
                throw new BaseException("Server object(DI[\"backendSrv\"]) must be type of PhalconPlus\\Rpc\\Server\\AbstractServer");
            }
        } else {
            let backendSrv = new SimpleServer(di);
            di->setShared(AbstractServer::NAME, backendSrv);
        }
        return backendSrv;
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
}