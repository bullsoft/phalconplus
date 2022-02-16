namespace PhalconPlus\Facades;

class Di extends AbstractFacade
{
    protected function getName() -> string
    {
        return "di";
    }

    protected function resolve(<\Phalcon\Di\Di> di) -> null | <\Phalcon\Di\Di>
    {
        return di;
    }
}