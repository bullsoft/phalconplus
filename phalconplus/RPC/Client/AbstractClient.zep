namespace PhalconPlus\Rpc\Client;

abstract class AbstractClient
{
    protected namePrefix = "";
	protected di = null;
	
    public function setNamePrefix(string prefix)
	{
		 let this->namePrefix = trim(prefix);
		 return this;
	}

	public function setDi(<\Phalcon\DI> di) -> <AbstractClient>
	{
		let this->di = di;
		return this;
	}
	
    abstract public function callByObject(array rawData);
}