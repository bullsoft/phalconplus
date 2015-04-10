namespace PhalconPlus\Base;

// use Phalcon\Mvc\Model;
// use Phalcon\Mvc\ModelMessage;
// use Phalcon\Db\RawValue;

class Model extends \Phalcon\Mvc\Model
{
    // 记录创建时间
    public ctime;
    // 记录更新时间
    public mtime;

    public function initialize()
    {
        self::setUp([
            "notNullValidations" : false
        ]);
        this->useDynamicUpdate(true);
        this->keepSnapshots(true);
    }

    public function getMessage()
    {
        return this->getFirstMessage();
    }

    public function getFirstMessage()
    {
        if count(this->getMessages("")) {
            return (string) current(this->getMessages(""));
        }
        return false;
    }

    public function getLastMessage()
    {
        if count(this->getMessages("")) {
            return (string) end(this->getMessages(""));
        }
        return false;
    }

    public function createBuilder(string! alias = "") -> <\Phalcon\Mvc\Model\Query\BuilderInterface>
    {
        var source;
        if !empty alias {
            let source = [alias:get_called_class()];
        } else {
            let source  = get_called_class();
        }
        return this->getModelsManager()->createBuilder()->from(source);
    }

    public static function getInstance() -> <\Phalcon\Mvc\Model>
    {
        var className;
        let className = get_called_class();
        return new {className}();
    }

    public function beforeValidationOnCreate()
    {
        let this->ctime = date("Y-m-d H:i:s");
        let this->mtime = this->ctime;
    }

    public function afterFetch()
    {
        // nothing
    }

    public function beforeSave()
    {
        let this->mtime = date("Y-m-d H:i:s");
        return true;
    }
}
