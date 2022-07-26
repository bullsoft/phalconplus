namespace PhalconPlus\Facades;
use Phalcon\Di\Di as PhDi;

class Di extends AbstractFacade
{
    protected function getName() -> string
    {
        return "di";
    }

    protected function resolve(<PhDi> di) -> null | <PhDi>
    {
        return di;
    }
}