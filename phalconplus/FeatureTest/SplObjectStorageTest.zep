namespace PhalconPlus\FeatureTest;

class SplObjectStorageTest
{
    protected objects;

    public function __construct()
    {
        let this->objects = new \SplObjectStorage();
    }

    public function insert(var name, <\stdClass> obj, array data = [])
    {    
        this->objects->detach(obj);
        this->objects->attach(obj, [
            "name" : name, 
            "method" : "insert",
            "initial_data": data
        ]);
    }

    public function exec()
    {
        var obj, info;
        this->objects->rewind();
        while this->objects->valid() {
            let obj = this->objects->current();
            let info = this->objects->getInfo();
            echo "Key: " . this->objects->key() . " Name: " . info["name"] . " Obj: " . get_class(obj) . PHP_EOL;
            this->objects->next();
        }
    }
}