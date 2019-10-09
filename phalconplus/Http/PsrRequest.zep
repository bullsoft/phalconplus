//<?php
namespace PhalconPlus\Http;

use Phalcon\Http\Request as BaseRequest;
use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\UploadedFileInterface;

use Phalcon\DiInterface;
use Phalcon\FilterInterface;
use Phalcon\Http\Request\File;
use Phalcon\Http\Request\Exception;
use Phalcon\Events\ManagerInterface;
use Phalcon\Di\InjectionAwareInterface;

class PsrRequest extends BaseRequest
{
    protected attributes = [] {
        get
    };
    protected cookies = [] {
        get
    };
    protected headers = [];
    protected files = [] {
        get
    };
    protected psrRequest = null {
        get
    };
    
    public function __construct(<ServerRequestInterface> request)
    {
        let this->attributes = request->getAttributes() ?: [];
        let this->cookies = request->getCookieParams() ?: [];
        let this->headers = request->getHeaders() ?: [];
        let this->_rawBody = request->getBody()->__toString();

        let _SERVER["REQUEST_URI"] = self::getRequestTarget(request);
        let _SERVER["REQUEST_METHOD"] = request->getMethod();
        
        var posts, gets, cookies;
        let posts = request->getParsedBody() ?: [];
        let gets  = request->getQueryParams() ?: [];
        let cookies = request->getCookieParams() ?: [];
        // Global variables
        var k, v;
        // POST
        for k, v in  posts {
            let _POST[k] = v;
        }
        // GET
        for k, v in gets {
            let _GET[k] = v;
        }
        let _GET["_url"] = request->getUri()->getPath();
        // SERVER
        for k, v in request->getServerParams() {
            let _SERVER[k] = v;
        }
        for k, v in this->headers {
            let k = strtoupper(str_replace("-", "_", k));
            let _SERVER["HTTP_".k] = v;
        }
        let _SERVER["REQUEST_URI"] = self::getRequestTarget(request);
        // COOKIE
        for k, v in cookies {
            let _COOKIE[k] = v;
        }
        // 设置SessionId
        if !empty this->cookies {
            if isset this->cookies[session_name()] {
                session_id(this->cookies[session_name()]);
            }
        }
        this->mapFiles(request->getUploadedFiles());
        var prefix, input;
        for prefix, input in this->files {
            let _FILES[prefix] = input;
        }

        let this->psrRequest = request;
    }

    protected static function getRequestTarget(<ServerRequestInterface> request)
    {
        var target = request->getUri()->getPath();
        if (target == "") {
            let target = "/";
        }
        if (request->getUri()->getQuery() != "") {
            let target .= "?" . request->getUri()->getQuery();
        }
        return target;
    }
 
    private function mapFiles(array uploads)
    {
        var file;
        for file in uploads {
            if is_array(file) {
                this->mapFiles(file);
            } elseif file instanceof UploadedFileInterface {
                var tmpname;
                let tmpname = tempnam(sys_get_temp_dir(), "upload");
             
                if (UPLOAD_ERR_OK == file->getError()) {
                    file_put_contents(tmpname, (string) file->getStream());
                }
                
                let this->files[] = [
                    "error"    : file->getError(),
                    "name"     : file->getClientFilename(),
                    "size"     : file->getSize(),
                    "tmp_name" : tmpname,
                    "type"     : file->getClientMediaType()
                ];
            }
        }
    }

    public function removeTmpFiles()
    {
        var item, tmp;
        for item in this->files {
            if fetch tmp, item["tmp_name"] {
                if file_exists(tmp) {
                    unlink(tmp);
                }
            }
        }
    }

    public function getScheme() -> string
    {
        return this->psrRequest->getUri()->getScheme();
    }

    /**
    * Checks whether request has been made using ajax
    */
    public function isAjax() -> boolean
    {
        return isset this->headers["HTTP_X_REQUESTED_WITH"] && this->headers["HTTP_X_REQUESTED_WITH"] === "XMLHttpRequest";
    }

    /**
    * Checks whether request has been made using SOAP
    */
    public function isSoap() -> boolean
    {
        var contentType;
        if isset this->headers["HTTP_SOAPACTION"] {
            return true;
        } else {
            let contentType = this->getContentType();
            if !empty contentType {
                return memstr(contentType, "application/soap+xml");
            }
        }
        return false;
    }
 

    public function getHttpHost() -> string
    {
        return this->psrRequest->getUri()->getHost();
    }

    public function getPort() -> int
    {
        return this->psrRequest->getUri()->getPort();
    }

    public function getHeaders() -> array
    {
        return this->headers;
    }

    public function getContentType() -> string | null
    {
    return  this->psrRequest->getHeaderLine("Content-Type");
    }

}
 