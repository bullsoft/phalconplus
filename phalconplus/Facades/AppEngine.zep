namespace PhalconPlus\Facades;
use Phalcon\Di;

class AppEngine extends AbstractFacade
{
    protected function getName() -> string
    {
        return "appEngine";
    }
}