namespace PhalconPlus\Rpc\Client\Adapter;
use PhalconPlus\Rpc\Client\AbstractClient;
use PhalconPlus\Base\Exception as BaseException;
use PhalconPlus\Base\ProtoBuffer;

class Yar extends AbstractClient
{
    private remoteServerUrl = "";
    private client = null;

    public function __construct(array remoteServerUrl, array opts = [])
    {
        if empty remoteServerUrl {
            throw new BaseException("server url can not be empty");
        }
        var key = array_rand(remoteServerUrl);
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
        let rawData["service"] = this->namePrefix . rawData["service"];
        var message = "", rsp = null, e = null;
        if isset(this->di) && this->di->has("logger") {
            let message = "RemoteRpc> callByObject: ". var_export(rawData, true);
            this->di->get("logger")->debug(message);
        }
        let rsp = new ProtoBuffer();
        let rsp->logId = this->di->get("logger")->logId;
        try {
            let rsp->results = this->client->callByObject(rawData);
            let rsp->status = "success";
            let rsp->code = 0;
            let rsp->message = "";
        } catch \Exception, e {
            let rsp->results = null;
            let rsp->status = "fail";
            let rsp->code = max(e->getCode(), 1);
            let rsp->message = e->getMessage();
        }
        return rsp;
    }

    public function __call(string! method, array args)
    {
        if method_exists(this->client, method) {
            return call_user_func_array([this->client, method], args);
        } else {
            throw new BaseException("Yar_Client: method(".method.") not exists");
        }
    }

}
