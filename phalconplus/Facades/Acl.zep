namespace PhalconPlus\Facades;
use Phalcon\Acl\Adapter\Memory as AclList;
use Phalcon\Di\Di;
use Phalcon\Acl\Enum as AclEnum;

class Acl extends AbstractFacade
{
    protected function getName() -> string
    {
        return "acl";
    }

    protected function resolve(<Di> di) -> null | <Di>
    {
        var acl;
        let acl = new AclList();
        acl->setDefaultAction(
            AclEnum::DENY
        );
        di->setShared(this->getName(), acl);
        return null;
    }
}