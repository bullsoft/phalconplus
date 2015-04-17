namespace PhalconPlus\Base;

class SimpleRequest extends ProtoBuffer
{
    private params = [];

    public function getParam(idx)
    {
        var val;
        if fetch val, this->params[idx] {
            return val;
        }
    }

    public function setParams(array params)
    {
        let this->params = params;
    }

    public function setParam(var val)
    {
        array_push(this->params, val);
    }
}
