<?php

namespace PhalconPlus\Curl;

class Response
{
    /**
     * The response headers.
     *
     * @var array
     */
    public $headers = array();

    /**
     * The response body.
     *
     * @var string
     */
    public $body = '';

    /**
     * The results of curl_getinfo on the response request.
     *
     * @var array|false
     */
    public $info = array();

    /**
     * The response code including text, e.g. '200 OK'.
     *
     * @var string
     */
    public $statusText = '';

    /**
     * The response code.
     *
     * @var int
     */
    public $statusCode;


    /**
     * The response body.
     *
     * @return string
     */
    public function getBody(): string
    {
    }

    /**
     * The response code including text, e.g. '200 OK'.
     *
     * @return string
     */
    public function getStatusText(): string
    {
    }

    /**
     * The response code.
     *
     * @return int
     */
    public function getStatusCode(): int
    {
    }

    /**
     * @param string $body
     * @param string $headers
     * @param mixed  $info
     */
    public function __construct(string $body, string $headers, $info = array())
    {
    }

    /**
     * Parse a header string.
     *
     * @param  string $header
     *
     * @return void
     */
    protected function parseHeader(string $header)
    {
    }

    /**
     * Parse an array of headers.
     *
     * @param  array  $headers
     *
     * @return void
     */
    protected function parseHeaders(array $headers)
    {
    }

    /**
     * Get a specific header from the response.
     *
     * @param  string $key
     *
     * @return mixed
     */
    public function getHeader($key)
    {
    }

    /**
     * Gets all the headers of the response.
     *
     * @return array
     */
    public function getHeaders()
    {
    }

    /**
     * Convert the response instance to an array.
     *
     * @return array
     */
    public function toArray()
    {
    }

    /**
     * Convert the response object to a JSON string.
     *
     * @return string
     */
    public function toJson()
    {
    }


    public function jsonSerialize()
    {
    }

    /**
     * Convert the object to its string representation by returning the body.
     *
     * @return string
     */
    public function __toString()
    {
    }

}
