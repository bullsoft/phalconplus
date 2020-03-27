namespace PhalconPlus\Http;

use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\UploadedFileInterface;
use GuzzleHttp\Psr7\Response as PsrBaseResponse;
use Phalcon\Http\Response as BaseResponse;
use PhalconPlus\Base\Exception as BaseException;
use Psr\Http\Message\ResponseInterface;

class PsrResponseFactory
{
    protected psrResponse = null;

    public static function create(<BaseResponse> response, var protocol = "1.1") -> <ResponseInterface>
    {
        var status = response->getStatusCode();
        var reason = response->getReasonPhrase();
        var content = response->getContent();
        // ob_start();
        // response->send();
        // var content = ob_get_clean();
        // if !empty stdout {
        //     let content = stdout . content;
        // }
        var headers = self::mapHeaders(response);

        if !class_exists("GuzzleHttp\\Psr7\\Response") {
            throw new BaseException("We use GuzzleHttp\\Psr7\\Response, please include that package");
        }
        var psrResponse;
        let psrResponse = new PsrBaseResponse(
            status ? status : 200, 
            headers, 
            content, 
            protocol, 
            reason ? reason : "OK"
        );

        if !isset(headers["Content-Length"]) {
            psrResponse->withAddedHeader("Content-Length", strlen(content));
        }
        return psrResponse;
    }

    protected static function mapHeaders(<BaseResponse> response) -> array
    {
        var headers = response->getHeaders()->toArray();
        
        var rawHeaders = headers_list();
        var h, pos, nativeHeaders = [];
        for h in rawHeaders {
            let pos = strpos(h, ":");
            if false !== pos {
                var name = substr(h, 0, pos);
                var value = trim(substr(h, pos + 1));
                if isset(nativeHeaders[name]) {
                    if !is_array(nativeHeaders[name]) {
                        let nativeHeaders[name] = [nativeHeaders[name]];
                    }
                    let nativeHeaders[name][] = value;
                } else {
                    let nativeHeaders[name] = value;
                }
            }
        }
        // after reading all headers we need to reset it, so next request
        // operates on a clean header.
        header_remove();
        let headers = array_merge(nativeHeaders, headers);
        
        if isset(nativeHeaders["Set-Cookie"]) {
            let headers["Set-Cookie"] = is_array(nativeHeaders["Set-Cookie"])?nativeHeaders["Set-Cookie"]:[nativeHeaders["Set-Cookie"]];
        } else {
            let headers["Set-Cookie"] = null;
        }
        return headers;
    }
}