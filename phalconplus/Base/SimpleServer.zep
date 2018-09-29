namespace PhalconPlus\Base;
use PhalconPlus\RPC\Server\AbstractServer;

class SimpleServer extends AbstractServer
{
    final public function __construct(<\Phalcon\DI> di)
    {
        let this->di = di;
        let this->config = di->getShared("config");
        let this->eventsManager = di->getShared("eventsManager");
        ob_start();
        this->onConstruct();
        ob_end_clean();
    }

    protected function onConstruct()
    {
        // ... hook
    }
}
