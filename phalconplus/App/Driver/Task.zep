namespace PhalconPlus\App\Driver;
use PhalconPlus\App\App as SuperApp;
use Phalcon\Di\Injectable;
use Phalcon\CLI\Console as TaskHandler;
use Phalcon\Cli\Task;

class Task extends Injectable implements AppDriver
{
    protected app;
    protected handler;
    protected autoHandle = true;

    public function __construct(<SuperApp> app, boolean autoHandle = true)
    {
        let this->autoHandle = autoHandle;
        let this->app = app;

        var di = app->getDI();
        this->setDI(di);
        
        let this->handler = new TaskHandler();
        this->handler->setDI(di);
        this->handler->setEventsManager(di->get("eventsManager"));
    }
    
    public function exec(array argv, <\Phalcon\DI\FactoryDefault> di = null) -> <AppDriver> | <Task>
    {
        // 如果不需要handle，则直接返回
        if !this->autoHandle { return this; }

        // Handle
        return this->handler->handle(argv);
    }

    public function setHandler(object handler, boolean autoHandle = false) -> <AppDriver>
    {
        if likely handler instanceof BaseApplication {
            let this->handler = handler;
            let this->autoHandle = autoHandle;
        } else {
            throw new BaseException("Handler must be instance of phalcon\\appliction");
        }
        return this;
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