namespace PhalconPlus\Helper;

class Ns
{
    /**
     * PhalconPlus\App\Engine\Web -> PhalconPlus\App\Engine
     */
    public static function super(string ns, int levels)
    {
        var dir = strtr(ns, "\\", "/");
        var here = dirname(dir, levels);
        return strtr(here, "/", "\\");
    }
}