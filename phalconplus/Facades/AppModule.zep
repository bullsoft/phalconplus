namespace PhalconPlus\Facades;
use Phalcon\Di\Di;

class AppModule extends AbstractFacade
{
    protected function getName() -> string
    {
        return "appModule";
    }
}