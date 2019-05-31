//<?php
namespace PhalconPlus\Base;

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
    protected get = [];
    protected post = [];
    protected request = [];
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
    protected server = [];
    protected psrRequest = null {
        get
    };
    
    public function __construct(<ServerRequestInterface> request)
    {
        let this->get = request->getQueryParams();
        let this->post = request->getParsedBody() ?: [];
        let this->request = array_merge(this->get, this->post);
        let this->attributes = request->getAttributes();
        let this->cookies = request->getCookieParams();
        let this->headers = request->getHeaders();
        let this->server = request->getServerParams();
        let this->server["REQUEST_METHOD"] = request->getMethod();
        let this->_rawBody = request->getBody()->__toString();

        let _SERVER["REQUEST_URI"] = self::getRequestTarget(request);
        let _SERVER["REQUEST_METHOD"] = request->getMethod();
        
        this->mapFiles(request->getUploadedFiles());

        var k, v;
        for k, v in this->headers {
            let k = strtoupper(str_replace("-", "_", k));
            let _SERVER["HTTP_".k] = v;
        }
        // 设置SessionId
        if !empty this->cookies {
            if isset this->cookies[session_name()] {
                session_id(this->cookies[session_name()]);
            }
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
        var file;
        for file in this->files {
            if file_exists(file["tmp_name"]) {
                unlink(file["tmp_name"]);
            }
        }
    }

    public function get(string! name = null, var filters = null, var defaultValue = null, boolean notAllowEmpty = false, boolean noRecursive = false) -> var
    {
        var post = array_merge(this->post, _POST);
        var get = array_merge(this->get, _GET);
        var request = array_merge(get, post);
        return this->getHelper(request, name, filters, defaultValue, notAllowEmpty, noRecursive);
    }

    public function getPost(string! name = null, var filters = null, var defaultValue = null, boolean notAllowEmpty = false, boolean noRecursive = false) -> var
    {
        var post = array_merge(this->post, _POST);
        return this->getHelper(post, name, filters, defaultValue, notAllowEmpty, noRecursive);
    }

    public function getQuery(string! name = null, var filters = null, var defaultValue = null, boolean notAllowEmpty = false, boolean noRecursive = false) -> var
    {
        var get = array_merge(this->get, _GET);
        return this->getHelper(get, name, filters, defaultValue, notAllowEmpty, noRecursive);
    }

    public function has(string! name) -> boolean
    {
        return ! emtpy(this->get(name));
    }

    public function hasPost(string! name) -> boolean
    {
        return ! empty(this->getPost(name));
    }

    public function hasQuery(string! name) -> boolean
    {
        return ! emtpy(this->getQuery(name));
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
 
    public function getServerAddress() -> string
    {
        var serverAddr;
        if fetch serverAddr, this->server["SERVER_ADDR"] {
            return serverAddr;
        }
        return gethostbyname("localhost");
    }

    /**
     * Gets active server name
     */
    public function getServerName() -> string
    {
        var serverName;

        if fetch serverName, this->server["SERVER_NAME"] {
            return serverName;
        }

        return "localhost";
    }

    public function getHttpHost() -> string
    {
        return this->psrRequest->getUri()->getHost();
    }

    public function getPort() -> int
    {
        return this->psrRequest->getUri()->getPort();
    }

    public function getClientAddress(boolean trustForwardedHeader = false) -> string | boolean
    {
        var address = null;

        /**
         * Proxies uses this IP
         */
        if trustForwardedHeader {
            fetch address, this->server["HTTP_X_FORWARDED_FOR"];
            if address === null {
                fetch address, this->server["HTTP_CLIENT_IP"];
            }
        }

        if address === null {
            fetch address, this->server["REMOTE_ADDR"];
        }

        if typeof address == "string" {
            if memstr(address, ",") {
                /**
                * The client address has multiples parts, only return the first part
                */
                return explode(",", address)[0];
            }
            return address;
        }

        return false;
    }

    public function getUserAgent() -> string
    {
        var userAgent;

        if fetch userAgent, this->server["HTTP_USER_AGENT"] {
            return userAgent;
        }
        return "";
    }

    public function hasFiles(boolean onlySuccessful = false) -> long
    {
        var files, file, error;
        int numberFiles = 0;

        let files = this->files;

        if typeof files != "array" {
            return 0;
        }

        for file in files {
            if fetch error, file["error"] {

                if typeof error != "array" {
                    if !error || !onlySuccessful {
                        let numberFiles++;
                    }
                }

                if typeof error == "array" {
                    let numberFiles += this->hasFileHelper(error, onlySuccessful);
                }
            }
        }

        return numberFiles;
    }

    public function getUploadedFiles(boolean onlySuccessful = false) -> <\Phalcon\Http\Request\FileInterface[]>
    {
        var superFiles, prefix, input, smoothInput, file, dataFile;
        array files = [];

        let superFiles = this->files;

        if count(superFiles) > 0 {

            for prefix, input in superFiles {
                if typeof input["name"] == "array" {
                    let smoothInput = this->smoothFiles(
                        input["name"],
                        input["type"],
                        input["tmp_name"],
                        input["size"],
                        input["error"],
                        prefix
                    );

                    for file in smoothInput {
                        if onlySuccessful == false || file["error"] == UPLOAD_ERR_OK {
                            let dataFile = [
                                "name": file["name"],
                                "type": file["type"],
                                "tmp_name": file["tmp_name"],
                                "size": file["size"],
                                "error": file["error"]
                            ];

                            let files[] = new File(dataFile, file["key"]);
                        }
                    }
                } else {
                    if onlySuccessful == false || input["error"] == UPLOAD_ERR_OK {
                        let files[] = new File(input, prefix);
                    }
                }
            }
        }

        return files;
    }

    public function getHeaders() -> array
    {
        return this->headers;
    }

    public function getHTTPReferer() -> string
    {
        var httpReferer;
        if fetch httpReferer, this->server["HTTP_REFERER"] {
            return httpReferer;
        }
        return "";
    }

    public function getContentType() -> string | null
    {
    return  this->psrRequest->getHeaderLine("Content-Type");
    }


    public function getBasicAuth() -> array | null
    {
        var auth;

        if isset this->server["PHP_AUTH_USER"] && isset this->server["PHP_AUTH_PW"] {
            let auth = [];
            let auth["username"] = this->server["PHP_AUTH_USER"];
            let auth["password"] = this->server["PHP_AUTH_PW"];
            return auth;
        }

        return null;
    }

    public function getDigestAuth() -> array
    {
        var digest, matches, match;
        array auth;

        let auth = [];
        if fetch digest, this->server["PHP_AUTH_DIGEST"] {
            let matches = [];
            if !preg_match_all("#(\\w+)=(['\"]?)([^'\" ,]+)\\2#", digest, matches, 2) {
                return auth;
            }
            if typeof matches == "array" {
                for match in matches {
                    let auth[match[1]] = match[3];
                }
            }
        }
        return auth;
    }
}
 