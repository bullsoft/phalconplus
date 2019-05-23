// <?php
namespace PhalconPlus\Enum;
use PhalconPlus\Enum\AbstractEnum;

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
        "Micro" : "default-web.php"
    ];

    public function getScriptPath()
    {
        var script;
        let script = APP_ROOT_COMMON_LOAD_DIR . this->scripts[this->val];
        if !is_file(script) {
            error_log("PHP Notice:  PhalconPlus\\Bootstrap Global load file not exists: " . script);
        }
        return script;
    }

    public function getMapClassName()
    {
        return this->mapClasses[this->val];
    }
}
