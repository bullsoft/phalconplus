namespace PhalconPlus\Facades;

class Session extends AbstractFacade
{
    protected function getName() -> string
    {
        return "session";
    }
}