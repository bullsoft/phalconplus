namespace PhalconPlus\Rpc\Client\Adapter;
use PhalconPlus\Rpc\Client\AbstractClient;

use PhalconPlus\Curl\Curl as HttpClient;

class Curl extends AbstractClient
{
    private remoteServerUrl;
    private client;
    private response { get };
    private formater = "msgpack";

    public function __construct(array remoteServerUrl, array opts = [], string formater = "")
    {
        if empty remoteServerUrl {
            throw new \PhalconPlus\Base\Exception("server url can not be empty");
        }
        var key;
        let key = array_rand(remoteServerUrl);
        let this->remoteServerUrl = remoteServerUrl[key];
        let this->client = new HttpClient();
        if !empty opts {
            this->client->setDefaultOptions(opts);
        }
        if "json" == formater {
            let this->formater = formater;
        }
    }

    public function callByObject(array rawData)
    {
        string encoder = "msgpack_pack", 
               decoder = "msgpack_unpack";
        if "json" == this->formater {
            let encoder = "json_encode",
                decoder = "json_decode";
        }
        let this->response = this->client->rawPost(this->remoteServerUrl, {encoder}(rawData));
        if is_object(this->response) {
            if(this->response->statusCode == 200) {
                if "json" == this->formater { 
                    return {decoder}(this->response->body, true);
                } else {
                    return {decoder}(this->response->body);
                }
            }
            return this->response->statusText;
        }
    }
}