namespace PhalconPlus\Contracts\Auth;
// use Phalcon\Mvc\Model;

interface UserProvider
{
    public function getById();
    // public function getByToken();
    // public function getByCredentials(array credentials);
    // public function validateCredentials(<Model> $user, array $credentials);
    // public function guest() -> <UserProvider>;
    public function getRole();
    public function getIdName() -> string;
    public function getIdValue();
    public function setIdValue(var val) -> <UserProvider>;
}