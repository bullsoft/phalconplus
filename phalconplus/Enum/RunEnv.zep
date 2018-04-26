namespace PhalconPlus\Enum;
use PhalconPlus\Enum\AbstractEnum;

class RunEnv extends AbstractEnum
{
    const DEV  = "dev";
    const DEBUG = "debug";
    const TEST = "test";
    const UAT = "uat";
    const PRODUCTION = "production";

    const __default = self::DEV;

    public static function isInProd(string env) -> boolean
    {
        // for compatibility
        return substr(env, 0, 7) == substr(self::PRODUCTION, 0, 7);
    }
}
