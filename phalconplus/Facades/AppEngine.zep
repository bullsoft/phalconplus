namespace PhalconPlus\Facades;
use Phalcon\Di\Di;

class AppEngine extends AbstractFacade
{
    protected function getName() -> string
    {
        return "appEngine";
    }

    public static function request(string controller, string action, array params, callback = null) -> string
    {
        var di = self::app()->di(),
            dispatcher = null, 
            view = di->get("view");

        let dispatcher = clone di->get("dispatcher");

        dispatcher->forward([
            "controller" : controller,
            "action"     : action,
            "params"     : params
        ]);

        dispatcher->dispatch();

        var ret = dispatcher->getReturnedValue();
        if !is_callable(callback) {
            let callback = function(view) {
                // ...
            };
        }
        var cont = view->getRender(
            dispatcher->getControllerName(),
            dispatcher->getActionName(),
            params,
            callback
        );
        if empty cont {
            if is_null(ret) || is_scalar(ret) {
                return strval(ret);
            } else {
                return json_encode(ret, JSON_UNESCAPED_UNICODE);
            }
        } else {
            return cont;
        }
    }
}