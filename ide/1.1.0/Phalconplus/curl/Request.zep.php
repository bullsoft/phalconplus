<?php

namespace PhalconPlus\Curl;

use PhalconPlus\Curl\Curl;

class Request
{
    /**
     * ENCODING_ constants,
     * used for specifying encoding options
     */
    const ENCODING_QUERY = 0;


    const ENCODING_JSON = 1;


    const ENCODING_RAW = 2;

    /**
     * Allowed methods => allows postdata
     *
     * @var array
     */
    static public $methods = array('get' => false, 'head' => false, 'post' => true, 'put' => true, 'patch' => true, 'delete' => true, 'options' => false);

    /**
     * The URL the request is sent to.
     *
     * @var string
     */
    private $url = '';

    /**
     * The headers sent with the request.
     *
     * @var array
     */
    private $headers = array();

    /**
     * The cookies sent with the request.
     *
     * @var array
     */
    private $cookies = array();

    /**
     * POST data sent with the request.
     *
     * @var mixed
     */
    private $data = array();

    /**
     * Optional cURL options.
     *
     * @var array
     */
    private $options = array();

    /**
     * Username to authenticate the request of cURL.
     *
     * @var string
     */
    private $user = '';

    /**
     * Password to authenticate the request of cURL.
     *
     * @var string
     */
    private $pass = '';

    /**
     * The type of processing to perform to encode the POST data
     *
     * @var int
     */
    private $encoding = self::ENCODING_QUERY;


    private $method = '';

    /**
     * Curl client
     *
     * @var <Curl>
     */
    private $curl = null;


    /**
     * Constructor
     *
     * @param \PhalconPlus\Curl\Curl $curl
     */
    public function __construct(\PhalconPlus\Curl\Curl $curl)
    {
    }

    /**
     * Set the HTTP method of the request.
     *
     * @param string $method
     */
    public function setMethod(string $method)
    {
    }

    /**
     * Get the HTTP method of the request.
     *
     * @return string
     */
    public function getMethod()
    {
    }

    /**
     * Set the URL of the request.
     *
     * @param string $url
     */
    public function setUrl(string $url)
    {
    }

    /**
     * Get the URL of the request.
     *
     * @return string
     */
    public function getUrl()
    {
    }

    /**
     * Set a specific header to be sent with the request.
     *
     * @param string $key   Can also be a string in "foo: bar" format
     * @param mixed  $value
     * @param boolean  $preserveCase
     */
    public function setHeader($key, $value = null, bool $preserveCase = false)
    {
    }

    /**
     * Set the headers to be sent with the request.
     *
     * Pass an associative array - e.g. ['Content-Type' => 'application/json']
     * and the correct header formatting - e.g. 'Content-Type: application/json'
     * will be done for you when the request is sent.
     *
     * @param array $headers
     */
    public function setHeaders(array $headers)
    {
    }

    /**
     * Get a specific header from the request.
     *
     * @param  string $key
     *
     * @return mixed
     */
    public function getHeader(string $key)
    {
    }

    /**
     * Get the headers to be sent with the request.
     *
     * @return array
     */
    public function getHeaders()
    {
    }

    /**
     * Set a cookie.
     *
     * @param string $key
     * @param string $value
     */
    public function setCookie(string $key, string $value)
    {
    }

    /**
     * Replace the request's cookies.
     *
     * @param array $cookies
     */
    public function setCookies(array $cookies)
    {
    }

    /**
     * Read the request cookies and set the cookie header.
     *
     * @return void
     */
    private function updateCookieHeader()
    {
    }

    /**
     * Get a specific cookie from the request.
     *
     * @param  string $key
     *
     * @return string|null
     */
    public function getCookie(string $key)
    {
    }

    /**
     * Get all the request's cookies.
     *
     * @return string[]
     */
    public function getCookies()
    {
    }

    /**
     * Format the headers to an array of 'key: val' which can be passed to
     * curl_setopt.
     *
     * @return array
     */
    public function formatHeaders()
    {
    }

    /**
     * Set the POST data to be sent with the request.
     *
     * @param mixed $data
     */
    public function setData($data)
    {
    }

    /**
     * Check whether the request has any data.
     *
     * @return boolean
     */
    public function hasData()
    {
    }

    /**
     * Get the POST data to be sent with the request.
     *
     * @return mixed
     */
    public function getData()
    {
    }

    /**
     * Set the encoding to use on the POST data, and (possibly) associated Content-Type headers
     *
     * @param int  $encoding  a Request::ENCODING_* constant
     */
    public function setEncoding(int $encoding)
    {
    }

    /**
     * Get the current encoding which will be used on the POST data
     *
     * @return int  a Request::ENCODING_* constant
     */
    public function getEncoding()
    {
    }

    /**
     * Encode the POST data as a string.
     *
     * @return string
     */
    public function encodeData()
    {
    }

    /**
     * Set a specific curl option for the request.
     *
     * @param string $key
     * @param mixed  $value
     */
    public function setOption(string $key, $value)
    {
    }

    /**
     * Set the cURL options for the request.
     *
     * @param array $options
     */
    public function setOptions(array $options)
    {
    }

    /**
     * Get a specific curl option from the request.
     *
     * @param  string $key
     *
     * @return mixed
     */
    public function getOption(string $key)
    {
    }

    /**
     * Get the cURL options for the request.
     *
     * @return array
     */
    public function getOptions()
    {
    }

    /**
     * Set the HTTP basic username and password.
     *
     * @param  string $user
     * @param  string $pass
     *
     * @return string
     */
    public function auth(string $user, string $pass)
    {
    }

    /**
     * Set an username to authenticate the request of curl.
     *
     * @param  string $user
     *
     * @return static
     */
    public function setUser(string $user)
    {
    }

    /**
     * Set a password to authenticate the request of curl.
     *
     * @param  string $pass
     *
     * @return static
     */
    public function setPass(string $pass)
    {
    }

    /**
     * If username and password is set, returns a string of 'username:password'.
     * If not, returns null.
     *
     * @return string|null
     */
    public function getUserAndPass()
    {
    }

    /**
     * Whether the request is JSON or not.
     *
     * @return boolean
     */
    public function isJson()
    {
    }

    /**
     * Send the request.
     *
     * @return Response
     */
    public function send()
    {
    }

}
