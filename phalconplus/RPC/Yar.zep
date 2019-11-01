// <?php
namespace PhalconPlus\Rpc;
use Phalcon\DiInterface;

class Yar extends \Phalcon\Application
{
	protected serviceObj = null {
        get
    };
    protected requestArgs = "" {
        get
    };
    protected responseBody = "not supported http method" {
        get
    };

	public function __construct(<DiInterface> di = null)
	{
        parent::__construct(di);
		var rawBody = this->__get("request")->getRawBody();
		let this->requestArgs = msgpack_unpack(rawBody);
	}

	public function handle()// -> <\Phalcon\Http\Response>
	{
		if this->__get("request")->isGet() {
			let this->responseBody = "<h1>Welcome to Phalcon+</h1>
			<p>If you see this page, the msgpack-rpc server is successfully installed and
			working.</p>";
		} elseif this->__get("request")->isPost() {
            var e = null;
			var ret = [
				"errorCode" : 0,
				"errorMsg" : "",
				"logId" : this->__get("logger")->logId,
				"data" : []
			];
			try {
                if empty this->requestArgs {
                    throw new \Exception("invalid request args");
                }
				let this->serviceObj = this->getDi()->get("backendSrv");
				let ret["data"] = this->serviceObj->callByObject(this->requestArgs);
			} catch \Exception, e {
				let ret["errorCode"] = max(e->getCode(), 1);
				let ret["errorMsg"] = e->getMessage();
			}
			let this->responseBody = msgpack_pack(ret);
		}
		echo this->responseBody;
        // var response;
        // let response = new \Phalcon\Http\Response();
		// response->setStatusCode(200, "OK");
		// response->setContent(this->responseBody);
		// return response;
	}
}