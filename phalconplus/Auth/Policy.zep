namespace PhalconPlus\Auth;
use PhalconPlus\Contracts\Auth\UserProvider;
use PhalconPlus\Contracts\Auth\Policy as PolicyContract;
use Phalcon\Mvc\Model;
use Phalcon\Di\Injectable;
use Phalcon\Acl\Adapter\Memory as AclList;
use PhalconPlus\Facades\Acl;

class Policy extends Injectable implements PolicyContract
{
    protected acl;

    public function __construct() 
    {
        let this->acl = this->getDI()->get("acl");
    }

    public function list(<UserProvider> user, <Model> model) -> bool
    {
        return this->acl->isAllowed(
            user->getRole(),
            get_class(model),
            "list",
            [
                user,
                model
            ]
        );
    }

    public function view(<UserProvider> user, <Model> model) -> bool
    {
        return this->acl->isAllowed(
            user->getRole(),
            get_class(model),
            "view",
            [
                user,
                model
            ]
        );
    }

    public function delete(<UserProvider> user, <Model> model) -> bool
    {
        return this->acl->isAllowed(
            user->getRole(),
            get_class(model),
            "delete",
            [
                user,
                model
            ]
        );
    }

    public function update(<UserProvider> user, <Model> model) -> bool
    {
        return this->acl->isAllowed(
            user->getRole(),
            get_class(model),
            "update",
            [
                user,
                model
            ]
        );
    }

    public function create(<UserProvider> user, <Model> model) -> bool
    {
        return this->acl->isAllowed(
            user->getRole(),
            get_class(model),
            "create",
            [
                user,
                model
            ]
        );
    }
}