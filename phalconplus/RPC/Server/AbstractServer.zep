namespace PhalconPlus\RPC\Server;
use PhalconPlus\Base\ProtoBuffer;

abstract class AbstractServer
{
    protected di = null;
    protected config = null;
    protected phpOnly = false;

    abstract public function __construct(<\Phalcon\DI> di);

    protected function requestCheck(string! service, string! method, <ProtoBuffer> request)
    {
        var serviceReflection, methodReflection;
        let serviceReflection = new \ReflectionClass(service);
        let methodReflection = serviceReflection->getMethod(method);
        // @TODO: check request object
    }

    protected function callByParams(string! service, string! method, request)
    {
        var serviceClass = "";
        let serviceClass = service->upperfirst() . "Service";

        if request instanceof ProtoBuffer {
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
                throw new \Exception("Service class:method definition is invalid. Detail: " . service . " : " . method . ". Request: " . json_encode(request));
            }
        } else {
            throw new \Exception("Your input is not allowed. Request: " . json_encode(request));
        }

        this->requestCheck(serviceClass, method, request);

        var serviceObj, response, e;
        let serviceObj = new {serviceClass}(this->di);
        
        if is_callable([serviceObj, method]) {
            try {
                let response = <ProtoBuffer> call_user_func_array([serviceObj, method], [request]);
            } catch \Exception, e {
                throw e;
            }
            return this->phpOnly == true ? response : response->toArray();
        } else {
            throw new \Exception("Service:method not found. Detail: " . service . " : " . method);
        }
    }

    /**
     *
     * @param array rawData
     * <code> 
     *     rawData = ["service":"Demo", "method":"demo", "args": <ProtoBuffer>]
     * </code>
     * @return <ProtoBuffer>
     * @throw \Exception
     *
     */
    public function callByObject(array rawData)
    {
        var service, method, request;
        
        error_log("Remote callByObject: " . var_export(rawData, true));
        
        if !fetch service, rawData["service"] {
            throw new \Exception("service " . service . " not exists");
        }

        if !fetch method, rawData["method"] {
            throw new \Exception("method " . method . " not exists");
        }

        if !fetch request, rawData["args"] {
            throw new \Exception("args not exists");
        }

        let service = trim(service);
        let method = trim(method);

        if empty service || empty method {
            throw new \Exception("service:method(args) must exists. All of them!!!");
        }
        error_log("Invoke callByParams");
        return this->callByParams(service, method, request);
    }
}
