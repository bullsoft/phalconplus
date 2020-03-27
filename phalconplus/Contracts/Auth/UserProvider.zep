namespace PhalconPlus\Contracts\Auth;
use Phalcon\Mvc\Model;

interface UserProvider
{
    // public function getById() -> <UserProvider>;
    // public function getByToken(string token) -> <UserProvider>;
    // public function getByCredentials(array credentials) -> <UserProvider>;
    // public function validateCredentials(<Model> user, array credentials) -> bool;

    public function getRole() -> string;
    public function getName() -> string;
    public function getIdName() -> string;
    public function getUsernameName() -> string;
}