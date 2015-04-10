namespace PhalconPlus\Base;

class Service
{
    private di;
    
    public function __construct(<\Phalcon\DI> di)
    {
        let this->di = di;
    }

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
