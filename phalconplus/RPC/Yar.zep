namespace PhalconPlus\Rpc;
use Phalcon\DiInterface;
use PhalconPlus\Rpc\Server\AbstractServer;

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

	protected formater = "msgpack";
	protected encoder = "msgpack_pack";

	public function __construct(<DiInterface> di = null, string formater = "json")
	{
        parent::__construct(di);
		var rawBody = this->__get("request")->getRawBody();
		if "json" == formater {
			let this->formater = formater;
			let this->encoder = "json_encode";
			let this->requestArgs = json_decode(rawBody, true);
		} else {
			let this->requestArgs = msgpack_unpack(rawBody);
		}
	}

	public function setServer(<AbstractServer> obj)
	{
		let this->serviceObj = obj;
		return this;
	}

	public function handle()
	{
		var serviceName = get_class(this->serviceObj);
		var sampleCodes;
		let  sampleCodes = "<?php
$remoteUrls = [
	\"http://" . _SERVER["HTTP_HOST"] . "\",
];
$client = new \PhalconPlus\Rpc\Client\Adapter\Curl($remoteUrls);
$result = $client->callByObject([
	\"service\" => \"\\Demo\\Services\\Dummy\",
	\"method\" => \"demo\",
	\"args\"   => [
		\"foo\" => \"bar\",
	],
]);
var_export($result);
";
		var  expectedRet = "<?php
array (
	'errorCode' => 0,
	'errorMsg' => '',
	'logId' => 'da0abdea3483146cd8',
	'data' => array (
		'params' => array (
			'foo' => 'bar',
		),
	),
)
";
		if this->__get("request")->isGet() {
			let this->responseBody = "<!DOCTYPE html>
			<html>
			 <head>
			  <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />
			  <title>" . serviceName . " - Phalcon+ Server</title>
			  <style>
			   body { margin: 0; font:14px/20px Verdana, Arial, sans-serif; color: #333; background: #f8f8f8;}
			   h1, h2, pre { margin: 0; padding: 0;}
			   h1 { font:bold 28px Verdana,Arial; background:#99c; padding: 12px 5px; border-bottom: 4px solid #669; box-shadow: 0 1px 4px #bbb; color: #222;}
			   h2 { font:normal 20px/22px Georgia, Times, \"Times New Roman\", serif; padding: 5px 0 8px; margin: 20px 10px 0; border-bottom: 1px solid #ddd; cursor:pointer;}
			   p, dd { color: #555; }
			   .api-info { padding: 10px 0; margin-left: 20px; }
			   .api-block, .sample-codes { margin: 0 40px;}
			   .code {border: 1px solid #669; padding: 10px;}
			   h2 u { font-size:20px;text-decoration:none;padding:10px; }
			  </style>
			  <script>
			   function _t(elem) {
				var block = elem.nextSibling;
				var info = elem.getElementsByTagName('u')[0];
				while (block) {
				 if ( block.nodeType == 1 && block.className.indexOf('api-block') > -1 ) {
				  break;
				 }
				 block = block.nextSibling;
				}
				var isHidden = block.style.display == 'none';
				block.style.display = isHidden ? '' : 'none';
				info.innerHTML = isHidden ? '-'  : '+';
			   }
			  </script>
			 </head>
			 <body>
				<h1>Phalcon+ Server: " . serviceName . "</h1>
				<h2>Code Samples: </h2>
				<div class=\"sample-codes\">
				<p class=\"code\">" . str_replace("&lt;?php", "// Client", highlight_string(sampleCodes, true)) . "</p>
				<p><center style=\"font-weight: bolder;\">-------------- Expected Result --------------</center></p>
				<p class=\"code\">" . str_replace("&lt;?php", "// Return", highlight_string(expectedRet, true)) . "</p>
				</div>
				<footer>
				    <center>Copyright &copy <a href=\"https://bullsoft.org\">BullSoft.org</a></center>
				</footer>
			 </body>
		    </html>";
		} elseif this->__get("request")->isPost() {
            var e = null;
			var ret = [
				"errorCode" : 0,
				"errorMsg" : "",
				"data" : []
			];
			try {
                if empty this->requestArgs {
                    throw new \Exception("invalid request args");
				}
				if empty this->serviceObj {
					let this->serviceObj = this->getDi()->get("backendSrv");
				}
				let ret["data"] = this->serviceObj->callByObject(this->requestArgs);
			} catch \Exception, e {
				let ret["errorCode"] = max(e->getCode(), 1);
				let ret["errorMsg"] = e->getMessage();
			}
			// Must do this after `callByObject`
			let ret["logId"] = this->__get("logger")->logId;

			string encoder = this->encoder;
			let this->responseBody = {encoder}(ret);
		}
		echo this->responseBody;
	}
}