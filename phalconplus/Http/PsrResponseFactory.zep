namespace PhalconPlus\Http;

use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\UploadedFileInterface;
use Phalcon\Http\Message\Response as PsrResponse;
use Phalcon\Http\Response as NativeResponse;
use PhalconPlus\Base\Exception as BaseException;

class PsrResponseFactory
{
    public static function create(<NativeResponse> response, var protocol = "1.1") -> <ResponseInterface>
    {
        var status  = response->getStatusCode();
        var reason  = response->getReasonPhrase();
        var content = response->getContent();

        // ob_start();
        // response->send();
        // var content = ob_get_clean();
        // if !empty stdout {
        //     let content = stdout . content;
        // }

        var headers = self::mapHeaders(response);

        var psrResponse;
        string className = "GuzzleHttp\\Psr7\\Response";
        let psrResponse = new {className}(
            status ? status : 200,
            headers,
            content,
            protocol
        );

        if !isset(headers["Content-Length"]) {
            psrResponse->withAddedHeader("Content-Length", strlen(content));
        }

        return psrResponse;
    }

    protected static function mapHeaders(<NativeResponse> response) -> array
    {
        var headers = response->getHeaders()->toArray();
        var rawHeaders = headers_list();

        var line, key, pos, nativeHeaders = [];
        for line in rawHeaders {
            let pos = strpos(line, ":");
            if false !== pos {
                var name = substr(line, 0, pos);
                var value = trim(substr(line, pos + 1));
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
        for key, _ in headers {
            if typeof key == "string" && starts_with(key, "HTTP/") {
                unset(headers[key]);
            }
        }
        // after reading all headers we need to reset it, so next request
        // operates on a clean header.
        header_remove();
        let headers = array_merge(nativeHeaders, headers);

        if isset(nativeHeaders["Set-Cookie"]) {
            let headers["Set-Cookie"] = is_array(nativeHeaders["Set-Cookie"]) ? nativeHeaders["Set-Cookie"] : [nativeHeaders["Set-Cookie"]];
        } else {
            let headers["Set-Cookie"] = null;
        }
        return headers;
    }
}
