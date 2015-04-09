namespace PhalconPlus\Volt\Extension;

class PhpFunction
{
    public function compileFunction(string name, string arguments) -> string
    {
        if function_exists(name) {
            return name . "(" . arguments . ")";
        } else {
            return "";
        }
    }
}
