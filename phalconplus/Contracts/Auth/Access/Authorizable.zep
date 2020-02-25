namespace PhalconPlus\Contracts\Auth\Access;

interface Authorizable
{
    public function can(string ability, var params) -> bool;
}