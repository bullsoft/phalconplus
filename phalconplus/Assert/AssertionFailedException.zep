namespace PhalconPlus\Assert;

interface AssertionFailedException
{
    public function __construct(message, code, propertyPath = null, value, array constraints = []);
    public function getPropertyPath();
    public function getValue();
    public function getConstraints();
}