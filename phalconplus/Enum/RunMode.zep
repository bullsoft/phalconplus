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
    protected map = [
        "Web"     : "Module",
        "Cli"     : "Task",
        "Srv"     : "Srv",
        "Micro"   : "Micro"
    ];

    public function getMapClassName()
    {
        return this->map[this->val];
    }
}
