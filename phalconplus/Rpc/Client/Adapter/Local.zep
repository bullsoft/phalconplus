namespace PhalconPlus\Rpc\Client\Adapter;
use PhalconPlus\Rpc\Client\AbstractClient;
use PhalconPlus\Base\ProtoBuffer;
use PhalconPlus\Base\Exception as BaseException;

class Local extends AbstractClient
{
    public function __construct(<\Phalcon\DI> di)
    {
        this->setDI(di);
    }

    private function callByParams(string! service, string! method, request)
    {
        var serviceObj = null, 
            methodReflection = null,
            serviceClass = "",
            message = "";

        let serviceClass  = service->upperfirst() . "Service";
        if !class_exists(serviceClass) {
            throw new BaseException("Service class not exists: " . serviceClass);
        }
        let serviceObj = new {serviceClass}(this->di);

        var e;
        try {
            let methodReflection = new \ReflectionMethod(serviceObj, method);
        } catch \ReflectionException, e {
            throw new BaseException("Service:method not found. Detail: " . serviceClass . " : " . method . ". RawException: ". e->getMessage());
        }

		if request == null && methodReflection->getNumberOfRequiredParameters() > 0 {
            throw new BaseException(service."::".method." need required params");
        }

        if this->di->has("logger") {
            let message = "LocalRpc> dispatch to '" .serviceClass. "::". method . "(request)' where request is: " . var_export(request, true);
            this->di->get("logger")->debug(message);
        }

        if methodReflection->getNumberOfParameters() > 0 {
            // If get an object, must be instance of <ProtoBuffer> or it's subclasses
            if is_object(request) && (request instanceof ProtoBuffer) {
                let this->phpOnly = true; // make no sense
            } elseif is_array(request) {
                var tmp = request, 
                    param = null, 
                    paramClass = "";
                let param = new \ReflectionParameter([serviceClass, method], 0);
                if param->getClass() {
                    let paramClass = param->getClass()->getName();
                    let request = new {paramClass}();
                    request->softClone(tmp);
                } else {
                    throw new BaseException("Service class:method definition is invalid. Detail: " . service . " : " . method . ". Request: " . json_encode(request));
                }
            } elseif null == request {
                // nothing here...
            } else {
                throw new BaseException("No service found: " . serviceClass . "::" . method);
            }
        }

        if this->di->has("logger") {
            let message = "LocalRpc> finally requst transformed to: ". var_export(request, true);
            this->di->get("logger")->debug(message);
        }
        
        var response;
        // Invoke target method
        try {
            // We expected type <ProtoBase>
            let response = methodReflection->invokeArgs(serviceObj, [request]);
        } catch \Exception, e {
            throw new BaseException(e->getMessage());
        }
        // We do not allow to return #Resource type. And if an object returned, we expected type <ProtoBuffer>
        if is_object(response) && !(response instanceof ProtoBuffer) {
            throw new BaseException("Your output is not allowed. Response: " . get_class(response) . ". We expect scalar type or <ProtoBuffer>");
        } elseif is_resource(response) {
            throw new BaseException("Your output is not allowed. Response: #Resource.");
        }
        return response;
    }

    public function callByObject(array rawData)
    {
        var service, method, request, message;

        if this->di->has("logger") {
            let message = "LocalRpc> callByObject: " . var_export(rawData, true);
            this->di->get("logger")->debug(message);
        }

        if !fetch service, rawData["service"] {
            throw new BaseException("service " . service . " not exists");
        }
        if !fetch method, rawData["method"] {
            throw new BaseException("method " . method . " not exists");
        }
        if !fetch request, rawData["args"] {
            let request = null;
        }

        let service = this->namePrefix . trim(service);

        let method = trim(method);

        if empty service || empty method {
            throw new BaseException("service:method(args) must exists. All of them!!!");
        }

        if this->di->has("logger") {
            let message = "LocalRpc> callByParams with (" . service . ", " . method . ")";
            this->di->get("logger")->debug(message);
        }
		
        return this->callByParams(service, method, request);
    }
}

