namespace PhalconPlus\Facades;
use Phalcon\Di\Di;

class User extends AbstractFacade
{
    protected function getName() -> string
    {
        return "user";
    }
}