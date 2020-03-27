namespace PhalconPlus\Assert;

class InvalidArgumentException extends \InvalidArgumentException implements AssertionFailedException
{
    private propertyPath;
    private value;
    private constraints;

    public function __construct(message, code, propertyPath = null, value, array constraints = [])
    {
        // if is_callable(message) {
        //     let message = (string) {message}(value, propertyPath, constraints);
        // }
        parent::__construct(message, code);
        let this->propertyPath = propertyPath;
        let this->value = value;
        let this->constraints = constraints;
    }

    public function getPropertyPath()
    {
        return this->propertyPath;
    }

    public function getValue()
    {
        return this->value;
    }

    public function getConstraints()
    {
        return this->constraints;
    }
}
