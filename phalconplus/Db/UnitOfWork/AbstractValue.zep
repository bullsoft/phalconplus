namespace PhalconPlus\Db\UnitOfWork;
use PhalconPlus\Db\UnitOfWork;

abstract class AbstractValue 
{
    abstract public function getValue(<UnitOfWork> unitwork);
}