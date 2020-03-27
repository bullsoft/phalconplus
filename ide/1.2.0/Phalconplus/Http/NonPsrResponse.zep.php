<?php

namespace PhalconPlus\Http;

use Phalcon\Http\Response as BaseResponse;
use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\UploadedFileInterface;

class NonPsrResponse extends Phalcon\Http\Response
{

    protected $psrResponse = null;


    /**
     * @param \Psr\Http\Message\ResponseInterface $psrResponse
     */
    public function __construct(\Psr\Http\Message\ResponseInterface $psrResponse)
    {
    }

}
