namespace PhalconPlus\Facades;
use Phalcon\Acl\Adapter\Memory as AclList;
use Phalcon\Di;

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
            \Phalcon\Acl::DENY
        );
        di->setShared(this->getName(), acl);
        return null;
    }
}