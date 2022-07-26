namespace PhalconPlus\Rpc\Server;
use PhalconPlus\Base\ProtoBuffer;
use PhalconPlus\Logger\Processor\LogId;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Di\Di;

abstract class AbstractServer
{
    protected di = null { get };
    protected phpOnly = false { get };
    protected eventsManager = null;

    abstract public function __construct(<Di> di);

    protected function callByParams(string! service, string! method, request = null)
    {
        var serviceClass = "", methodReflection, 
            serviceObj, response, e;
		
        let serviceClass = service->upperfirst() . "Service";
        if !class_exists(serviceClass) {
            throw new BaseException("Service class not exists: " . serviceClass);
        }
        // Instance Server Object
        let serviceObj = new {serviceClass}(this->di);
        try {
            let methodReflection = new \ReflectionMethod(serviceObj, method);
        } catch \ReflectionException, e {
            throw new BaseException("Service:method not found. Detail: " . serviceClass . " : " . method . ". RawException: ". e->getMessage());
        }
		if request == null && methodReflection->getNumberOfRequiredParameters() > 0 {
            throw new BaseException(service."::".method." need required params");
        }

        if methodReflection->getNumberOfParameters() > 0 {
    		// ...
            if is_object(request) && request instanceof ProtoBuffer {
                let this->phpOnly = true;
            } elseif is_array(request) {
                var tmp = request, param, paramClass;
                // We just care the first parameter, and ignore others
                let param = new \ReflectionParameter([serviceClass, method], 0);
                if param->getClass() {
                    let paramClass = param->getClass()->getName();
                    let request = new {paramClass}();
                    request->softClone(tmp);
                } else {
                    throw new BaseException("Service class:method definition is invalid. Detail: " . service . " : " . method . ". Request: " . json_encode(request));
                }
            } elseif is_null(request) {
                // Now "null" for optional param is allowed
            } else {
                throw new BaseException("Your args is not allowed. Request: " . json_encode(request));
            }
    		// ...	
        }
        // Fire Event "beforeExecute"
        this->eventsManager->fire("backend-server:beforeExecute", $this, [service, method, request]);
        // Invoke target method
        try {
            // We expected type <ProtoBase>
            let response = methodReflection->invokeArgs(serviceObj, [request]);
        } catch \Exception, e {
            throw new BaseException(e->getMessage());
        }
        // Fire Event "afterExecute"
        this->eventsManager->fire("backend-server:afterExecute", $this, [service, method, request]);
        
        // We do not allow to return #Resource type. And if an object returned, we expected type <ProtoBuffer>
        if is_object(response) && !(response instanceof ProtoBuffer) {
            throw new BaseException("Your output is not allowed. Response: " . get_class(response) . ". We expect scalar type or <ProtoBuffer>");
        } elseif is_resource(response) {
            throw new BaseException("Your output is not allowed. Response: #Resource.");
        }
        
        // Distinguish object/scalar types when there are non-php clients
        if this->phpOnly == false && is_object(response) {
            return response->toArray();
        }
        return response;
    }

    /**
     *
     * @param array rawData
     * <code>
     *     rawData = ["service":"Demo", "method":"demo", "args": <ProtoBuffer>, "logId": "234fdfaf3334"]
     * </code>
     * @return <ProtoBuffer>
     * @throw <BaseException>
     *
     */
    public function callByObject(array rawData)
    {
        var service, method, request, response, 
            logId = "", message = "";

        if !fetch service, rawData["service"] {
            throw new BaseException("service " . service . " not exists");
        }
        if !fetch method, rawData["method"] {
            throw new BaseException("method " . method . " not exists");
        }
        if !fetch request, rawData["args"] {
            // throw new BaseException("args not exists");
            let request = null;
        }

        this->eventsManager->fire("backend-server:requestCheck", $this, [service, method, rawData]);

        let service = trim(service), method = trim(method);
        if empty service || empty method {
            throw new BaseException("service:method(args) must exists. All of them!!!");
        }

        // set logId, same as request api
        if fetch logId, rawData["logId"] {
            LogId::setId(logId);
        }

        if this->di->has("logger") {
            let message = "RPC Request - logId: " . logId . ", invoke: " . service . "::" . method . ", args: " . json_encode(request);           
            this->di->get("logger")->info(message);
        }

        this->eventsManager->fire("backend-server:beforeDispatch", $this, [service, method, request]);
		
        let response = this->callByParams(service, method, request);
		
        this->eventsManager->fire("backend-server:afterDispatch", $this, [service, method, request, response]);

        if this->di->has("logger") {
            let message = "RPC Response - logId: " . logId . ", invoke: " . service . "::" . method . ", response: " . json_encode(response);
            this->di->get("logger")->info(message);
        }
        return response;
    }
}
