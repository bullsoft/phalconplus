<?php

namespace PhalconPlus\Http;

use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\UploadedFileInterface;
use Phalcon\Http\Message\Response as PsrResponse;
use Phalcon\Http\Response as NativeResponse;
use PhalconPlus\Base\Exception as BaseException;

class PsrResponseFactory
{

    /**
     * @param \Phalcon\Http\Response $response
     * @param mixed $protocol
     * @return ResponseInterface
     */
    public static function create(\Phalcon\Http\Response $response, $protocol = '1.1'): ResponseInterface
    {
    }

    /**
     * @param \Phalcon\Http\Response $response
     * @return array
     */
    protected static function mapHeaders(\Phalcon\Http\Response $response): array
    {
    }

}
