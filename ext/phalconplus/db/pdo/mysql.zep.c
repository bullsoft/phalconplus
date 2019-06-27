
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

	zend_declare_property_bool(phalconplus_db_pdo_mysql_ce, SL("_isConnected"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_Pdo_Mysql, __construct) {

	zend_class_entry *_4$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool autoConnect;
	zval *descriptor_param = NULL, *autoConnect_param = NULL, __$true, __$false, dialectClass, connectionId, _0, _1$$5, _2$$6, _3$$6;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
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
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_isConnected"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_isConnected"), &__$false);
		}
	} else {
		
                zephir_unset_property(this_ptr, "_pdo");
            
	}
	ZEPHIR_OBS_VAR(&connectionId);
	zephir_read_static_property_ce(&connectionId, phalconplus_db_pdo_mysql_ce, SL("_connectionConsecutive"), PH_NOISY_CC);
	zephir_update_property_zval(this_ptr, SL("_connectionId"), &connectionId);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(&connectionId) + 1));
	zend_update_static_property(phalconplus_db_pdo_mysql_ce, ZEND_STRL("_connectionConsecutive"), &_0);
	ZEPHIR_OBS_VAR(&dialectClass);
	if (!(zephir_array_isset_string_fetch(&dialectClass, &descriptor, SL("dialectClass"), 0))) {
		zephir_read_property(&_1$$5, this_ptr, SL("_dialectType"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&dialectClass);
		ZEPHIR_CONCAT_SV(&dialectClass, "phalcon\\db\\dialect\\", &_1$$5);
	}
	if (Z_TYPE_P(&dialectClass) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2$$6);
		zephir_fetch_safe_class(&_3$$6, &dialectClass);
		_4$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$6), Z_STRLEN_P(&_3$$6), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_2$$6, _4$$6);
		if (zephir_has_constructor(&_2$$6 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("_dialect"), &_2$$6);
	} else {
		if (Z_TYPE_P(&dialectClass) == IS_OBJECT) {
			zephir_update_property_zval(this_ptr, SL("_dialect"), &dialectClass);
		}
	}
	zephir_update_property_zval(this_ptr, SL("_descriptor"), &descriptor);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_Pdo_Mysql, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prop_param = NULL, __$true, __$false, _0$$3;
	zval prop;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prop);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prop_param);

	if (UNEXPECTED(Z_TYPE_P(prop_param) != IS_STRING && Z_TYPE_P(prop_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prop' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prop_param) == IS_STRING)) {
		zephir_get_strval(&prop, prop_param);
	} else {
		ZEPHIR_INIT_VAR(&prop);
		ZVAL_EMPTY_STRING(&prop);
	}


	if (ZEPHIR_IS_STRING(&prop, "_pdo")) {
		
                add_property_null_ex(this_ptr, SL("_pdo") TSRMLS_CC);
            
		zephir_read_property(&_0$$3, this_ptr, SL("_descriptor"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0, &_0$$3);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_isConnected"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_isConnected"), &__$false);
		}
		RETURN_MM_MEMBER(getThis(), "_pdo");
	}
	RETURN_MM_NULL();

}

PHP_METHOD(PhalconPlus_Db_Pdo_Mysql, isUnderTransaction) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_isConnected"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_PARENT(phalconplus_db_pdo_mysql_ce, getThis(), "isundertransaction", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Db_Pdo_Mysql, close) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	ZEPHIR_MM_GROW();

	if (0) {
		zephir_update_property_zval(this_ptr, SL("_isConnected"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_isConnected"), &__$false);
	}
	ZEPHIR_RETURN_CALL_PARENT(phalconplus_db_pdo_mysql_ce, getThis(), "close", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

