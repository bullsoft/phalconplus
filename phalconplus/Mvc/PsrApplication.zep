namespace PhalconPlus\Mvc;

use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\ResponseInterface as PsrResponseInterface;

use Phalcon\Http\ResponseInterface;
use Phalcon\Http\Response as BaseResponse;
use Phalcon\Di\DiInterface;
use Phalcon\Application\AbstractApplication as AbstractApplication;
use Phalcon\Mvc\Application as MvcApplication;

use PhalconPlus\Http\PsrResponseFactory;
use PhalconPlus\Http\NonPsrRequest;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Events\ManagerInterface;

class PsrApplication extends AbstractApplication
{
    protected app = null;

    public function __construct(<DiInterface> di)
    {
        parent::__construct(di);
        let this->app = new MvcApplication(di);
        this->app->sendCookiesOnHandleRequest(false)
                 ->sendHeadersOnHandleRequest(false);
    }

    public function handle(<ServerRequestInterface> request, boolean psr = false) -> <ResponseInterface> | <PsrResponseInterface>
    {
        if empty this->container {
            throw new BaseException("there is no di(dependency injector) in PsrAppliction");
        }

        var nativeRequest, nativeResponse, reqUri;

        let nativeRequest = new NonPsrRequest(request);
        this->container->setShared("request", nativeRequest);

        let reqUri = request->getUri()->getPath();

        let nativeResponse = <BaseResponse> this->app->handle(reqUri);

        if psr == true {
            return PsrResponseFactory::create(nativeResponse); // TODO
        }

        return nativeResponse;
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        parent::setEventsManager(eventsManager);
        this->app->setEventsManager(eventsManager);
    }
}