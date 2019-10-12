<?php

namespace PhalconPlus\Http;


class PsrRequest extends Phalcon\Http\Request
{

    protected $attributes = array();


    protected $cookies = array();


    protected $headers = array();


    protected $files = array();


    protected $psrRequest = null;



    public function getAttributes() {}


    public function getCookies() {}


    public function getFiles() {}


    public function getPsrRequest() {}

    /**
     * @param \Psr\Http\Message\ServerRequestInterface $request
     */
    public function __construct(\Psr\Http\Message\ServerRequestInterface $request) {}

    /**
     * @param \Psr\Http\Message\ServerRequestInterface $request
     */
    protected static function getRequestTarget(\Psr\Http\Message\ServerRequestInterface $request) {}

    /**
     * @param array $uploads
     */
    private function mapFiles(array $uploads) {}


    public function removeTmpFiles() {}

    /**
     * @return string
     */
    public function getScheme(): string {}

    /**
     * Checks whether request has been made using ajax
     *
     * @return bool
     */
    public function isAjax(): bool {}

    /**
     * Checks whether request has been made using SOAP
     *
     * @return bool
     */
    public function isSoap(): bool {}

    /**
     * @return string
     */
    public function getHttpHost(): string {}

    /**
     * @return int
     */
    public function getPort(): int {}

    /**
     * @return array
     */
    public function getHeaders(): array {}

    /**
     * @return string|null
     */
    public function getContentType(): ?string {}

}
