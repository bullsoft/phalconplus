namespace PhalconPlus\Contracts;

interface ArrayOf
{
    public function toArray(array columns = []) -> array;
}