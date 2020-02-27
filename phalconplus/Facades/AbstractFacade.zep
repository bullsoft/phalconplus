namespace PhalconPlus\Facades;
use Phalcon\Di;
use PhalconPlus\App\App as SuperApp;

abstract class AbstractFacade
{
    private static app = null;

    abstract protected function getName() -> string;
    protected function resolve(<Di> di) -> null | <Di>
    {
        return null;
    }

    public static function setApp(<SuperApp> app)
    {
        let self::app = app;
    }

    public static function __callStatic(string method, array params)
    {
        var di, name, facade, service;
        let di = self::app->getDI(),
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
            error_log("PHP Fatal:  Service can not be resovled: " . name);
            throw new \PhalconPlus\Base\Exception("Service can not be resovled: " . name);
        }
        return call_user_func_array(
            [service, method], 
            params
        );
    }
}