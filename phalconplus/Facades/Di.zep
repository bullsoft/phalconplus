namespace PhalconPlus\Facades;

class Di extends AbstractFacade
{
    protected function getName() -> string
    {
        return "di";
    }

    protected function resolve(<\Phalcon\Di> di) -> null | <\Phalcon\Di>
    {
        return di;
    }
}