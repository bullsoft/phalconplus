
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_MultiPleFile) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger, MultiPleFile, phalconplus, logger_multiplefile, zephir_get_internal_ce(SL("phalcon\\logger")), phalconplus_logger_multiplefile_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_multiplefile_ce, SL("processors"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_logger_multiplefile_ce, SL("options"), ZEND_ACC_PROTECTED);

	phalconplus_logger_multiplefile_ce->create_object = zephir_init_properties_PhalconPlus_Logger_MultiPleFile;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_MultiPleFile, getProcessors) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "processors");

}

/**
 *  options = [
 *          [
 *               "name" => "local",
 *               "filePath" => "/path/to/logger/file.log",
 *               "level"  => \Phalcon\Logger::DEBUG,
 *          ],
 *          [
 *               "name" => "remote",
 *               "filePath" => "/path/to/logger/file.log",
 *               "level" => \Phalcon\Logger::CUSTOM，
 *          ],
 *  ]
 */
PHP_METHOD(PhalconPlus_Logger_MultiPleFile, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, __$true, opt, logger, level, name, dir, *_0, _1, _2$$4, _4$$4, _8$$4, _6$$5, _10$$6, _12$$8, _13$$8, _15$$8, _14$$9, _16$$10;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&opt);
	ZVAL_UNDEF(&logger);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	if (ZEPHIR_IS_EMPTY(&options)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Logger config can not be empty", "phalconplus/Logger/MultipleFile.zep", 30);
		return;
	}
	zephir_is_iterable(&options, 0, "phalconplus/Logger/MultipleFile.zep", 51);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&options), _0)
		{
			ZEPHIR_INIT_NVAR(&opt);
			ZVAL_COPY(&opt, _0);
			ZEPHIR_OBS_NVAR(&level);
			zephir_array_fetch_string(&level, &opt, SL("level"), PH_NOISY, "phalconplus/Logger/MultipleFile.zep", 36);
			zephir_update_property_array(this_ptr, SL("options"), &level, &opt);
			zephir_array_fetch_string(&_2$$4, &opt, SL("filePath"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 38);
			ZEPHIR_CALL_FUNCTION(&dir, "dirname", &_3, 121, &_2$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_4$$4, "is_dir", &_5, 52, &dir);
			zephir_check_call_status();
			if (!(zephir_is_true(&_4$$4))) {
				ZVAL_LONG(&_6$$5, 0777);
				ZEPHIR_CALL_FUNCTION(NULL, "mkdir", &_7, 142, &dir, &_6$$5, &__$true);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(&logger);
			object_init_ex(&logger, zephir_get_internal_ce(SL("phalcon\\logger\\adapter\\stream")));
			zephir_array_fetch_string(&_8$$4, &opt, SL("filePath"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 42);
			ZEPHIR_CALL_METHOD(NULL, &logger, "__construct", &_9, 0, &_8$$4);
			zephir_check_call_status();
			if (zephir_array_isset_string(&opt, SL("name"))) {
				zephir_array_fetch_string(&_10$$6, &opt, SL("name"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 44);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addadapter", &_11, 0, &_10$$6, &logger);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&name);
				ZEPHIR_CONCAT_SV(&name, "adapter#", &level);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addadapter", &_11, 0, &name, &logger);
				zephir_check_call_status();
				zephir_update_property_array_multi(this_ptr, SL("options"), &name, SL("zs"), 3, &level, SL("name"));
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&opt, &options, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&level);
				zephir_array_fetch_string(&level, &opt, SL("level"), PH_NOISY, "phalconplus/Logger/MultipleFile.zep", 36);
				zephir_update_property_array(this_ptr, SL("options"), &level, &opt);
				zephir_array_fetch_string(&_12$$8, &opt, SL("filePath"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 38);
				ZEPHIR_CALL_FUNCTION(&dir, "dirname", &_3, 121, &_12$$8);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_13$$8, "is_dir", &_5, 52, &dir);
				zephir_check_call_status();
				if (!(zephir_is_true(&_13$$8))) {
					ZVAL_LONG(&_14$$9, 0777);
					ZEPHIR_CALL_FUNCTION(NULL, "mkdir", &_7, 142, &dir, &_14$$9, &__$true);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(&logger);
				object_init_ex(&logger, zephir_get_internal_ce(SL("phalcon\\logger\\adapter\\stream")));
				zephir_array_fetch_string(&_15$$8, &opt, SL("filePath"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 42);
				ZEPHIR_CALL_METHOD(NULL, &logger, "__construct", &_9, 0, &_15$$8);
				zephir_check_call_status();
				if (zephir_array_isset_string(&opt, SL("name"))) {
					zephir_array_fetch_string(&_16$$10, &opt, SL("name"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 44);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addadapter", &_11, 0, &_16$$10, &logger);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&name);
					ZEPHIR_CONCAT_SV(&name, "adapter#", &level);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addadapter", &_11, 0, &name, &logger);
					zephir_check_call_status();
					zephir_update_property_array_multi(this_ptr, SL("options"), &name, SL("zs"), 3, &level, SL("name"));
				}
			ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&opt);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_MultiPleFile, addProcessor) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *processor, processor_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&processor_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &processor);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_array(this_ptr, SL("processors"), &name, processor);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Logger_MultiPleFile, getProcessorVar) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, processor, _0;
	zval name, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&processor);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("processors"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&processor, &_0, &name, 1)) {
		zephir_get_strval(&_1$$3, &processor);
		RETURN_CTOR(&_1$$3);
	}
	RETURN_MM_STRING("<empty>");

}

PHP_METHOD(PhalconPlus_Logger_MultiPleFile, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(&property, property_param);
	} else {
		ZEPHIR_INIT_VAR(&property);
		ZVAL_EMPTY_STRING(&property);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getprocessorvar", NULL, 0, &property);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Logger_MultiPleFile, addMessage) {

	zend_string *_5$$4;
	zend_ulong _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zval message;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, name, processor, custormContext, options, _8, _9, _10, _0$$3, _1$$4, *_2$$4, _3$$4, _6$$5, _7$$6;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&processor);
	ZVAL_UNDEF(&custormContext);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level_param, &message_param, &context_param);

	level = zephir_get_intval(level_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&custormContext);
	array_init(&custormContext);
	if (ZEPHIR_IS_EMPTY(&context)) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("processors"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(&_0$$3))) {
			zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("processors"), PH_NOISY_CC | PH_READONLY);
			zephir_is_iterable(&_1$$4, 0, "phalconplus/Logger/MultipleFile.zep", 81);
			if (Z_TYPE_P(&_1$$4) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$4), _4$$4, _5$$4, _2$$4)
				{
					ZEPHIR_INIT_NVAR(&name);
					if (_5$$4 != NULL) { 
						ZVAL_STR_COPY(&name, _5$$4);
					} else {
						ZVAL_LONG(&name, _4$$4);
					}
					ZEPHIR_INIT_NVAR(&processor);
					ZVAL_COPY(&processor, _2$$4);
					ZEPHIR_CALL_METHOD(&_6$$5, &processor, "__tostring", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&custormContext, &name, &_6$$5, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_1$$4, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_3$$4, &_1$$4, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&name, &_1$$4, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&processor, &_1$$4, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_7$$6, &processor, "__tostring", NULL, 0);
						zephir_check_call_status();
						zephir_array_update_zval(&custormContext, &name, &_7$$6, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &_1$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&processor);
			ZEPHIR_INIT_NVAR(&name);
		}
	} else {
		ZEPHIR_CPY_WRT(&custormContext, &context);
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_8);
	if (zephir_array_isset_long(&options, level)) {
		zephir_array_unset_long(&options, level, PH_SEPARATE);
	} else if (zephir_array_isset_long(&options, 8)) {
		zephir_array_unset_long(&options, 8, PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "name");
	ZEPHIR_CALL_FUNCTION(&_10, "array_column", NULL, 143, &options, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "excludeadapters", NULL, 0, &_10);
	zephir_check_call_status();
	ZVAL_LONG(&_8, level);
	ZEPHIR_RETURN_CALL_PARENT(phalconplus_logger_multiplefile_ce, getThis(), "addmessage", NULL, 0, &_8, &message, &custormContext);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Logger_MultiPleFile, setFormatter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *formatter, formatter_sub, adapter, _0, *_1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&formatter_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &formatter);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapters"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalconplus/Logger/MultipleFile.zep", 104);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&adapter);
			ZVAL_COPY(&adapter, _1);
			ZEPHIR_CALL_METHOD(NULL, &adapter, "setformatter", NULL, 0, formatter);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&adapter, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &adapter, "setformatter", NULL, 0, formatter);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&adapter);
	RETURN_THIS();

}

zend_object *zephir_init_properties_PhalconPlus_Logger_MultiPleFile(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("processors"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("processors"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

