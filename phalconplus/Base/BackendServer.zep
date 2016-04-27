namespace PhalconPlus\Base;
use PhalconPlus\RPC\Server\AbstractServer;

final class BackendServer extends AbstractServer
{
    public function __construct(<\Phalcon\DI> di)
    {
        let this->di = di;
        let this->config = di->get("config");
        let this->eventsManager = di->getShared("eventsManager");
        if di->has("serviceListener") {
            di->get("serviceListener");
        }
    }
}
