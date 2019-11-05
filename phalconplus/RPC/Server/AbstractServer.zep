namespace PhalconPlus\Rpc\Server;
use PhalconPlus\Base\ProtoBuffer;
use PhalconPlus\Logger\Processor\LogId;

abstract class AbstractServer
{
    protected di = null {
        get
    };

    protected phpOnly = false {
        get
    };

    protected eventsManager = null;

    abstract public function __construct(<\Phalcon\DI> di);

    protected function callByParams(string! service, string! method, request)
    {
        var serviceClass = "";
        let serviceClass = service->upperfirst() . "Service";

        if is_object(request) && request instanceof ProtoBuffer {
            let this->phpOnly = true;
        } elseif is_array(request) {
            var tmp = [], param, paramClass;
            let tmp = request;
            let param = new \ReflectionParameter([serviceClass, method], 0);
            if param->getClass() {
                let paramClass = param->getClass()->getName();
                let request = new {paramClass}();
                request->softClone(tmp);
            } else {
                throw new \PhalconPlus\Base\Exception("Service class:method definition is invalid. Detail: " . service . " : " . method . ". Request: " . json_encode(request));
            }
        } else {
            throw new \PhalconPlus\Base\Exception("Your input is not allowed. Request: " . json_encode(request));
        }

        var serviceObj, response, e;
        let serviceObj = new {serviceClass}(this->di);

        if is_callable([serviceObj, method]) {
            this->eventsManager->fire("backend-server:beforeExecute", $this, [service, method, request]);
            try {
                let response = <ProtoBuffer> call_user_func_array([serviceObj, method], [request]);
            } catch \Exception, e {
                throw e;
            }
            this->eventsManager->fire("backend-server:afterExecute", $this, [service, method, request]);
            // We do not allow to return #Resource type. And if an object returned, we expected type <ProtoBuffer>
            if is_object(response) && !(response instanceof ProtoBuffer) {
                throw new \PhalconPlus\Base\Exception("Your output is not allowed. Response: " . get_class(response) . ". We expect scalar type or <ProtoBuffer>");
            } elseif is_resource(response) {
                throw new \PhalconPlus\Base\Exception("Your output is not allowed. Response: #Resource.");
            }
            // Distinguish object/scalar types when there are non-php clients
            if this->phpOnly == false && is_object(response) {
                return response->toArray();
            }
            return response;
        } else {
            throw new \PhalconPlus\Base\Exception("Service:method not found. Detail: " . service . " : " . method);
        }
    }

    /**
     *
     * @param array rawData
     * <code>
     *     rawData = ["service":"Demo", "method":"demo", "args": <ProtoBuffer>, "logId": "234fdfaf3334"]
     * </code>
     * @return <ProtoBuffer>
     * @throw \Exception
     *
     */
    public function callByObject(array rawData)
    {
        var service, method, request, response, logId = "", message = "";

        if !fetch service, rawData["service"] {
            throw new \PhalconPlus\Base\Exception("service " . service . " not exists");
        }

        if !fetch method, rawData["method"] {
            throw new \PhalconPlus\Base\Exception("method " . method . " not exists");
        }

        if !fetch request, rawData["args"] {
            throw new \PhalconPlus\Base\Exception("args not exists");
        }

        this->eventsManager->fire("backend-server:requestCheck", $this, [service, method, rawData]);

        let service = trim(service);
        let method = trim(method);

        if empty service || empty method {
            throw new \PhalconPlus\Base\Exception("service:method(args) must exists. All of them!!!");
        }

        if fetch logId, rawData["logId"] {
            // set logId, same as request api
            LogId::setId(logId);
        }

        if this->di->has("logger") {
            let message = "RPC Request - logId: " . logId . ", invoke: " . service . "::" . method . ", args: " . json_encode(request);           
            this->di->get("logger")->log(message);
        }

        this->eventsManager->fire("backend-server:beforeDispatch", $this, [service, method, request]);
        let response = this->callByParams(service, method, request);
        this->eventsManager->fire("backend-server:afterDispatch", $this, [service, method, request, response]);

        if this->di->has("logger") {
            let message = "RPC Response - logId: " . logId . ", invoke: " . service . "::" . method . ", response: " . json_encode(response);
            this->di->get("logger")->log(message);
        }

        return response;
    }
}
