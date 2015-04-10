namespace PhalconPlus\RPC\Client;

abstract class AbstractClient
{
    abstract public function callByObject(array rawData);
}
