namespace PhalconPlus\Base;

class Service
{
    protected di;
    
    final public function __construct(<\Phalcon\DI> di)
    {
        let this->di = di;
        this->onConstruct();
    }

    protected function onConstruct() {}
    
    protected function getDI() -> <\Phalcon\DI>
    {
        return this->di;
    }

    protected function __get(string! key)
    {
        if property_exists(this, key) {
            return this->{key};
        } else {
            return this->di->get(key);
        }
    }
}
