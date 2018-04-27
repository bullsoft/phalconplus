namespace PhalconPlus\Enum;
use PhalconPlus\Enum\AbstractEnum;

class RunEnv extends AbstractEnum
{
    const DEV  = "dev";
    const DEBUG = "debug"; // for dev debugging
    const TEST = "test";
    const UAT = "uat"; // for test debugging
    const PRE_PRODUCTION = "pre_production";
    const AB_TEST = "ab_test"; // for A-B test in production
    const PRODUCTION = "production";

    const __default = self::DEV;

    public static function isInProd(string env) -> boolean
    {
        // for compatibility
        return substr(env, 0, 7) == substr(self::PRODUCTION, 0, 7);
    }

    public function isInAbTest()
    {
        return self::AB_TEST == this->val;
    }
}
