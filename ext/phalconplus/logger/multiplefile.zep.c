
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_MultiPleFile) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger, MultiPleFile, phalconplus, logger_multiplefile, zephir_get_internal_ce(SL("phalcon\\logger")), phalconplus_logger_multiplefile_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_multiplefile_ce, SL("processors"), ZEND_ACC_PROTECTED);

	phalconplus_logger_multiplefile_ce->create_object = zephir_init_properties_PhalconPlus_Logger_MultiPleFile;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_MultiPleFile, getProcessors) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "processors");

}

/**
 *  options = [
 *       "level" => Phalcon\Logger::INFO,
 *       "adapters" => [
 *          [
 *               "name" => "local",
 *               "filePath" => "/path/to/logger/file.log",
 *          ],
 *          [
 *               "name" => "local",
 *               "filePath" => "/path/to/logger/file.log",
 *          ],
 *       ]
 */
PHP_METHOD(PhalconPlus_Logger_MultiPleFile, __construct) {

	zval _14$$10, _17$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i$$9;
	zval *options_param = NULL, opt, logger, level, _0$$5, _1$$6, *_2$$6, _3$$6, _4$$7, _6$$7, _8$$8, _9$$8, *_10$$9, _11$$9, _12$$10, _13$$10, _15$$11, _16$$11;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&opt);
	ZVAL_UNDEF(&logger);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_17$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	if (ZEPHIR_IS_EMPTY(&options)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Logger config can not empty", "phalconplus/Logger/MultipleFile.zep", 26);
		return;
	}
	if (zephir_array_isset_string(&options, SL("level"))) {
		ZEPHIR_OBS_VAR(&level);
		zephir_array_fetch_string(&level, &options, SL("level"), PH_NOISY, "phalconplus/Logger/MultipleFile.zep", 32);
	} else {
		zephir_array_fetch_long(&_0$$5, &options, 0, PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 34);
		ZEPHIR_OBS_NVAR(&level);
		zephir_array_fetch_string(&level, &_0$$5, SL("level"), PH_NOISY, "phalconplus/Logger/MultipleFile.zep", 34);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setloglevel", NULL, 0, &level);
	zephir_check_call_status();
	if (zephir_array_isset_string(&options, SL("adapters"))) {
		zephir_array_fetch_string(&_1$$6, &options, SL("adapters"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 40);
		zephir_is_iterable(&_1$$6, 0, "phalconplus/Logger/MultipleFile.zep", 44);
		if (Z_TYPE_P(&_1$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$6), _2$$6)
			{
				ZEPHIR_INIT_NVAR(&opt);
				ZVAL_COPY(&opt, _2$$6);
				ZEPHIR_INIT_NVAR(&logger);
				object_init_ex(&logger, zephir_get_internal_ce(SL("phalcon\\logger\\adapter\\stream")));
				zephir_array_fetch_string(&_4$$7, &opt, SL("filePath"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 41);
				ZEPHIR_CALL_METHOD(NULL, &logger, "__construct", &_5, 0, &_4$$7);
				zephir_check_call_status();
				zephir_array_fetch_string(&_6$$7, &opt, SL("name"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 42);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addadapter", &_7, 0, &_6$$7, &logger);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_1$$6, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$6, &_1$$6, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&opt, &_1$$6, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&logger);
					object_init_ex(&logger, zephir_get_internal_ce(SL("phalcon\\logger\\adapter\\stream")));
					zephir_array_fetch_string(&_8$$8, &opt, SL("filePath"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 41);
					ZEPHIR_CALL_METHOD(NULL, &logger, "__construct", &_5, 0, &_8$$8);
					zephir_check_call_status();
					zephir_array_fetch_string(&_9$$8, &opt, SL("name"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 42);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addadapter", &_7, 0, &_9$$8, &logger);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_1$$6, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&opt);
	} else {
		i$$9 = 1;
		zephir_is_iterable(&options, 0, "phalconplus/Logger/MultipleFile.zep", 51);
		if (Z_TYPE_P(&options) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&options), _10$$9)
			{
				ZEPHIR_INIT_NVAR(&opt);
				ZVAL_COPY(&opt, _10$$9);
				ZEPHIR_INIT_NVAR(&logger);
				object_init_ex(&logger, zephir_get_internal_ce(SL("phalcon\\logger\\adapter\\stream")));
				zephir_array_fetch_string(&_12$$10, &opt, SL("filePath"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 47);
				ZEPHIR_CALL_METHOD(NULL, &logger, "__construct", &_5, 0, &_12$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_LONG(&_13$$10, i$$9);
				ZEPHIR_INIT_NVAR(&_14$$10);
				ZEPHIR_CONCAT_SV(&_14$$10, "message", &_13$$10);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addadapter", &_7, 0, &_14$$10, &logger);
				zephir_check_call_status();
				i$$9 = (i$$9 + 1);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_11$$9, &options, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_11$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&opt, &options, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&logger);
					object_init_ex(&logger, zephir_get_internal_ce(SL("phalcon\\logger\\adapter\\stream")));
					zephir_array_fetch_string(&_15$$11, &opt, SL("filePath"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 47);
					ZEPHIR_CALL_METHOD(NULL, &logger, "__construct", &_5, 0, &_15$$11);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_16$$11);
					ZVAL_LONG(&_16$$11, i$$9);
					ZEPHIR_INIT_NVAR(&_17$$11);
					ZEPHIR_CONCAT_SV(&_17$$11, "message", &_16$$11);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addadapter", &_7, 0, &_17$$11, &logger);
					zephir_check_call_status();
					i$$9 = (i$$9 + 1);
				ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&opt);
	}
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
	RETURN_MM_STRING("");

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

/**
 * Sends a message to each registered logger
 */
PHP_METHOD(PhalconPlus_Logger_MultiPleFile, log) {

	zend_string *_5$$4;
	zend_ulong _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *level, level_sub, *message, message_sub, *context_param = NULL, name, processor, custormContext, _0$$3, _1$$4, *_2$$4, _3$$4, _6$$5, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&processor);
	ZVAL_UNDEF(&custormContext);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level, &message, &context_param);

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
			zephir_is_iterable(&_1$$4, 0, "phalconplus/Logger/MultipleFile.zep", 86);
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
	ZEPHIR_CALL_PARENT(NULL, phalconplus_logger_multiplefile_ce, getThis(), "log", NULL, 0, level, message, &custormContext);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_PhalconPlus_Logger_MultiPleFile(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("processors"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("processors"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

