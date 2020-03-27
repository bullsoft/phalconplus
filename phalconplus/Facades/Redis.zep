namespace PhalconPlus\Facades;
use Phalcon\Di;

class Redis extends AbstractFacade
{
    protected function getName() -> string
    {
        return "redis";
    }
}