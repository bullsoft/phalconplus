namespace PhalconPlus\Facades;
use Phalcon\Di;

class User extends AbstractFacade
{
    protected function getName() -> string
    {
        return "user";
    }
}