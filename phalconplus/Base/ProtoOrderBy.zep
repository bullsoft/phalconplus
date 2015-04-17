namespace PhalconPlus\Base;
use PhalconPlus\Assert\Assertion as Assert;

class ProtoOrderBy extends ProtoBuffer
{
    /**
     * @required
     */
    private property;

    /**
     * @required
     */
    private direction;

    /**
     * @optional
     */
    private alias = "";

    public function getProperty()
    {
        return this->property;
    }

    public function setProperty(string! property)
    {
        let this->property = property;
    }

    public function setDirection(<\PhalconPlus\Enum\OrderByDirection> orderBy)
    {
        let this->direction = orderBy;
    }

    public function getDirection()
    {
        return this->direction;
    }

    public function getAlias()
    {
        return this->alias;
    }

    public function setAlias(string! alias)
    {
        let this->alias = alias;
    }

    public function __toString()
    {
        Assert::notEmpty(this->property);
        Assert::notEmpty(this->direction);
        var orderBy = "";
        if !empty this->alias {
            let orderBy = orderBy . this->alias . ".";
        }
        return orderBy . this->property . " " . this->direction;
    }
}