namespace PhalconPlus\Contracts\Auth;
use Phalcon\Mvc\Model;

interface Policy
{
    public function list(<UserProvider> user, <Model> model) -> bool;
    public function view(<UserProvider> user, <Model> model) -> bool;
    public function delete(<UserProvider> user, <Model> model) -> bool;
    public function create(<UserProvider> user, <Model> model) -> bool;
    public function update(<UserProvider> user, <Model> model) -> bool;
}