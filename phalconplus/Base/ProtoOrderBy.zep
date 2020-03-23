namespace PhalconPlus\Base;
use PhalconPlus\Assert\Assertion as Assert;
use PhalconPlus\Enum\OrderByDirection;

class ProtoOrderBy extends ProtoBuffer
{
    /**
     * @required
     */
    protected property;

    /**
     * @required
     */
    protected direction;

    /**
     * @optional
     */
    protected alias = "";

    public function getProperty() -> string
    {
        return this->property;
    }

    public function setProperty(string! property) -> <ProtoOrderBy>
    {
        let this->property = property;
        return this;
    }

    public function setDirection(<OrderByDirection> orderBy) -> <ProtoOrderBy>
    {
        let this->direction = orderBy;
        return this;
    }

    public function setAlias(string! alias) -> <ProtoOrderBy>
    {
        let this->alias = alias;
        return this;
    }

    public function getDirection() -> <OrderByDirection>
    {
        return this->direction;
    }

    public function getAlias() -> string
    {
        return this->alias;
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