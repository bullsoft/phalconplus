namespace PhalconPlus\Rpc\Client;

abstract class AbstractClient
{
    protected namePrefix = "";
	
    public function setNamePrefix(string prefix)
	{
		 let this->namePrefix = trim(prefix);
		 return this;
	}
	
    abstract public function callByObject(array rawData);
}