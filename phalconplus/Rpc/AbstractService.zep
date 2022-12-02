namespace PhalconPlus\Rpc;
use Phalcon\Di\DiInterface;
use PhalconPlus\Rpc\Server\AbstractServer;
use Phalcon\Application\AbstractApplication;

class AbstractService extends AbstractApplication
{
    // const NAME = "backendSrv";

    public function getServer() -> <AbstractServer>
    {
        return this->getModule(AbstractServer::NAME);
    }

    abstract public function setServer(<AbstractServer> obj) -> <AbstractService>;

    abstract public function handle() -> bool;
}
