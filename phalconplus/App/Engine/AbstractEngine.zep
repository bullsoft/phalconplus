namespace PhalconPlus\App\Engine;

use Phalcon\Di\Injectable;
use Phalcon\Application\AbstractApplication as BaseApplication;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use PhalconPlus\Base\Exception as BaseException;

class AbstractEngine extends Injectable
{
    protected appModule = null;
    protected handler = null;

    public function __construct(<AppModule> appModule, <BaseApplication> handler = null)
    {
        let this->appModule = appModule;
        var di = appModule->di();
        this->setDI(di);
        if handler != null {
            handler->setDI(di);
            handler->setEventsManager(di->get("eventsManager"));
            let this->handler = handler;
        }
    }

    public function handler() -> <BaseApplication>
    {
        return this->handler;
    }

    // return object | null
    public function getHandler() -> <BaseApplication>
    {
        if unlikely empty(this->handler) {
            throw new BaseException("Sorry, empty cli handler");
        }
        return this->handler;
    }

    public function setHandler(<BaseApplication> handler) -> <AbstractEngine>
    {
        let this->handler = handler;
        return this;
    }
}
