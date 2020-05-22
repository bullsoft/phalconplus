namespace PhalconPlus\Contracts;

interface Dump
{
    public function __debugInfo() -> array;
}