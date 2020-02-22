namespace PhalconPlus\Facades;

class Log extends AbstractFacade
{
    protected function getName() -> string
    {
        return "logger";
    }
}