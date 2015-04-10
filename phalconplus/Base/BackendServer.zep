namespace PhalconPlus\Base;
use PhalconPlus\RPC\Server\AbstractServer;

class BackendServer extends AbstractServer
{
    public function __construct(<\Phalcon\DI> di)
    {
        let this->di = di;
        let this->config = di->get("config");
    }
}
