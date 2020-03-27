namespace PhalconPlus\Base;

final class SimpleResponse extends AbstractResponse
{
    /**
     * @var array
     */
    private result = [];

    public function softClone(array data, boolean deep = false) -> <ProtoBuffer>
    {
        var key, val;
        for key, val in data {
            this->__set(key, val);
        }
        return this;
    }

    protected function getSelfVars() -> array
    {
        return (array) this->result;
    }

    public function getResult() -> array
    {
        return (array) this->result;
    }

    public function setResult(array result = []) -> <SimpleResponse>
    {
        let this->result = result;
        return this;
    }

    public function setItem(var val, var key = null) -> <SimpleResponse>
    {
        if !is_null(key) {
            let this->result[key] = val;
        } else {
            array_push(this->result, val);
        }
        return this;
    }

    public function getItem(var key = null)
    {
        if !is_null(key) {
            if isset this->result[key] {
                return this->result[key];
            }
        } else {
            return reset(this->result);
        }
        return null;
    }

    public function hasItem(var key) 
    {
        if isset this->result[key] {
            return true;
        } else {
            return false;
        }
    }

    public function __set(string! key, val)
    {
        let this->result[key] = val;   
    }

    public function __isset(string! key)
    {    
        if isset this->result[key] {
            return true;
        }
        return false;
    }

    public function __get(string! key)
    {
        if isset this->result[key] {
            return this->result[key];
        }
        return null;
    }

    public function __unset(string! key) -> void
    {
        if isset this->result[key] {
            unset(this->result[key]);
        }
    }

    public function isEmpty() -> boolean
    {
        return empty(this->result);
    }
}
