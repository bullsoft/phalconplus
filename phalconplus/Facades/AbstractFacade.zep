namespace PhalconPlus\Facades;

abstract class AbstractFacade
{
    abstract protected function getName() -> string;

    public static function __callStatic(string method, array params)
    {
        var di, name, facade, service;
        let di = \Phalcon\Di::getDefault(),
            name = get_called_class(),
            facade = new {name}(),
            service = di->get(facade->getName());
        return call_user_func_array([service, method], params);
    }
}