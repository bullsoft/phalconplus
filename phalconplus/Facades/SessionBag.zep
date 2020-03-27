namespace PhalconPlus\Facades;

class SessionBag extends AbstractFacade
{
    protected function getName() -> string
    {
        return "sessionBag";
    }
}