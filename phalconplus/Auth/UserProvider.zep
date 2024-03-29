namespace PhalconPlus\Auth;
use PhalconPlus\Contracts\Auth\UserProvider as UserProviderContract;
use PhalconPlus\Base\ProtoBuffer;
use Phalcon\Security;
use Phalcon\Support\HelperFactory;
use Phalcon\Support\Helper\Str\Random as RandomText;
use Phalcon\Mvc\Model;

abstract class UserProvider extends ProtoBuffer implements UserProviderContract
{
    const DEFAULT_ROLE1 = "Guests";
    const DEFAULT_ROLE2 = "Members";

    protected id;
    protected role = UserProvider::DEFAULT_ROLE1;
    protected name = "";
    protected entity = null { get };

    public function __construct(var user = null, string role = "Guests")
    {

        %{BEGIN:}%
        if is_null(user) {
            let this->id = 0;    
            let this->name = (new RandomText())->__invoke(RandomText::RANDOM_ALNUM);
            let this->role = role;
        } elseif (typeof user == "array") {
            if !isset user["id"] {
                let user = null;
                %{goto BEGIN;}%
            }
            let this->id   = user["id"];
            let this->name = user["name"];
            let this->role = user["role"];
        } elseif (typeof user == "object" && user instanceof Model) {
            var idName = this->getIdName();
            var usernameName = this->getUsernameName();
            var roleName = this->getRoleName();
            
            let this->id = user->{idName};
            if !empty(this->id) {
                let this->name = user->{usernameName};
                let this->role = empty(user->{roleName}) ? UserProvider::DEFAULT_ROLE2 : user->{roleName};
                let this->entity = user;
            } else {
                let this->id = 0;    
                let this->name = (new RandomText())->__invoke(RandomText::RANDOM_ALNUM);
                let this->role = role;
            }
        } else {
            let user = null;
            %{goto BEGIN;}%
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
    public static function getByCredentials(array credentials) -> <Model>
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
        let encryptedPasswd = sec->hash(rawPasswd . salt);
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
        return sec->checkHash(rawPasswd . salt, encryptedPasswd);
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

    public function getId() 
    {
        return this->id;
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

    // public function jsonSerialize()
    // {
    //     return [
    //         "name" : this->name,
    //         "id"   : this->id,
    //         "role" : this->role
    //     ];
    // }
}