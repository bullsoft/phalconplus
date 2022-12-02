namespace PhalconPlus\Rpc;
use Phalcon\Di\DiInterface;
use PhalconPlus\Rpc\Server\AbstractServer;
use Phalcon\Application\AbstractApplication;
use PhalconPlus\Enum\Sys as Sys;
use PhalconPlus\Enum\RunMode;
use PhalconPlus\Base\Exception as BaseException;

class SimpleService extends AbstractService
{
    protected formater = "msgpack";
    protected encoder  = "msgpack_pack";

    public function __construct(<DiInterface> di = null, string formater = "json")
    {
        parent::__construct(di);
        if "json" == formater {
            let this->formater = formater;
            let this->encoder = "json_encode";
        }
    }

    public function setServer(<AbstractServer> obj) -> <AbstractService>
    {
        this->registerModules([
            AbstractServer::NAME : obj
        ]);
        return this;
    }

    public function handle() -> bool
    {
        var serviceObj = this->getServer();
        if empty serviceObj {
            throw new BaseException("You need set a server before handler request");
        }

        var serviceName = get_class(serviceObj);
        var config = this->container->get("config");
        var responseBody = "Not supported http method.";

        if this->__get("request")->isGet() {
            let responseBody = this->defaultResponse([
                "ns" : config->application->ns,
                "serviceName" : serviceName,
                "originalMode" : config->application->mode
            ]);
            echo responseBody;
        } elseif this->__get("request")->isPost() {
            var e = null, ret, rawRequestBody, requestArgs;

            let rawRequestBody = this->__get("request")->getRawBody();
            if this->formater == "json" {
                let requestArgs = json_decode(rawRequestBody, true);
            } else {
                let requestArgs = msgpack_unpack(rawRequestBody);
            }
            let ret = [
                "errorCode" : 0,
                "errorMsg" : "",
                "data" : []
            ];
            try {
                if empty requestArgs {
                    throw new BaseException("invalid request args");
                }
                let ret["data"] = serviceObj->callByObject(requestArgs);
            } catch \Exception, e {
                let ret["errorCode"] = max(e->getCode(), 1);
                let ret["errorMsg"] = e->getMessage();
            }
            // Must do this after `callByObject`
            let ret["logId"] = this->__get("logger")->logId;

            string encoder = this->encoder;
            let responseBody = {encoder}(ret);
            echo responseBody;
        } else {
            echo responseBody;
            return false;
        }
        return true;
    }

    private function defaultResponse(array! vals = []) -> string
    {
        var sampleCodes, expectedRet, host;
        let host = _SERVER["HTTP_HOST"];
        if vals["originalMode"] == RunMode::WEB {
            let host = host . "/rpc.php";
        }
        let sampleCodes = "
<?php
$remoteUrls = [
    \"http://".host."\",
];
$client = new PhalconPlus\Rpc\Client\Adapter\Curl($remoteUrls);
$result = $client->callByObject([
    \"service\" => \"". vals["ns"] ."Services\Demo\",
    \"method\" => \"main\",
    \"args\"   => [
        \"foo\" => \"bar\",
    ],
]);
var_export($result);
";
        let expectedRet = "<?php
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
        return "<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />
  <title>" . vals["serviceName"] . " - Phalcon+ Server</title>
  <style type=\"text/css\">
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
  <script type=\"text/javascript\">
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
    <h1>Phalcon+ Server: " . vals["serviceName"] . "</h1>
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
    }


}