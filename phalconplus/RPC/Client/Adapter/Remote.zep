namespace PhalconPlus\RPC\Client\Adapter;
use PhalconPlus\RPC\Client\AbstractClient;

class Remote extends AbstractClient
{
    private remoteServerUrl;
    private client;

    public function __construct(array remoteServerUrl, array opts = [])
    {
        if empty remoteServerUrl {
            throw new \PhalconPlus\Base\Exception("server url can not be empty");
        }
        var key;
        let key = array_rand(remoteServerUrl);
        let this->remoteServerUrl = remoteServerUrl[key];
        let this->client = new \Yar_Client(this->remoteServerUrl);

        if !empty opts {
            var optKey, optVal;
            for optKey, optVal in opts {
                this->client->setOpt(optKey, optVal);
            }
        }
    }

    public function callByObject(array rawData)
    {
        return this->client->callByObject(rawData);
    }

    public function __call(string! method, array args)
    {
        if method_exists(this->client, method) {
            // error_log("Remote RPC set Opts: " . method . " args: " . var_export(args, true));
            return call_user_func_array([this->client, method], args);
        } else {
            throw new \PhalconPlus\Base\Exception("method not exists");
        }
    }

}
