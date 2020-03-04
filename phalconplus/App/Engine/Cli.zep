namespace PhalconPlus\App\Engine;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use Phalcon\Di\Injectable;
use Phalcon\CLI\Console as TaskHandler;
use Phalcon\Cli\Task;

class Cli extends Injectable implements AppEngine
{
    protected appModule = null;
    protected handler = null;

    public function __construct(<AppModule> appModule, <BaseApplication> handler = null)
    {
        let this->appModule = appModule;

        var di = appModule->getDI();
        this->setDI(di);
        
        if is_null(handler) {
            let this->handler = new TaskHandler();    
        } else {
            let this->handler = handler;
        }

        this->handler->setDI(di);
        this->handler->setEventsManager(di->get("eventsManager"));
    }
    
    public function exec(array argv, <\Phalcon\DI\FactoryDefault> di = null) -> <AppEngine> | <Task>
    {
        // 如果不需要handle，则直接返回
        // if !this->appModule->isAuto() { return this; }
        // Handle
        return this->handler->handle(argv);
    }

    public function setHandler(object handler) -> <AppEngine>
    {
        if likely handler instanceof BaseApplication {
            let this->handler = handler;
        } else {
            throw new BaseException("Handler must be instance of phalcon\\appliction");
        }
        return this;
    }

    public function handler() -> object
    {
        return this->handler;
    }

    // return object | null
    public function getHandler() -> object
    {
        if unlikely empty(this->handler) {
            throw new BaseException("Sorry, empty handler");
        }
        return this->handler;
    }
}