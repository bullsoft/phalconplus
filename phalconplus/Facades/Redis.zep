namespace PhalconPlus\Facades;

class Redis extends AbstractFacade
{
    protected function getName() -> string
    {
        return "redis";
    }
}