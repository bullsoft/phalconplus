namespace PhalconPlus\Rpc\Server;
use PhalconPlus\Rpc\Server\AbstractServer;
use Phalcon\Di\Di;

class SimpleServer extends AbstractServer
{
    final public function __construct(<Di> di)
    {
        let this->di = di;
        let this->eventsManager = di->getShared("eventsManager");
        
        ob_start();
        this->onConstruct();
        ob_end_clean();
    }

    protected function onConstruct()
    {
        // ... hook
    }

    public function __get(string! property) 
    {
        if(this->di->has(property)) {
            return this->di->get(property);
        }
        return null;
    }
}
