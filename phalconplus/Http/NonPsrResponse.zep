namespace PhalconPlus\Http;

use Phalcon\Http\Response as NativeResponse;
use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\UploadedFileInterface;

class NonPsrResponse extends NativeResponse
{
    public function __construct(<ResponseInterface> psrResponse)
    {
        parent::__construct(
            psrResponse->getBody()->__toString(),
            psrResponse->getStatusCode(),
            psrResponse->getReasonPhrase()
        );

        var cookies, cookie,
            values, value, name;

        let cookies = psrResponse->getHeader("Set-Cookie");

        var newPsrResponse = psrResponse->withoutHeader("Set-Cookie");

        var headers = newPsrResponse->getHeaders();

        for name, values in headers {
            for value in values {
                this->setHeader(name, value);
            }
        }

        for cookie in cookies {
            this->setRawHeader("Set-Cookie: ".cookie);
        }
    }
}
