namespace PhalconPlus\App\Driver;

interface AppDriver
{
    public function getHandler() -> object;
    public function setHandler(object handler, boolean autoHandle = false) -> <AppDriver>;
}