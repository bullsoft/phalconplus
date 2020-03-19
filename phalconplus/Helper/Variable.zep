namespace PhalconPlus\Helper;

class Variable
{
    public static function stringify(var value, bool full = false) -> string
    {
        if is_bool(value) {
            return value == true ? "TRUE" : "FALSE";
        }
        if value === NULL { 
            return "NULL"; 
        }
        var val = "";
        if is_scalar(value) {
            let val = (string) value;
            if full == false && strlen(val) > 100 {
                let val = substr(val, 0, 96) . " ...";
            }
            return val;
        }
        if is_array(value) || is_object(value) || is_resource(value) {
            let val = print_r(value, true);
            let val = preg_replace("/\s+/", " ", val);
            if full == false && strlen(val) > 160 {
                return substr(val, 0, 156) . " ...";
            }
            return val;
        }
        return "unknown";
    }
}