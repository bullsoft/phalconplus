namespace PhalconPlus\Helper;

class Ns
{
    public static function super(string ns, int levels)
    {
        var dir = strtr(ns, "\\", "/");
        var here = dirname(dir, levels);
        return strtr(here, "/", "\\");
    }
}