<?php

namespace PhalconPlus\Curl;

use PhalconPlus\Contracts\Stringer;
use PhalconPlus\Contracts\ArrayOf;

class Response implements \PhalconPlus\Contracts\Stringer, \PhalconPlus\Contracts\ArrayOf
{
    /**
     * The response headers.
     *
     * @var array
     */
    public $headers = [];

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
    public $info = [];

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
    public function __construct(string $body, string $headers, $info = [])
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
    public function getHeader($key): ?string
    {
    }

    /**
     * Gets all the headers of the response.
     *
     * @return array
     */
    public function getHeaders(): array
    {
    }

    /**
     * Convert the response instance to an array.
     *
     * @return array
     * @param array $columns
     */
    public function toArray(array $columns = []): array
    {
    }

    /**
     * Convert the response object to a JSON string.
     *
     * @return string
     */
    public function toJson(): string
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
    public function __toString(): string
    {
    }

}
