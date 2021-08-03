<?php

namespace PhalconPlus\Http;

use Phalcon\Http\Response as NativeResponse;
use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\UploadedFileInterface;

class NonPsrResponse extends Phalcon\Http\Response
{

    /**
     * @param \Psr\Http\Message\ResponseInterface $psrResponse
     */
    public function __construct(\Psr\Http\Message\ResponseInterface $psrResponse)
    {
    }

}
