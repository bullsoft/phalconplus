namespace PhalconPlus\Db\Pdo;

class Mysql extends AbstractMysql
{
    public function __construct(array! descriptor, boolean autoConnect = true)
    {
        if autoConnect {
            this->connect(descriptor);
        } else {
            %{
            zephir_unset_property(this_ptr, "pdo");
            }%
        }

        // ------------------------------------------------------ //
        // start coping from \Phalcon\Db\Adapter::__construct
        // ------------------------------------------------------ //

        var dialectClass, connectionId;

        let connectionId = self::connectionConsecutive,
            this->_connectionId = connectionId,
            self::connectionConsecutive = connectionId + 1;

        /**
         * Dialect class can override the default dialect
         */
        if !fetch dialectClass, descriptor["dialectClass"] {
            let dialectClass = "phalcon\\db\\dialect\\" . this->dialectType;
        }

        /**
         * Create the instance only if the dialect is a string
         */
        if typeof dialectClass == "string" {
            let this->dialect = new {dialectClass}();
        } else {
            if typeof dialectClass == "object" {
                let this->dialect = dialectClass;
            }
        }
        let this->_descriptor = descriptor;
        
        // ------------------------------------------------------ //
        // end coping
        // ------------------------------------------------------ //
    }

    public function __get(string! prop)
    {
        if prop == "pdo" {
            %{
            add_property_null_ex(this_ptr, SL("pdo") TSRMLS_CC);
            }%
            this->connect(this->descriptor);
            return this->pdo;
        }
        return null;
    }

    public function isUnderTransaction() -> boolean
    {
        string prop = "pdo";
        int isPdoSet = 0;
        /* 
         * Used to check if a property of the object exists 
         * https://wiki.php.net/internals/engine/objects#the_handler_table
         *
         * param has_set_exists:
         * 0 (has) whether property exists and is not NULL
         * 1 (set) whether property exists and is true
         * 2 (exists) whether property exists
         */
        %{
        isPdoSet = Z_OBJ_HT_P(this_ptr)->has_property(this_ptr, &prop, 0, NULL);
        // isPdoSet = zephir_isset_property(this_ptr, SL("pdo"));
        }%

        if(isPdoSet == 0) {
            return false;
        }

        return parent::isUnderTransaction();
    }

}