
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_Handler_Task) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App\\Handler, Task, phalconplus, app_handler_task, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalconplus_app_handler_task_method_entry, 0);

	zend_declare_property_null(phalconplus_app_handler_task_ce, SL("app"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_handler_task_ce, SL("handler"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalconplus_app_handler_task_ce, SL("autoHandle"), 1, ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_App_Handler_Task, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool autoHandle;
	zval *app, app_sub, *autoHandle_param = NULL, __$true, __$false, di, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &app, &autoHandle_param);

	if (!autoHandle_param) {
		autoHandle = 1;
	} else {
		autoHandle = zephir_get_boolval(autoHandle_param);
	}


	if (autoHandle) {
		zephir_update_property_zval(this_ptr, SL("autoHandle"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("autoHandle"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("app"), app);
	ZEPHIR_CALL_METHOD(&di, app, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("phalcon\\cli\\console")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("handler"), &_0);
	zephir_read_property(&_1, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setdi", NULL, 0, &di);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "eventsManager");
	ZEPHIR_CALL_METHOD(&_3, &di, "get", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "seteventsmanager", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_App_Handler_Task, exec) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *di = NULL, di_sub, __$null, _0, _1;
	zval argv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argv);
	ZVAL_UNDEF(&di_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &argv_param, &di);

	zephir_get_arrval(&argv, argv_param);
	if (!di) {
		di = &di_sub;
		di = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("autoHandle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_THIS();
	}
	zephir_read_property(&_1, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "handle", NULL, 0, &argv);
	zephir_check_call_status();
	RETURN_MM();

}

