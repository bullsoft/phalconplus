
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Db_Pdo_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Db\\Pdo, Mysql, phalconplus, db_pdo_mysql, phalconplus_db_pdo_abstractmysql_ce, phalconplus_db_pdo_mysql_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_Pdo_Mysql, __construct) {

	zend_class_entry *_4$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool autoConnect;
	zval *descriptor_param = NULL, *autoConnect_param = NULL, dialectClass, connectionId, _0, _1$$5, _2$$6, _3$$6;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&dialectClass);
	ZVAL_UNDEF(&connectionId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &descriptor_param, &autoConnect_param);

	ZEPHIR_OBS_COPY_OR_DUP(&descriptor, descriptor_param);
	if (!autoConnect_param) {
		autoConnect = 1;
	} else {
		autoConnect = zephir_get_boolval(autoConnect_param);
	}


	if (autoConnect) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0, &descriptor);
		zephir_check_call_status();
	} else {
		
            zephir_unset_property(this_ptr, "pdo");
            
	}
	ZEPHIR_OBS_VAR(&connectionId);
	zephir_read_static_property_ce(&connectionId, phalconplus_db_pdo_mysql_ce, SL("connectionConsecutive"), PH_NOISY_CC);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_connectionId"), &connectionId);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(&connectionId) + 1));
	zephir_update_static_property_ce(phalconplus_db_pdo_mysql_ce, ZEND_STRL("connectionConsecutive"), &_0);
	ZEPHIR_OBS_VAR(&dialectClass);
	if (!(zephir_array_isset_string_fetch(&dialectClass, &descriptor, SL("dialectClass"), 0))) {
		zephir_read_property(&_1$$5, this_ptr, ZEND_STRL("dialectType"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&dialectClass);
		ZEPHIR_CONCAT_SV(&dialectClass, "phalcon\\db\\dialect\\", &_1$$5);
	}
	if (Z_TYPE_P(&dialectClass) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2$$6);
		zephir_fetch_safe_class(&_3$$6, &dialectClass);
		_4$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$6), Z_STRLEN_P(&_3$$6), ZEND_FETCH_CLASS_AUTO);
		if(!_4$$6) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_2$$6, _4$$6);
		if (zephir_has_constructor(&_2$$6)) {
			ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("dialect"), &_2$$6);
	} else {
		if (Z_TYPE_P(&dialectClass) == IS_OBJECT) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("dialect"), &dialectClass);
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("_descriptor"), &descriptor);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_Pdo_Mysql, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prop_param = NULL, _0$$3;
	zval prop;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prop);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prop_param);

	if (UNEXPECTED(Z_TYPE_P(prop_param) != IS_STRING && Z_TYPE_P(prop_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prop' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prop_param) == IS_STRING)) {
		zephir_get_strval(&prop, prop_param);
	} else {
		ZEPHIR_INIT_VAR(&prop);
		ZVAL_EMPTY_STRING(&prop);
	}


	if (ZEPHIR_IS_STRING(&prop, "pdo")) {
		
            add_property_null_ex(this_ptr, SL("pdo") TSRMLS_CC);
            
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("descriptor"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM_MEMBER(getThis(), "pdo");
	}
	RETURN_MM_NULL();

}

PHP_METHOD(PhalconPlus_Db_Pdo_Mysql, isUnderTransaction) {

	zval prop;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, isPdoSet;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prop);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&prop);
	ZVAL_STRING(&prop, "pdo");
	isPdoSet = 0;
	
        isPdoSet = Z_OBJ_HT_P(this_ptr)->has_property(this_ptr, &prop, 0, NULL);
        // isPdoSet = zephir_isset_property(this_ptr, SL("pdo"));
        
	if (isPdoSet == 0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_PARENT(phalconplus_db_pdo_mysql_ce, getThis(), "isundertransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

