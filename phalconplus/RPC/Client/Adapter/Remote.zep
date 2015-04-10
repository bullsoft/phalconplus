namespace PhalconPlus\RPC\Client\Adapter;
use PhalconPlus\RPC\Client\AbstractClient;

class Remote extends AbstractClient
{
    private remoteServerUrl;
    private client;
    
    public function __construct(array remoteServerUrl)
    {
        if empty remoteServerUrl {
            throw new \Exception("server url can not be empty");
        }
        var key;
        let key = array_rand(remoteServerUrl);
        let this->remoteServerUrl = remoteServerUrl[key];
        let this->client = new \Yar_Client(this->remoteServerUrl);
    }

    public function callByObject(array rawData)
    {
        return this->client->callByObject(rawData);
    }

}
