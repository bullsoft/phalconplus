namespace PhalconPlus\Contracts\Auth\Access;
use Phalcon\Mvc\DispatcherInterface;
use Phalcon\Events\Event;

interface DispatchEvent
{
    public function beforeExecuteRoute(<Event> event, <DispatcherInterface> dispatcher) -> bool;
}