namespace PhalconPlus\App\Engine;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Di\Injectable;
use Phalcon\Di\DiInterface;
use Phalcon\Application\AbstractApplication as BaseApplication;
use Phalcon\Cli\Console as TaskHandler;
use Phalcon\Cli\Task;

class Cli extends AbstractEngine
{
    public function __construct(<AppModule> appModule, <BaseApplication> handler = null)
    {
        if is_null(handler) {
            let handler = new TaskHandler();
        }
        parent::__construct(appModule, handler);
    }
    
    public function exec(array argv, <DiInterface> di = null) -> <Task>
    {
        return this->handler->handle(argv);
    }

}