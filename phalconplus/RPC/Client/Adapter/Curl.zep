namespace PhalconPlus\Rpc\Client\Adapter;
use PhalconPlus\Rpc\Client\AbstractClient;

use PhalconPlus\Curl\Curl as HttpClient;

class Curl extends AbstractClient
{
    private remoteServerUrl;
    private client;
    private response { get };

    public function __construct(array remoteServerUrl, array opts = [])
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
    }

    public function callByObject(array rawData)
    {
        let this->response = this->client->rawPost(this->remoteServerUrl, msgpack_pack(rawData));
        if is_object(this->response) {
            if(this->response->statusCode == 200) {
                return msgpack_unpack(this->response->body);
            }
            return this->response->statusText;
        }
    }
}