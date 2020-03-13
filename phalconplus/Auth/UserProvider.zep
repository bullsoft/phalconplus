namespace PhalconPlus\Auth;
use PhalconPlus\Contracts\Auth\UserProvider as UserProviderContract;
use Phalcon\Security;
use Phalcon\Text;
use Phalcon\Mvc\Model;

abstract class UserProvider implements UserProviderContract
{
    protected id;
    protected role = "Guests";
    protected name = "";
    protected entity = null { get };

    public function __construct(<Model> user = null, string role = "Guests")
    {
        if is_null(user) {
            let this->id = 0;    
            let this->name = Text::random(Text::RANDOM_ALNUM);
            let this->role = role;
        } else {
            var idName = this->getIdName();
            var usernameName = this->getUsernameName();
            var roleName = this->getRoleName();
            
            let this->id = user->{idName};
            if !empty(this->id) {
                let this->name = user->{usernameName};
                let this->role = empty(user->{roleName}) ? "Members" : user->{roleName};
                let this->entity = user;
            } else {
                let this->id = 0;    
                let this->name = Text::random(Text::RANDOM_ALNUM);
                let this->role = role;
            }
        }
    }

    public static function getById(string userId) -> <UserProvider>
    {
        // 
    }
    public static function getByToken(string token) -> <UserProvider>
    {
        // 
    }
    public static function getByCredentials(array credentials) -> <UserProvider>
    {
        // 
    }
    public static function loginByCredentials(array credentials) -> <UserProvider>
    {
        // 
    }
    public static function loginByToken(array credentials) -> <UserProvider>
    {
        // 
    }
    public static function checkLogin() -> bool
    {
        return false;
    }
    public static function checkLoginByToken() -> bool
    {
        return false;
    }
    public static function validateCredentials(<Model> user, array credentials) -> bool
    {
        return false;
    }

    public static function guest() -> <UserProvider>
    {
        var userClass = get_called_class();
        return new {userClass}();
    }

    public static function hashPassword(string rawPasswd, bool makeSalt = false) -> array
    {
        var sec, salt = "", encryptedPasswd = "";

        let sec = new Security();
        if makeSalt === true {
            let salt = sec->getSaltBytes();
        }
        let encryptedPasswd = sec->hash(Text::concat(rawPasswd, salt));
        return [
            "raw" : rawPasswd,
            "encrypted" : encryptedPasswd,
            "salt" : salt
        ];
    }

    public static function checkPassword(string rawPasswd, string encryptedPasswd, string salt = "") -> bool
    {
        var sec;
        let sec = new Security();
        return sec->checkHash(Text::concat(rawPasswd, salt), encryptedPasswd);
    }

    public function can(string ability, var params) -> bool
    {
        return false;
    }

    public function entity() -> <Model> | null
    {
        return this->entity;
    }

    public function hasAccess(string roleName) -> bool
    {
        return false;
    }
    
    public function getRole() -> string
    {
        return this->role;
    }

    public function getName() -> string
    {
        return this->name;
    }

    public function getIdName() -> string
    {
        return "id";
    }

    public function getUsernameName() -> string
    {
        return "username";
    }

    public function getRoleName() -> string
    {
        return "role";
    }
}