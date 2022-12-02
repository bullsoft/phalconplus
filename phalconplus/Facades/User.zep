namespace PhalconPlus\Facades;

class User extends AbstractFacade
{
    protected function getName() -> string
    {
        return "user";
    }
}