<?php

namespace PhalconPlus\Http;

use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\UploadedFileInterface;
use GuzzleHttp\Psr7\Response as PsrBaseResponse;
use Phalcon\Http\Response as BaseResponse;
use PhalconPlus\Base\Exception as BaseException;

class PsrResponseFactory
{

    protected $psrResponse = null;


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
