namespace PhalconPlus\Curl;

use PhalconPlus\Base\Exception as BaseException;

class Exception extends BaseException
{
    public function getRequest()
    {
        return this->info[2];
    }
}