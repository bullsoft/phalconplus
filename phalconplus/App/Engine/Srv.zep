namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Module\AbstractModule as AppModule;

use PhalconPlus\Rpc\Server\AbstractServer;
use PhalconPlus\Rpc\Server\SimpleServer;
use PhalconPlus\Rpc\Yar as YarServerPlus;
use PhalconPlus\Rpc\YarServerWrapper;
use PhalconPlus\Rpc\AbstractYar;
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
                let handler = new YarServerWrapper();
            } else {
                let handler = new YarServerPlus();
            }
        }
        var backendSrv = this->newService(di);
        handler->setServer(backendSrv);
        parent::__construct(appModule, handler);
    }

    private function newService(<DiInterface> di) -> <AbstractServer>
    {
        // Backend Server, Default is SimpleServer
        var backendSrv;
        if unlikely di->has(AbstractYar::NAME) {
            let backendSrv = di->get(AbstractYar::NAME);
            if ! (backendSrv instanceof AbstractServer) {
                throw new BaseException("Service object(DI[\"backendSrv\"]) must be type of PhalconPlus\\Rpc\\Server\\AbstractServer");
            }
        } else {
            let backendSrv = new SimpleServer(di);
            di->setShared(AbstractYar::NAME, backendSrv);
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