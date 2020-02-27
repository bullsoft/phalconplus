namespace PhalconPlus\App\Module;
use PhalconPlus\App\Module\ModuleDef;
use PhalconPlus\App\App as SuperApp;

abstract class AbstractModule
{
    // <SuperApp>
    protected app = null {
        get
    };
    // <\Phalcon\DI>
    protected di = null {
        get
    };
    // <ModuleDef>
    protected def = null {
        get
    };

    public function __construct(<SuperApp> app, <ModuleDef> def = null)
    {
        let this->app = app;
        let this->di  = app->getDI();
        let this->def = def;  // Module should have it's definition.
    }

    public function getConfig()
    {
        return this->def->getConfig();
    }

    public function isPrimary()
    {
        return this->def->getIsPrimary() === true; // Report is primary or not
    }

    public function getName()
    {
        return this->def->getName();
    }

    public function getBootstrap()
    {
        return this->app->getBootstrap();
    }

    public function __call(string method, array params = [])
    {
        return call_user_func_array(
            [this->def, method],
            params
        );
    }

    abstract public function registerAutoloaders();
    abstract public function registerServices();
    public function registerEvents()
    {
        // 
    }
}
