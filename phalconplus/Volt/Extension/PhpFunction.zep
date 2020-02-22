namespace PhalconPlus\Volt\Extension;

class PhpFunction
{
    private ns = "";

    private func = "__invoke__";

    public function setCustNamespace(string! ns)
    {
        let this->ns = ns;
    }

    public function setCustFuncName(string! func)
    {
        if !empty func {
            let this->func = func;
        }
    }

    public function compileFunction()
    {
        var params = [];
        var name, args, code;
        let params = func_get_args();
        let name = array_shift(params);
        array_pop(params);

        let args = join(",", params);

        // 当你在Volt模板中使用 {{ __invoke__("Volt::output", "foo", "bar") }} 时，
        // 下面这段逻辑会帮你把上面的调用解析成 $NS\Volt::output("foo", "bar")
        // 让自定义Volt函数更加方便
        if name == this->func {
            var pos;
            let pos = strpos(args, ",");
            if pos === false {
                // call without params
                let name = trim(args, "'\"");
                let args = "";
            } else {
                // call with params
                let name = trim(substr(args, 0, pos), "'\"");
                let args = substr(args, pos+1);
            }
            let code = this->ns . name . "(" . args . ")";
            return code;
        }

        if function_exists(name) {
            let code = name . "(" . args . ")";
            return code;
        }
    }
}
