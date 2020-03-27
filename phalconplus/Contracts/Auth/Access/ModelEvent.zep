namespace PhalconPlus\Contracts\Auth\Access;
use Phalcon\Mvc\Model;
use Phalcon\Events\Event;

interface ModelEvent
{
    public function beforeDelete(<Event> event, <Model> model, var context = null) -> bool;
    public function beforeCreate(<Event> event, <Model> model, var context = null) -> bool;
    public function beforeUpdate(<Event> event, <Model> model, var context = null) -> bool;
    public function beforeValidation(<Event> event, <Model> model, var context = null) -> bool;
}