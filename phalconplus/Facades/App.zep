namespace PhalconPlus\Facades;
use Phalcon\Di;

class App extends AbstractFacade
{
    protected function getName() -> string
    {
        return "application";
    }

    protected function resolve(<Di> di) -> null | <Di>
    {
        var boot = di->get("bootstrap");
        di->setShared(this->getName(), boot->getApp());
        return null;
    }
}