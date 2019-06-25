namespace PhalconPlus\Db\Pdo;

class Mysql extends AbstractMysql
{
    protected _isConnected = false;

    public function __construct(array! descriptor, boolean autoConnect = true)
    {
        if autoConnect {
            this->connect(descriptor);
            let this->_isConnected = true;
        } else {
            %{
                zephir_unset_property(this_ptr, "_pdo");
            }%
        }

        // ------------------------------------------------------ //
        // start coping from \Phalcon\Db\Adapter::__construct

        var dialectClass, connectionId;

		let connectionId = self::_connectionConsecutive,
			this->_connectionId = connectionId,
			self::_connectionConsecutive = connectionId + 1;

		/**
		 * Dialect class can override the default dialect
		 */
		if !fetch dialectClass, descriptor["dialectClass"] {
			let dialectClass = "phalcon\\db\\dialect\\" . this->_dialectType;
		}

		/**
		 * Create the instance only if the dialect is a string
		 */
		if typeof dialectClass == "string" {
			let this->_dialect = new {dialectClass}();
		} else {
			if typeof dialectClass == "object" {
				let this->_dialect = dialectClass;
			}
		}
        let this->_descriptor = descriptor;

        // end coping
        // ------------------------------------------------------ //
    }

    public function __get(string! prop)
    {
        if prop == "_pdo" {
            %{
                add_property_null_ex(this_ptr, SL("_pdo") TSRMLS_CC);
            }%
            this->connect(this->_descriptor);
            let this->_isConnected = true;
            return this->_pdo;
        }
        return null;
    }

    public function isUnderTransaction() -> boolean
	{
        if this->_isConnected {
            return parent::isUnderTransaction();
        }
		return false;
    }
    
    public function close() -> boolean
    {
        let this->_isConnected = false;
        return parent::close();
    }
}