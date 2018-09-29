namespace PhalconPlus\Base;

class Service
{
    /**
     * @var <\Phalcon\DI>
     */
    protected di = null;

    final public function __construct(<\Phalcon\DI> di)
    {
        let this->di = di;
        ob_start();
        this->onConstruct();
        ob_end_clean();
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
