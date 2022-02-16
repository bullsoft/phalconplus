
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_Cli)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App\\Engine, Cli, phalconplus, app_engine_cli, phalconplus_app_engine_abstractengine_ce, phalconplus_app_engine_cli_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_App_Engine_Cli, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *appModule, appModule_sub, *handler = NULL, handler_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&appModule_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(appModule, phalconplus_app_module_abstractmodule_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(handler, zephir_get_internal_ce(SL("phalcon\\application\\abstractapplication")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &appModule, &handler);
	if (!handler) {
		handler = &handler_sub;
		ZEPHIR_CPY_WRT(handler, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(handler);
	}


	if (Z_TYPE_P(handler) == IS_NULL) {
		ZEPHIR_INIT_NVAR(handler);
		object_init_ex(handler, zephir_get_internal_ce(SL("phalcon\\cli\\console")));
		ZEPHIR_CALL_METHOD(NULL, handler, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, phalconplus_app_engine_cli_ce, getThis(), "__construct", &_0, 0, appModule, handler);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_App_Engine_Cli, exec)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *di = NULL, di_sub, __$null, _0;
	zval argv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argv);
	ZVAL_UNDEF(&di_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(argv)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(di, zephir_get_internal_ce(SL("phalcon\\di\\diinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &argv_param, &di);
	zephir_get_arrval(&argv, argv_param);
	if (!di) {
		di = &di_sub;
		di = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "handle", NULL, 0, &argv);
	zephir_check_call_status();
	RETURN_MM();
}

