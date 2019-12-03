namespace PhalconPlus\Curl;
use PhalconPlus\Curl\Request;
use PhalconPlus\Curl\Response;
use PhalconPlus\Curl\Exception as CurlException;

/**
 * @ref https://github.com/anlutro/php-curl
 */
class Curl
{
	/**
	 * The cURL resource.
	 */
     protected ch = null;
     /**
      * The default headers.
      *
      * @var array
      */
     protected defaultHeaders = [];
     /**
      * The default curl options.
      *
      * @var array
      */
     protected defaultOptions = [];


     public function __construct(array opts = [])
     {
        let this->defaultOptions = opts;
     }

     /**
      * Get allowed methods.
      *
      * @return array
      */
     public function getAllowedMethods()
     {
         return Request::methods;
     }
     /**
      * Set the default headers for every request.
      *
      * @param array $headers
      */
     public function setDefaultHeaders(array headers)
     {
         let this->defaultHeaders = headers;
     }
     /**
      * Get the default headers.
      *
      * @return array
      */
     public function getDefaultHeaders()
     {
         return this->defaultHeaders;
     }
     /**
      * Set the default curl options for every request.
      *
      * @param array $options
      */
     public function setDefaultOptions(array options)
     {
         let this->defaultOptions = options + this->defaultOptions;
     }
     /**
      * Get the default options.
      *
      * @return array
      */
     public function getDefaultOptions()
     {
         return this->defaultOptions;
     }
     /**
      * Build an URL with an optional query string.
      *
      * @param  string $url   the base URL without any query string
      * @param  array  $query array of GET parameters
      *
      * @return string
      */
     public function buildUrl(string url, array query)
     {
         if (empty(query)) {
             return url;
         }
         var retUrl;
         var parts = parse_url(url);
         var queryString = "";
         if (isset(parts["query"]) && parts["query"]) {
             let queryString = queryString . parts["query"]."&".http_build_query(query);
         } else {
             let queryString = queryString . http_build_query(query);
         }

         let retUrl = parts["scheme"]."://".parts["host"];
         if (isset(parts["port"])) {
             let retUrl = retUrl . ":" . parts["port"];
         }
         if (isset(parts["path"])) {
             let retUrl = retUrl . parts["path"];
         }
         if (queryString) {
             let retUrl = retUrl . "?" . queryString;
         }
         return retUrl;
     }
     /**
      * Create a new response object and set its values.
      *
      * @param  string  $method    get, post, etc
      * @param  string  $url
      * @param  mixed   $data      POST data
      * @param  int     $encoding  Request::ENCODING_* constant specifying how to process the POST data
      *
      * @return Request
      */
     public function newRequest(string method, string url, var data, int encoding = Request::ENCODING_QUERY)
     {
         var request;
         let request = new Request(this);
         if (this->defaultHeaders) {
             request->setHeaders(this->defaultHeaders);
         }
         if (this->defaultOptions) {
             request->setOptions(this->defaultOptions);
         }
         request->setMethod(method);
         request->setUrl(url);
         request->setData(data);
         request->setEncoding(encoding);
         return request;
     }
     /**
      * Create a new JSON request and set its values.
      *
      * @param  string $method  get, post etc
      * @param  string $url
      * @param  mixed  $data    POST data
      *
      * @return Request
      */
     public function newJsonRequest(string method, string url, array data = [])
     {
         return this->newRequest(method, url, data, Request::ENCODING_JSON);
     }
     /**
      * Create a new raw request and set its values.
      *
      * @param  string $method  get, post etc
      * @param  string $url
      * @param  mixed  $data    request body
      *
      * @return Request
      */
     public function newRawRequest(string method, string url, var data = "")
     {
         return this->newRequest(method, url, data, Request::ENCODING_RAW);
     }
     /**
      * Prepare the curl resource for sending a request.
      *
      * @param  Request $request
      *
      * @return void
      */
     public function prepareRequest(<Request> request)
     {
         let this->ch = curl_init();
         curl_setopt(this->ch, CURLOPT_RETURNTRANSFER, true);
         curl_setopt(this->ch, CURLOPT_HEADER, true);
         var auth, options, method;
         let auth = request->getUserAndPass();
         if (auth) {
             curl_setopt(this->ch, CURLOPT_USERPWD, auth);
         }
         curl_setopt(this->ch, CURLOPT_URL, request->getUrl());
         let options = request->getOptions();
         if (!empty(options)) {
             curl_setopt_array(this->ch, options);
         }
         let method = request->getMethod();
         curl_setopt(this->ch, CURLOPT_CUSTOMREQUEST, strtoupper(method));
         curl_setopt(this->ch, CURLOPT_HTTPHEADER, request->formatHeaders());
         if (request->hasData()) {
             curl_setopt(this->ch, CURLOPT_POSTFIELDS, request->encodeData());
         }
         if ($method === "head") {
             curl_setopt(this->ch, CURLOPT_NOBODY, true);
         }
     }
     /**
      * Send a request.
      *
      * @param  Request $request
      *
      * @return Response
      */
     public function sendRequest(<Request> request)
     {
         this->prepareRequest(request);
         var result, response;
         let result = curl_exec(this->ch);
         if (result === false) {
             var ex, errno, msg, errmsg;
             let errno = curl_errno(this->ch);
             let errmsg = curl_error(this->ch);
             let msg = "Curl request failed with error [".errno.":". errmsg;
             curl_close(this->ch);
             let ex = new CurlException([msg, [], request]);
             throw ex->setCode(errno);
         }
         let response = this->createResponseObject(result);
         curl_close(this->ch);
         return response;
     }
     /**
      * Extract the response info, header and body from a cURL response. Saves
      * the data in variables stored on the object.
      *
      * @param  string $response
      *
      * @return Response
      */
     protected function createResponseObject(response)
     {
         var info, headerSize, headers, body;
         let info = curl_getinfo(this->ch);
         let headerSize = curl_getinfo(this->ch, CURLINFO_HEADER_SIZE);
         let headers = substr(response, 0, headerSize);
         let body = substr(response, headerSize);
         return new Response(body, headers, info);
     }
     /**
      * Handle dynamic calls to the class.
      *
      * @param  string $func
      * @param  array  $args
      *
      * @return mixed
      */
     public function __call(string func, array args)
     {
         var request, method, encoding, url, data = null, msg;
         let method = strtolower(func);
         let encoding = Request::ENCODING_QUERY;
         if (substr(method, 0, 4) === "json") {
             let encoding = Request::ENCODING_JSON;
             let method = substr(method, 4);
         } elseif (substr(method, 0, 3) === "raw") {
             let encoding = Request::ENCODING_RAW;
             let method = substr($method, 3);
         }
         if (!array_key_exists(method, Request::methods)) {
             let msg = "Method [".method."] not a valid HTTP method.";
             throw new \BadMethodCallException(msg);
         }
         if (!isset(args[0])) {
             let msg = "Missing argument 1 (".url.") for ".__CLASS__. "::" . func;
             throw new \BadMethodCallException(msg);
         }
         let url = args[0];
         if (isset(args[1])) {
             let data = args[1];
         }
         let request = this->newRequest(method, url, data, encoding);
         return this->sendRequest(request);
     }
}