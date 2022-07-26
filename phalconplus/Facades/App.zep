namespace PhalconPlus\Facades;
use Phalcon\Di\Di;

class App extends AbstractFacade
{
    protected function getName() -> string
    {
        return "superApp";
    }
}