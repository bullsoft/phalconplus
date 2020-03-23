namespace PhalconPlus\Base;
use PhalconPlus\Base\ProtoBuffer;

final class SimpleRequest extends AbstractRequest
{
    /**
     * @var array
     */
    private params = [];

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
        return this->params;
    }

    public function getParam(var idx, var defaultValue = null)
    {
        var val;
        if fetch val, this->params[idx] {
            return val;
        }
        return defaultValue;
    }

    public function hasParam(var idx)
    {
        if isset this->params[idx] {
            return true;
        } else {
            return false;
        }
    }

    public function setParams(array params) -> <SimpleRequest>
    {
        let this->params = params;
        return this;
    }

    public function setParam(var val, var key = null) -> <SimpleRequest>
    {
        if !is_null(key) {
            let this->params[key] = val;
        } else {
            array_push(this->params, val);
        }
        return this;
    }

    public function getParams() -> array
    {
        return this->params;
    }

    public function __set(string! key, val)
    {
        let this->params[key] = val;
    }

    public function __isset(string! key)
    {
        if isset this->params[key] {
            return true;
        }
        return false;
    }

    public function __get(string! key)
    {
        if isset this->params[key] {
            return this->params[key];
        }
        return null;
    }

    public function __unset(string! key) -> void
    {
        if isset this->params[key] {
            unset(this->params[key]);
        }
    }

    public function isEmpty() -> boolean
    {
        return empty(this->params);
    }
}
