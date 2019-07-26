namespace PhalconPlus\Rpc\Client;

abstract class AbstractClient
{
    abstract public function callByObject(array rawData);
}
