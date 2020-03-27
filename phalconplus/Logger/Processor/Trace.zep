namespace PhalconPlus\Logger\Processor;

class Trace extends AbstractProcessor
{
    const T_FILE  = 0x0001;
    const T_CLASS = 0x0010;

    private skipClassesPartials = [];
    private mode = self::T_FILE;
    private limit = 15;

    public function __construct(int mode = self::T_FILE, array skipClassesPartials = [])
    {
        let this->mode = mode;
        if !empty skipClassesPartials {
            let this->skipClassesPartials = skipClassesPartials;
        } else {
            let this->skipClassesPartials = [
                "PhalconPlus\\Logger\\", 
                "PhalconPlus\\Facades\\", 
                "Phalcon\\",
                "Exception"
            ];
        }
    }

    public function setLimit(int limit = 15)
    {
        let this->limit = limit;
    }

    public function __toString()
    {
        var trace = debug_backtrace(DEBUG_BACKTRACE_IGNORE_ARGS, this->limit);
        // skip first since it's always the current method
        array_shift(trace);
        // the MultiPleFile::log method is also skipped
        array_shift(trace);

        var i = 0, j = i, part;

        %{CHECK:}%
        while isset trace[i] {
            var tmp = trace[i]; 
            // unset(tmp["object"], tmp["args"]);
            // error_log(var_export(tmp, true));
            if isset trace[i]["class"] && j == i {
                // error_log("Class: " .trace[i]["class"]);
                for part in this->skipClassesPartials {
                    if strpos(tmp["class"], part) !== false {
                        // error_log("###" . tmp["class"]);
                        let i = i + 1, j = i;
                        %{goto CHECK;}%
                    }
                }
            }
            // let i = i + 1;
            break;
        }

        var k, trace1 = [], trace2 = [];
        let k = j - 1;

        let trace1 = [
            "file" : isset(trace[k]["file"]) ? trace[k]["file"] : "Nil",
            "line" : isset(trace[k]["line"]) ? trace[k]["line"] : -1
        ];

        let trace2 = [
            "class"    : isset(trace[j]["class"]) ? trace[j]["class"] : "Nil",
            "function" : isset(trace[j]["function"]) ? trace[j]["function"] : "Nil"
        ];

        switch this->mode & 0x0011 {
            case self::T_CLASS:
                return join(":", trace2);
            case 0x11:
                return join(":", trace1) . "][" . join(":", trace2);
            case self::T_FILE:
            default:
                return join(":", trace1);
        }
    }
}

