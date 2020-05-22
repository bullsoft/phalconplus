namespace PhalconPlus\Mvc;
use Phalcon\Mvc\Application as BaseApplication;
use Psr\Http\Message\ServerRequestInterface;
use Phalcon\Http\ResponseInterface;
use Phalcon\Http\Response as BaseResponse;
use PhalconPlus\Http\PsrResponseFactory;
use PhalconPlus\Http\NonPsrRequest;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\DiInterface;

class PsrApplication extends BaseApplication
{
    protected psrRequest = null { set, get };
    protected nativeRequest = null { get };

    public function __construct(<ServerRequestInterface> psrRequest, <DiInterface> dependencyInjector = null)
    {
        parent::__construct(dependencyInjector);
        let this->_sendHeaders = false;
        let this->_sendCookies = false;
        // <ServerRequestInterface>
        let this->psrRequest = psrRequest;
        // <Phalcon\Http\Request>
        let this->nativeRequest = new NonPsrRequest(psrRequest);
    }

    public function __destruct()
    {
        if this->nativeRequest {
            this->nativeRequest->removeTmpFiles();
        }
    }

    public function handle(string uri = null) -> <ResponseInterface>
    {
        if empty this->_dependencyInjector {
            throw new BaseException("there is no di(dependency injector) in PsrAppliction");
        }

        this->_dependencyInjector->setShared("request", this->nativeRequest);
   
        // var psrRequest = this->psrRequest,
        //     reqUri     = psrRequest->getUri()->getPath(),
        //     protocol   = psrRequest->getProtocolVersion();

        return <BaseResponse> parent::handle();
    }
}