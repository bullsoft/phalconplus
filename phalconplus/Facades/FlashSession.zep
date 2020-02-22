namespace PhalconPlus\Facades;

class FlashSession extends AbstractFacade
{
    protected function getName() -> string
    {
        return "flashSession";
    }
}