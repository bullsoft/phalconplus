
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_Facade) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Enum, Facade, phalconplus, enum_facade, phalconplus_enum_abstractenum_ce, phalconplus_enum_facade_method_entry, 0);

	zend_declare_property_null(phalconplus_enum_facade_ce, SL("facades"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	zend_declare_property_string(phalconplus_enum_facade_ce, SL("classPrefix"), "PhalconPlus\\Facades\\", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_bool(phalconplus_enum_facade_ce, SL("loaded"), 0, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("ANNO"), "Annotations");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("ASSETS"), "Assets");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("CONFIG"), "Config");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("COOKIES"), "Cookies");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("CRYPT"), "Crypt");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("ESCAPER"), "Escaper");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("EVENT_MGR"), "EventsManager");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("FILTER"), "Filter");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("FLASH"), "Flash");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("APP_MODULE"), "AppModule");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("APP_ENGINE"), "AppEngine");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("DISPATCHER"), "Dispatcher");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("FLASH_SESSION"), "FlashSession");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("MODELS_CACHE"), "ModelsCache");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("MODELS_MGR"), "ModelsManager");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("MODELS_METADATA"), "ModelsMetadata");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("SESSION_BAG"), "SessionBag");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("SESSION"), "Session");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("REQUEST"), "Request");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("RESPONSE"), "Response");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("ROUTER"), "Router");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("SECURITY"), "Security");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("SERVICE"), "Service");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("TX_MGR"), "TransactionManager");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("REDIS"), "Redis");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("TAG"), "Tag");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("LOG"), "Log");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("URL"), "Url");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("ACL"), "Acl");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("APP"), "App");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("DI"), "Di");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("VIEW"), "View");

	zephir_declare_class_constant_string(phalconplus_enum_facade_ce, SL("USER"), "User");

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Enum_Facade, register) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval prefix, className, classAlias;
	zval *superApp, superApp_sub, *prefix_param = NULL, __$true, _0, alias, facades, *_2, _3, _4$$4, _5$$4, _6$$4, _7$$5, _8$$5, _9$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&superApp_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&facades);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&classAlias);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &superApp, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
		zephir_get_strval(&prefix, prefix_param);
	}


	zephir_read_static_property_ce(&_0, phalconplus_enum_facade_ce, SL("loaded"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_facades_abstractfacade_ce, "setapp", &_1, 0, superApp);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&facades, "validvalues", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&facades, 0, "phalconplus/Enum/Facade.zep", 76);
	if (Z_TYPE_P(&facades) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&facades), _2)
		{
			ZEPHIR_INIT_NVAR(&alias);
			ZVAL_COPY(&alias, _2);
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_read_static_property_ce(&_4$$4, phalconplus_enum_facade_ce, SL("classPrefix"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(&_5$$4);
			ZEPHIR_CONCAT_VV(&_5$$4, &_4$$4, &alias);
			zephir_get_strval(&className, &_5$$4);
			ZEPHIR_INIT_NVAR(&_6$$4);
			ZEPHIR_CONCAT_VV(&_6$$4, &prefix, &alias);
			zephir_get_strval(&classAlias, &_6$$4);
			
                zend_class_entry *ce;
                ce = zephir_fetch_class(&className TSRMLS_CC);
                zend_register_class_alias_ex(Z_STRVAL(classAlias), Z_STRLEN(classAlias), ce);
            
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &facades, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &facades, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&alias, &facades, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_7$$5);
				zephir_read_static_property_ce(&_7$$5, phalconplus_enum_facade_ce, SL("classPrefix"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZEPHIR_CONCAT_VV(&_8$$5, &_7$$5, &alias);
				zephir_get_strval(&className, &_8$$5);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZEPHIR_CONCAT_VV(&_9$$5, &prefix, &alias);
				zephir_get_strval(&classAlias, &_9$$5);
				
                zend_class_entry *ce;
                ce = zephir_fetch_class(&className TSRMLS_CC);
                zend_register_class_alias_ex(Z_STRVAL(classAlias), Z_STRLEN(classAlias), ce);
            
			ZEPHIR_CALL_METHOD(NULL, &facades, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&alias);
	zephir_update_static_property_ce(phalconplus_enum_facade_ce, ZEND_STRL("loaded"), &__$true);
	RETURN_MM_BOOL(1);

}

void zephir_init_static_properties_PhalconPlus_Enum_Facade(TSRMLS_D) {

	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 37, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Annotations");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Assets");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Config");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Cookies");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "View");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Crypt");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Dispatcher");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Escaper");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "EventsManager");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Filter");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Flash");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "FlashSession");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Log");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ModelsCache");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ModelsManager");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ModelsMetadata");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Request");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Response");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Router");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Security");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Service");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Session");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "SessionBag");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Tag");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "TransactionManager");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Url");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Acl");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "App");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Di");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "AppEngine");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Redis");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "User");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "AppModule");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_static_property_ce(phalconplus_enum_facade_ce, ZEND_STRL("facades"), &_0);
	ZEPHIR_MM_RESTORE();

}

