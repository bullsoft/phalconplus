<?php

namespace PhalconPlus\Http;

use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\UploadedFileInterface;
use Phalcon\Di\DiInterface;
use Phalcon\Http\Request\File;
use Phalcon\Http\Request\Exception;
use Phalcon\Http\Request as NativeRequest;
use Phalcon\Events\ManagerInterface;
use Phalcon\Di\InjectionAwareInterface;

class NonPsrRequest extends Phalcon\Http\Request
{

    protected $attributes = [];


    protected $cookies = [];


    protected $files = [];


    protected $psrRequest = null;


    protected $headers = [];



    public function getAttributes()
    {
    }


    public function getCookies()
    {
    }


    public function getFiles()
    {
    }


    public function getPsrRequest()
    {
    }

    /**
     * @param \Psr\Http\Message\ServerRequestInterface $request
     */
    public function __construct(\Psr\Http\Message\ServerRequestInterface $request)
    {
    }


    protected function getRequestTarget()
    {
    }

    /**
     * @param array $uploads
     */
    private function mapFiles(array $uploads)
    {
    }


    protected function removeTmpFiles()
    {
    }

    /**
     * @return string
     */
    public function getScheme(): string
    {
    }

    /**
     * Checks whether request has been made using ajax
     *
     * @return bool
     */
    public function isAjax(): bool
    {
    }

    /**
     * Checks whether request has been made using SOAP
     *
     * @return bool
     */
    public function isSoap(): bool
    {
    }

    /**
     * @return string
     */
    public function getHttpHost(): string
    {
    }

    /**
     * @return int
     */
    public function getPort(): int
    {
    }

    /**
     * @return array
     */
    public function getHeaders(): array
    {
    }

    /**
     * @return string|null
     */
    public function getContentType(): ?string
    {
    }


    public function __destruct()
    {
    }

}
