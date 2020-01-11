namespace PhalconPlus\Rpc\Server;
use PhalconPlus\Rpc\Server\AbstractServer;

class SimpleServer extends AbstractServer
{
    final public function __construct(<\Phalcon\DI> di)
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
