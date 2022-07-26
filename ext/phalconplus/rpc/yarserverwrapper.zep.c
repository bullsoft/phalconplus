
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_YarServerWrapper)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc, YarServerWrapper, phalconplus, rpc_yarserverwrapper, phalconplus_rpc_abstractyar_ce, phalconplus_rpc_yarserverwrapper_method_entry, 0);

	zend_declare_property_null(phalconplus_rpc_yarserverwrapper_ce, SL("yar"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Rpc_YarServerWrapper, setServer)
{
	zval _2;
	zend_class_entry *_1 = NULL;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *obj, obj_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&obj_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(obj, zephir_get_internal_ce(SL("phalconplus\\rpc\\server\\abstractserver")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);


	ZEPHIR_INIT_VAR(&_0);
	if (!_1) {
	_1 = zephir_fetch_class_str_ex(SL("Yar_Server"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_0, _1);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, obj);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("yar"), &_0);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	zephir_array_update_string(&_2, SL("backendSrv"), obj, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermodules", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_Rpc_YarServerWrapper, handle)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("yar"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "You need set a server before handler request", "phalconplus/Rpc/YarServerWrapper.zep", 25);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("yar"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "handle", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

