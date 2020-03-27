namespace PhalconPlus\Facades;

class Request extends AbstractFacade
{
    protected function getName() -> string
    {
        return "request";
    }

    public static function setPost(string! name, var val)
    {
        let _POST[name] = val;
    }

    public static function setQuery(string! name, var val)
    {
        let _GET[name] = val;
    }

    public static function setServer(string! name, var val)
    {
        let _SERVER[name] = val;
    }

    public static function set(string! name, var val)
    {
        let _REQUEST[name] = val;
    }
}