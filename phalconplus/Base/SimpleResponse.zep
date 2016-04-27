namespace PhalconPlus\Base;

final class SimpleResponse extends Response
{
    private result = [];
    
    public function getResult()
    {
        return this->result;
    }

    public function setResult(array result)
    {
        let this->result = result;
        return this;
    }

    public function pushItem(var val)
    {
        array_push(this->result, val);
        return this;
    }

    public function popItem()
    {
        return array_pop(this->result);
    }
}