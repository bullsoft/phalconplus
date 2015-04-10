namespace PhalconPlus\Base;

class ProtoBuffer implements \JsonSerializable
{
    public function softClone(array data)
    {
        var key, val;
        for key, val in data {
            if property_exists(this, key) {
                let this->{key} = val;
            }
        }
    }

    public function __set(string! key, val)
    {
        var method, param, paramClass, paramObj;
        let method = "set" . key->upperfirst();
        if method_exists(this, method) {
            let param = new \ReflectionParameter([this, method], 0);
            if param->getClass() {
                let paramClass = param->getClass()->getName();
                let paramObj = new {paramClass}();
                paramObj->softClone(val);
                let val = paramObj;
            }
            this->{method}(val);
        }
        // hard code
        let this->{key} = val;
    }

    public function __get(string! key)
    {
        var method;
        let method = "set" . key->upperfirst();

        if method_exists(this, method) {
            return this->{method}();
        }

        if property_exists(this, key) {
            return this->{key};
        }

        return null;
    }

    protected function getSelfVars() -> array
    {
        var objReflection = null;
        var vars = [], pros = [], pro = null;
        
        let objReflection = new \ReflectionObject(this);
        let pros = objReflection->getProperties();

        for pro in pros {
            pro->setAccessible(true);
            let vars[pro->getName()] = pro->getValue(this);
        }
        return vars;
    }

    public function jsonSerialize()
    {
        return this->toArray();
    }

    public function toArray()
    {
        var pros = [];
        let pros = this->getSelfVars();
        /*
          array_walk_recursive(pros, function(&property, key){
            if is_object(property) {
                let property = property->toArray();
            } 
        });
        */
        return pros;
    }
}
