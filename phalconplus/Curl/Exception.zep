namespace PhalconPlus\Curl;

use PhalconPlus\Base\Exception as BaseException;

class Exception extends BaseException
{
    public function getRequest()
    {
        if isset this->info[1][0] {
            return this->info[1][0];
        }
        return null;
    }
}