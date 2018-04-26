
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Adapter_FilePlus) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger\\Adapter, FilePlus, phalconplus, logger_adapter_fileplus, zephir_get_internal_ce(SL("phalcon\\logger\\adapter\\file")), phalconplus_logger_adapter_fileplus_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("type2Handler"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("type2Ext"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("mode"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("_path"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("_options"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_logger_adapter_fileplus_ce, SL("_fileHandler"), ZEND_ACC_PRIVATE TSRMLS_CC);

	phalconplus_logger_adapter_fileplus_ce->create_object = zephir_init_properties_PhalconPlus_Logger_Adapter_FilePlus;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval options;
	zval *filePath_param = NULL, *options_param = NULL, mode, _4, _5, _6, _7, _8, _1$$3, _2$$3, _3$$6;
	zval filePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &options_param);

	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(&filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(&filePath);
		ZVAL_EMPTY_STRING(&filePath);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notempty", &_0, 0, &filePath);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&mode);
	if (zephir_array_isset_string_fetch(&mode, &options, SL("mode"), 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "r");
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_fast_strpos(&_2$$3, &mode, &_1$$3, 0 );
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			zephir_update_property_zval(this_ptr, SL("mode"), &mode);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Logger must be opened in append or write mode", "phalconplus/Logger/Adapter/FilePlus.zep", 25);
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_3$$6);
		ZEPHIR_INIT_NVAR(&_3$$6);
		ZVAL_STRING(&_3$$6, "ab");
		zephir_update_property_zval(this_ptr, SL("mode"), &_3$$6);
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "open", NULL, 52, &filePath);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_fileHandler"), &_4);
	zephir_update_property_zval(this_ptr, SL("_path"), &filePath);
	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	zephir_read_property(&_5, this_ptr, SL("_fileHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_LONG(&_6, -1);
	zephir_update_property_array(this_ptr, SL("type2Handler"), &_6, &_5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_LONG(&_7, -1);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "");
	zephir_update_property_array(this_ptr, SL("type2Ext"), &_7, &_8 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, open) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, handler, _0, _1$$3;
	zval filePath, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(&filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(&filePath);
		ZVAL_EMPTY_STRING(&filePath);
	}


	ZEPHIR_INIT_VAR(&handler);
	ZVAL_NULL(&handler);
	zephir_read_property(&_0, this_ptr, SL("mode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&handler, "fopen", NULL, 53, &filePath, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(&handler)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Cannot open log file ", &filePath);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Logger/Adapter/FilePlus.zep", 45 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&handler);

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, log) {

	zend_bool _0, _1$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *type, type_sub, *message = NULL, message_sub, *context_param = NULL, __$null, handler, toggledType, _2, _3$$9, _4$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&toggledType);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &type, &message, &context_param);

	if (!message) {
		message = &message_sub;
		message = &__$null;
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&context, context_param);
	}


	_0 = Z_TYPE_P(type) == IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(message) == IS_LONG;
	}
	if (_0) {
		ZEPHIR_CPY_WRT(&toggledType, message);
	} else {
		_1$$4 = Z_TYPE_P(type) == IS_STRING;
		if (_1$$4) {
			_1$$4 = Z_TYPE_P(message) == IS_NULL;
		}
		if (_1$$4) {
			ZEPHIR_CPY_WRT(&toggledType, message);
		} else {
			ZEPHIR_CPY_WRT(&toggledType, type);
		}
	}
	if (Z_TYPE_P(&toggledType) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&toggledType);
		ZVAL_LONG(&toggledType, 7);
	}
	ZEPHIR_OBS_VAR(&handler);
	zephir_read_property(&_2, this_ptr, SL("type2Handler"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&handler, &_2, &toggledType, 0 TSRMLS_CC)) {
		zephir_update_property_zval(this_ptr, SL("_fileHandler"), &handler);
	} else {
		zephir_read_property(&_3$$9, this_ptr, SL("type2Handler"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_4$$9, &_3$$9, -1, PH_NOISY | PH_READONLY, "phalconplus/Logger/Adapter/FilePlus.zep", 72 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_fileHandler"), &_4$$9);
	}
	ZEPHIR_RETURN_CALL_PARENT(phalconplus_logger_adapter_fileplus_ce, getThis(), "log", NULL, 0, type, message, &context);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, registerExtension) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval types;
	zval *ext_param = NULL, *types_param = NULL, filePath, type, fileHandler, _1, *_2;
	zval ext;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&fileHandler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&types);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &types_param);

	if (UNEXPECTED(Z_TYPE_P(ext_param) != IS_STRING && Z_TYPE_P(ext_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ext' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(ext_param) == IS_STRING)) {
		zephir_get_strval(&ext, ext_param);
	} else {
		ZEPHIR_INIT_VAR(&ext);
		ZVAL_EMPTY_STRING(&ext);
	}
	zephir_get_arrval(&types, types_param);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notempty", &_0, 0, &ext);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notempty", &_0, 0, &types);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&filePath);
	ZEPHIR_CONCAT_VV(&filePath, &_1, &ext);
	ZEPHIR_CALL_METHOD(&fileHandler, this_ptr, "open", NULL, 52, &filePath);
	zephir_check_call_status();
	zephir_is_iterable(&types, 0, "phalconplus/Logger/Adapter/FilePlus.zep", 104);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&types), _2)
	{
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_COPY(&type, _2);
		zephir_update_property_array(this_ptr, SL("type2Handler"), &type, &fileHandler TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("type2Ext"), &type, &ext TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&type);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, close) {

	zend_string *_3;
	zend_ulong _2;
	zval type, handler, _0, *_1, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("type2Handler"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalconplus/Logger/Adapter/FilePlus.zep", 113);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&type);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&type, _3);
		} else {
			ZVAL_LONG(&type, _2);
		}
		ZEPHIR_INIT_NVAR(&handler);
		ZVAL_COPY(&handler, _1);
		zephir_fclose(&handler TSRMLS_CC);
		zephir_read_property(&_4$$3, this_ptr, SL("type2Handler"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_4$$3, &type, PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&handler);
	ZEPHIR_INIT_NVAR(&type);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, getProcessorVar) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, processor, _2, _3, _0$$3;
	zval key, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&processor);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}



	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getformatter", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&processor, &_0$$3, "getprocessor", NULL, 0, &key);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_get_strval(&_1$$3, &processor);
		RETURN_CTOR(&_1$$3);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_OBJ(&_2, EG(exception));
		Z_ADDREF_P(&_2);
		ZEPHIR_INIT_VAR(&_3);
		if (zephir_instance_of_ev(&_2, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_3, &_2);
		}
	}
	RETURN_MM_STRING("undefined");

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, __destruct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "close", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, __wakeup) {

	zend_string *_3;
	zend_ulong _2;
	zval type, ext, handler, ext2Handler, _0, *_1, _7, _8, _4$$4, _5$$4;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&ext2Handler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&ext2Handler);
	array_init(&ext2Handler);
	zephir_read_property(&_0, this_ptr, SL("type2Ext"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalconplus/Logger/Adapter/FilePlus.zep", 143);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&type);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&type, _3);
		} else {
			ZVAL_LONG(&type, _2);
		}
		ZEPHIR_INIT_NVAR(&ext);
		ZVAL_COPY(&ext, _1);
		ZEPHIR_OBS_NVAR(&handler);
		if (zephir_array_isset_string_fetch(&handler, &ext2Handler, SL("ext"), 0)) {
		} else {
			zephir_read_property(&_4$$4, this_ptr, SL("_path"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_VV(&_5$$4, &_4$$4, &ext);
			ZEPHIR_CALL_METHOD(&handler, this_ptr, "open", &_6, 52, &_5$$4);
			zephir_check_call_status();
			zephir_array_update_zval(&ext2Handler, &ext, &handler, PH_COPY | PH_SEPARATE);
		}
		zephir_update_property_array(this_ptr, SL("type2Handler"), &type, &handler TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&ext);
	ZEPHIR_INIT_NVAR(&type);
	zephir_read_property(&_7, this_ptr, SL("type2Handler"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_8, &_7, -1, PH_NOISY | PH_READONLY, "phalconplus/Logger/Adapter/FilePlus.zep", 143 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_fileHandler"), &_8);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_PhalconPlus_Logger_Adapter_FilePlus(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("type2Ext"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("type2Ext"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("type2Handler"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("type2Handler"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

