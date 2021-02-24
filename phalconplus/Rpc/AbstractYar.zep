namespace PhalconPlus\Rpc;
use Phalcon\Di\DiInterface;
use PhalconPlus\Rpc\Server\AbstractServer;
use Phalcon\Application\AbstractApplication;

class AbstractYar extends AbstractApplication
{
    const NAME = "backendSrv";

    public function getServer() -> <AbstractServer>
    {
        return this->getModule(AbstractYar::NAME);
    }

    abstract public function setServer(<AbstractServer> obj) -> <AbstractYar>;

    abstract public function handle() -> bool;
}
