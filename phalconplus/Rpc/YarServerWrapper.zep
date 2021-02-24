namespace PhalconPlus\Rpc;

use Yar_Server;
use Phalcon\Di\DiInterface;
use Phalcon\Application\AbstractApplication;
use PhalconPlus\Rpc\Server\AbstractServer;
use PhalconPlus\Base\Exception as BaseException;

class YarServerWrapper extends AbstractYar
{
    protected yar = null;

    public function setServer(<AbstractServer> obj) -> <AbstractYar>
    {
        let this->yar = new Yar_Server(obj);
        this->registerModules([
            AbstractYar::NAME : obj
        ]);
        return this;
    }

    public function handle() -> bool
    {
        if this->yar == null {
            throw new BaseException("You need set a server before handler request");
        }
        return this->yar->handle();
    }
}