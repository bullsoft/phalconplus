namespace PhalconPlus\App\Module;
use PhalconPlus\App\Module\ModuleDef;

abstract class AbstractModule
{
    // <\Phalcon\DI>
    protected di = null;

    // <ModuleDef>
    protected def = null;

    public function __construct(<\Phalcon\DI> di, <ModuleDef> def = null)
    {
        let this->di = di;
        let this->def = def; // Module should have it's definition.
    }

    public function getConfig()
    {
        return this->def->getConfig();
    }

    public function getDef() -> <\PhalconPlus\Base\ModuleDef>
    {
        return this->def;
    }

    public function getDI() -> <\Phalcon\Di>
    {
        return this->di;
    }

    public function isPrimary()
    {
        return this->def->getIsPrimary() == true; // Report is primary or not
    }

    public function getName()
    {
        return this->def->getName();
    }

    public function getBootstrap()
    {
        return this->def->getBootstrap();
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
