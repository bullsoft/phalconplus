// <?php
namespace PhalconPlus\Enum;
use PhalconPlus\Enum\AbstractEnum;
use PhalconPlus\Enum\Sys as Sys;

class RunMode extends AbstractEnum
{
    const WEB = "Web";
    const CLI = "Cli";
    const SRV = "Srv";
    const MICRO = "Micro";

    const __default = self::CLI;

    // mode -> className
    // eg: mode "Web" has a module initial className in app/Module.php
    protected mapClasses = [
        "Web"     : "Module",
        "Cli"     : "Task",
        "Srv"     : "Srv",
        "Micro"   : "Micro"
    ];

    // 全局服务加载脚本定义
    protected scripts = [
        "Web"   : "default-web.php", 
        "Cli"   : "default-cli.php", 
        "Srv"   : "default-web.php", 
        "Micro" : "default-micro.php"
    ];

    public function getScriptPath() -> string | null
    {
        var script;
        let script = Sys::getGlobalLoadDir() . this->scripts[this->val];
        if !is_file(script) {
            error_log("PHP Notice:  PhalconPlus\\Bootstrap Global load file not exists: " . script);
            return null;
        }
        return script;
    }

    public function getMapClassName() -> string
    {
        return this->mapClasses[this->val];
    }
}
