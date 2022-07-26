namespace PhalconPlus\Base;
use Phalcon\Di\Di;

class Service
{
    /**
     * @var <Di>
     */
    protected di = null;

    final public function __construct(<Di> di)
    {
        let this->di = di;
        ob_start();
        this->onConstruct();
        ob_end_clean();
    }

    protected function onConstruct() {}

    protected function getDI() -> <Di>
    {
        return this->di;
    }

    public function __get(string! key)
    {
        if property_exists(this, key) {
            return this->{key};
        } else {
            return this->di->get(key);
        }
    }
}
