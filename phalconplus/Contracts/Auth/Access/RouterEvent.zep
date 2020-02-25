namespace PhalconPlus\Contracts\Auth\Access;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Route;
use Phalcon\Events\Event;

interface RouterEvent 
{
    public function matchedRoute(<Event> event, <Router> router, <Route> route);
}