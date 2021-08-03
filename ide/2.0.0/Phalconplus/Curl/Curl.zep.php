<?php

namespace PhalconPlus\Curl;

use PhalconPlus\Curl\Request;
use PhalconPlus\Curl\Response;
use PhalconPlus\Curl\Exception as CurlException;
use Phalcon\Text;

/**
 * @ref https://github.com/anlutro/php-curl
 */
class Curl
{
    /**
     * The cURL resource.
     */
    protected $ch = null;

    /**
     * The default headers.
     *
     * @var array
     */
    protected $defaultHeaders = [];

    /**
     * The default curl options.
     *
     * @var array
     */
    protected $defaultOptions = [];

    /**
     * The base url
     *
     * @var string
     */
    protected $baseUrl = '';


    /**
     * @param array $opts
     */
    public function __construct(array $opts = [])
    {
    }

    /**
     * Get allowed methods.
     *
     * @return array
     */
    public function getAllowedMethods(): array
    {
    }

    /**
     * Set the default headers for every request.
     *
     * @param array $headers
     * @return Curl
     */
    public function setDefaultHeaders(array $headers): Curl
    {
    }

    /**
     * Get the default headers.
     *
     * @return array
     */
    public function getDefaultHeaders(): array
    {
    }

    /**
     * Set the default curl options for every request.
     *
     * @param array $options
     * @return Curl
     */
    public function setDefaultOptions(array $options): Curl
    {
    }

    /**
     * Get the default options.
     *
     * @return array
     */
    public function getDefaultOptions()
    {
    }

    /**
     * Get the default options.
     *
     * @return array
     * @param string $baseUrl
     */
    public function setBaseUrl(string $baseUrl): Curl
    {
    }

    /**
     * Build an URL with an optional query string.
     *
     * @param  string $url   the base URL without any query string
     * @param  array  $query array of GET parameters
     *
     * @return string
     */
    public function buildUrl(string $url, array $query): string
    {
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
    public function newRequest(string $method, string $url, $data, int $encoding = Request::ENCODING_QUERY): Request
    {
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
    public function newJsonRequest(string $method, string $url, array $data = []): Request
    {
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
    public function newRawRequest(string $method, string $url, $data = ''): Request
    {
    }

    /**
     * Prepare the curl resource for sending a request.
     *
     * @param  Request $request
     *
     * @return Curl
     */
    public function prepareRequest(\PhalconPlus\Curl\Request $request): Curl
    {
    }

    /**
     * Send a request.
     *
     * @param  Request $request
     *
     * @return Response
     */
    public function sendRequest(\PhalconPlus\Curl\Request $request): Response
    {
    }

    /**
     * Extract the response info, header and body from a cURL response. Saves
     * the data in variables stored on the object.
     *
     * @param  string $response
     *
     * @return Response
     */
    protected function createResponseObject($response): Response
    {
    }

    /**
     * Handle dynamic calls to the class.
     *
     * @param  string $func
     * @param  array  $args
     *
     * @return Response
     */
    public function __call(string $func, array $args): Response
    {
    }

}
