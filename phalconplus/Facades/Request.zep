namespace PhalconPlus\Facades;

class Request extends AbstractFacade
{
    protected function getName() -> string
    {
        return "request";
    }
}