namespace PhalconPlus\App\Module;
use PhalconPlus\App\Module\ModuleDef;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Engine\AbstractEngine;
use Phalcon\Di\Injectable;
use PhalconPlus\Base\Exception as BaseException;
use PhalconPlus\Enum\RunMode;
use Phalcon\Events\ManagerInterface;
use Phalcon\Http\ResponseInterface as HttpResponse;
use Phalcon\Cli\Task as CliTask;
use Phalcon\Config\Config;
use Phalcon\Di\Di;

abstract class AbstractModule extends Injectable
{
    // <SuperApp>
    protected app = null { get };
    // <ModuleDef>
    protected def = null { get };
    // <AppEngine>
    protected engine = null { get };

    public function __construct(<SuperApp> app, <ModuleDef> def = null)
    {
        let this->app = app; // Hold SuperApp instance
        let this->def = def; // Module should have it's definition.
        let this->container = app->di();
    }

    public function isPrimary() -> boolean
    {
        return this->def->getIsPrimary() === true; // Report is primary or not
    }

    public function isCli() -> boolean
    {
        return this->def->getRunMode()->isCli();
    }

    public function isWeb() -> boolean
    {
        return this->def->getRunMode()->isWeb();
    }

    public function isSrv() -> boolean
    {
        return this->def->getRunMode()->isSrv();
    }

    public function isMicro() -> boolean
    {
        return this->def->getRunMode()->isMicro();
    }

    public function getName() -> string
    {
        return this->def->getName();
    }

    public function app() -> <SuperApp>
    {
        return this->app;
    }

    public function di() -> <Di>
    {
        return this->container;
    }

    public function def() -> <ModuleDef>
    {
        return this->def;
    }

    public function config() -> <Config>
    {
        return this->def->config();
    }

    public function engine() -> <AbstractEngine>
    {
        return this->engine;
    }

    public function __call(string method, array params = [])
    {
        return call_user_func_array(
            [this->def, method],
            params
        );
    }

    public function exec(array params = []) -> <HttpResponse> | <CliTask>
    {
        if !this->def->isPrimary() {
            throw new BaseException("Only primary module can be executed");
        }

        var eventsManager,
            engineClass,  
            engineName = this->def->getMapClassName();
        
        let eventsManager = <ManagerInterface> this->container->get("eventsManager");
        if typeof eventsManager == "object" {
            if eventsManager->fire("module:beforeStartEngine", this, [engineClass, params]) === false {
                // 
            }
        }

        if empty this->engine {
            this->registerEngine();
        }
        this->container->setShared("appEngine", this->engine);

        var ret = call_user_func_array(
            [this->engine, "exec"], 
            params
        );

        if typeof eventsManager == "object" {
            if eventsManager->fire("module:afterStartEngine", this, [engineClass, ret]) === false {
                // 
            }
        }

        return ret;
    }

    abstract public function registerAutoloaders();
    abstract public function registerServices();
    public function registerEvents()
    {
        // 
    }

    public function registerEngine() -> <AbstractModule>
    {
        if !this->def->isPrimary() {
            return this;
        }
        
        var engineClass,  
            engineName = this->def->getMapClassName();
        let engineClass = "PhalconPlus\\App\\Engine\\".engineName;

        let this->engine = new {engineClass}(this);

        return this;
    }
}
