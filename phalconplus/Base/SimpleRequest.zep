namespace PhalconPlus\Base;

final class SimpleRequest extends AbstractRequest
{
    /**
     * @var array
     */
    private params = [];

    public function softClone(array data)
    {
        var key, val;
        for key, val in data {
            if property_exists(this, key) {
                this->__set(key, val);
            } else {
                let this->params[key] = val;
            }
        }
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

    public function setParams(array params) -> <\PhalconPlus\Base\SimpleRequest>
    {
        let this->params = params;
        return this;
    }

    public function setParam(var val, var key = null) -> <\PhalconPlus\Base\SimpleRequest>
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
}
