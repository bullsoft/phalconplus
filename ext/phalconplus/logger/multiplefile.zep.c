
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_MultiPleFile) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger, MultiPleFile, phalconplus, logger_multiplefile, zephir_get_internal_ce(SL("phalcon\\logger\\multiple")), phalconplus_logger_multiplefile_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_multiplefile_ce, SL("processors"), ZEND_ACC_PROTECTED);

	phalconplus_logger_multiplefile_ce->create_object = zephir_init_properties_PhalconPlus_Logger_MultiPleFile;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_MultiPleFile, getProcessors) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "processors");

}

PHP_METHOD(PhalconPlus_Logger_MultiPleFile, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, opt, logger, *_0, _1, _2$$3, _4$$3, _7$$4, _8$$4;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&opt);
	ZVAL_UNDEF(&logger);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	zephir_is_iterable(&options, 0, "phalconplus/Logger/MultipleFile.zep", 16);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&options), _0)
		{
			ZEPHIR_INIT_NVAR(&opt);
			ZVAL_COPY(&opt, _0);
			ZEPHIR_INIT_NVAR(&logger);
			object_init_ex(&logger, zephir_get_internal_ce(SL("phalcon\\logger\\adapter\\file")));
			zephir_array_fetch_string(&_2$$3, &opt, SL("filePath"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 12);
			ZEPHIR_CALL_METHOD(NULL, &logger, "__construct", &_3, 0, &_2$$3);
			zephir_check_call_status();
			zephir_array_fetch_string(&_4$$3, &opt, SL("level"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 13);
			ZEPHIR_CALL_METHOD(NULL, &logger, "setloglevel", &_5, 0, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "push", &_6, 0, &logger);
			zephir_check_call_status();
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
				ZEPHIR_INIT_NVAR(&logger);
				object_init_ex(&logger, zephir_get_internal_ce(SL("phalcon\\logger\\adapter\\file")));
				zephir_array_fetch_string(&_7$$4, &opt, SL("filePath"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 12);
				ZEPHIR_CALL_METHOD(NULL, &logger, "__construct", &_3, 0, &_7$$4);
				zephir_check_call_status();
				zephir_array_fetch_string(&_8$$4, &opt, SL("level"), PH_NOISY | PH_READONLY, "phalconplus/Logger/MultipleFile.zep", 13);
				ZEPHIR_CALL_METHOD(NULL, &logger, "setloglevel", &_5, 0, &_8$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "push", &_6, 0, &logger);
				zephir_check_call_status();
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


	zephir_read_property(&_0, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
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
	zval *type, type_sub, *message = NULL, message_sub, *context_param = NULL, __$null, loggers, logger, name, processor, custormContext, _0$$3, _1$$4, *_2$$4, _3$$4, _6$$5, _7$$6, *_8$$8, _9$$8, _10$$9, _11$$9, _12$$12, _13$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&loggers);
	ZVAL_UNDEF(&logger);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&processor);
	ZVAL_UNDEF(&custormContext);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
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


	ZEPHIR_INIT_VAR(&custormContext);
	array_init(&custormContext);
	if (ZEPHIR_IS_EMPTY(&context)) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property(&_0$$3, this_ptr, SL("processors"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(&_0$$3))) {
			zephir_read_property(&_1$$4, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
			zephir_is_iterable(&_1$$4, 0, "phalconplus/Logger/MultipleFile.zep", 50);
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
	ZEPHIR_OBS_VAR(&loggers);
	zephir_read_property(&loggers, this_ptr, SL("_loggers"), PH_NOISY_CC);
	if (Z_TYPE_P(&loggers) == IS_ARRAY) {
		zephir_is_iterable(&loggers, 0, "phalconplus/Logger/MultipleFile.zep", 65);
		if (Z_TYPE_P(&loggers) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&loggers), _8$$8)
			{
				ZEPHIR_INIT_NVAR(&logger);
				ZVAL_COPY(&logger, _8$$8);
				ZEPHIR_CALL_METHOD(&_10$$9, &logger, "getloglevel", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_10$$9, 9)) {
					ZEPHIR_CALL_METHOD(NULL, &logger, "log", NULL, 0, type, message, &custormContext);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_11$$9, &logger, "getloglevel", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&_11$$9, type)) {
					ZEPHIR_CALL_METHOD(NULL, &logger, "log", NULL, 0, type, message, &custormContext);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &loggers, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_9$$8, &loggers, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&logger, &loggers, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_12$$12, &logger, "getloglevel", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_12$$12, 9)) {
						ZEPHIR_CALL_METHOD(NULL, &logger, "log", NULL, 0, type, message, &custormContext);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_13$$12, &logger, "getloglevel", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_IDENTICAL(&_13$$12, type)) {
						ZEPHIR_CALL_METHOD(NULL, &logger, "log", NULL, 0, type, message, &custormContext);
						zephir_check_call_status();
					}
				ZEPHIR_CALL_METHOD(NULL, &loggers, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&logger);
	}
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
		zephir_read_property(&_0, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("processors"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

