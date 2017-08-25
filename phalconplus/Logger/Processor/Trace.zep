namespace PhalconPlus\Logger\Processor;

class Trace extends AbstractProcessor
{
    const T_FILE = 0x0001;
    const T_CLASS = 0x0010;

    private skipClassesPartials = [];

    private mode = self::T_FILE;

    public function __construct(int mode = self::T_FILE, array skipClassesPartials = [])
    {
        let this->mode = mode;
        if empty skipClassesPartials {
            let this->skipClassesPartials = ["PhalconPlus\\", "Phalcon\\"];
        }
    }

    public function __toString()
    {
        var trace;
        let trace = debug_backtrace();

        // skip first since it's always the current method
        array_shift(trace);
        // the strval is also skipped
        array_shift(trace);

        var i = 0, part;

        %{CHECK:}%
        while isset(trace[i]["class"]) {
            // error_log("Class: " .trace[i]["class"]);
            for part in this->skipClassesPartials {
                if strpos(trace[i]["class"], part) !== false {
                    let i = i + 1;
                    %{goto CHECK;}%
                }
            }
            break;
        }

        var j, trace1 = [], trace2 = [];
        let j = i - 1;

        let trace1 = [
            "file"      : isset(trace[j]["file"]) ? trace[j]["file"] : "Nil",
            "line"      : isset(trace[j]["line"]) ? trace[j]["line"] : -1
        ];

        let trace2 = [
            "class"     : isset(trace[i]["class"]) ? trace[i]["class"] : "Nil",
            "function"  : isset(trace[i]["function"]) ? trace[i]["function"] : "Nil"
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

