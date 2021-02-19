namespace PhalconPlus\Curl;
use PhalconPlus\Contracts\Stringer;
use PhalconPlus\Contracts\ArrayOf;

class Response implements Stringer, ArrayOf
{
	/**
	 * The response headers.
	 *
	 * @var array
	 */
     public headers = [];
     /**
      * The response body.
      *
      * @var string
      */
     public body = "" { get };
     /**
      * The results of curl_getinfo on the response request.
      *
      * @var array|false
      */
     public info = [];
     /**
      * The response code including text, e.g. '200 OK'.
      *
      * @var string
      */
     public statusText = "" { get };
     /**
      * The response code.
      *
      * @var int
      */
     public statusCode { get };
     /**
      * @param string $body
      * @param string $headers
      * @param mixed  $info
      */
     public function __construct(string body, string headers, var info = [])
     {
         let this->body = body;
         let this->info = info;
         this->parseHeader(headers);
     }
     /**
      * Parse a header string.
      *
      * @param  string $header
      *
      * @return void
      */
     protected function parseHeader(string header)
     {
         var headers = [];
         let headers = explode("\r\n", trim(header));
         this->parseHeaders(headers);
     }
     /**
      * Parse an array of headers.
      *
      * @param  array  $headers
      *
      * @return void
      */
     protected function parseHeaders(array headers)
     {
         let this->headers = [];
         // find and set the HTTP status code and reason
         var firstHeader = array_shift(headers);
         // HTTP/1.1 200 OK
         if (!preg_match("/^HTTP\/\d(\.\d)? [0-9]{3}/", firstHeader)) {
             throw new \InvalidArgumentException("Invalid response header");
         }
         var code, status, parts;
         let parts = explode(" ", firstHeader, 2);

         let status = parts[1];
         let code = explode(" ", status);
         let code = intval(code[0]);

         var key, header, headerCopy = headers;
         // special handling for HTTP 100 responses
         if (code === 100) {
             // remove empty header lines between 100 and actual HTTP status
             for key, header in headerCopy {
                 if (header) {
                     break;
                 }
                 unset(headers[key]);
             }
             // start the process over with the 100 continue header stripped away
             return this->parseHeaders(headers);
         }
         let this->statusText = status;
         let this->statusCode = code;

         for header in headers {
             // skip empty lines
             if (!header) {
                 continue;
             }
             var delimiter = strpos(header, ":");
             if (!delimiter) {
                 continue;
             }
             var key, val;
             let key = trim(strtolower(substr(header, 0, delimiter)));
             let val = ltrim(substr(header, delimiter + 1));
             if (isset(this->headers[key])) {
                 if (is_array(this->headers[key])) {
                     let this->headers[key][] = val;
                 } else {
                     let this->headers[key] = [this->headers[key], val];
                 }
             } else {
                 let this->headers[key] = val;
             }
         }
     }
     /**
      * Get a specific header from the response.
      *
      * @param  string $key
      *
      * @return mixed
      */
     public function getHeader(key) -> string | null
     {
         let key = strtolower(key);
         return isset(this->headers[key]) ? this->headers[key] : null;
     }
     /**
      * Gets all the headers of the response.
      *
      * @return array
      */
     public function getHeaders() -> array
     {
         return this->headers;
     }
     /**
      * Convert the response instance to an array.
      *
      * @return array
      */
     public function toArray(array columns = []) -> array
     {
         return [
             "headers" : this->headers,
             "body"    : this->body,
             "info"    : this->info
         ];
     }
     /**
      * Convert the response object to a JSON string.
      *
      * @return string
      */
     public function toJson() -> string
     {
         return json_encode(this->toArray());
     }

     public function jsonSerialize()
     {
        return this->toArray();
     }

     /**
      * Convert the object to its string representation by returning the body.
      *
      * @return string
      */
     public function __toString() -> string
     {
         return this->body;
     }
}