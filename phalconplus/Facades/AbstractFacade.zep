namespace PhalconPlus\Facades;
use Phalcon\Di;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Base\Exception as BaseException;

abstract class AbstractFacade
{
    private static app = null;

    abstract protected function getName() -> string;
    protected function resolve(<Di> di) -> null | <Di>
    {
        return null;
    }

    public static function setApp(<\PhalconPlus\App\App> app)
    {
        let self::app = app;
    }

    public static function app() -> <\PhalconPlus\App\App>
    {
        return self::app;
    }
		
    public static function getApp() -> <\PhalconPlus\App\App>
    {
        return self::app;
    }
	
	public static function itself()
	{
        var di, name, facade, service;
		
        let di = self::app->di(),
            name = get_called_class(),
            facade = new {name}();

        if di->has(facade->getName()) {
            let service = di->get(facade->getName());
        } else {
            let service = facade->resolve(di);
            if is_null(service) && di->has(facade->getName()) {
                let service = di->get(facade->getName());
            }
        }
		
        if is_null(service) {
            trigger_error("Service can not be resovled: " . name);
            throw new BaseException("Service can not be resovled: " . name);
        }
        
		return service;
	}

    public static function __callStatic(string method, array params)
    {
        var service = static::itself();
		
        return call_user_func_array(
            [service, method], 
            params
        );
    }
}