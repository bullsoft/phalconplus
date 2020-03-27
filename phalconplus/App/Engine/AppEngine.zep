namespace PhalconPlus\App\Engine;

interface AppEngine
{
    public function getHandler() -> object;
    public function setHandler(object handler) -> <AppEngine>;
}