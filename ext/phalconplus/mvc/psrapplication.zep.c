
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Mvc_PsrApplication)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Mvc, PsrApplication, phalconplus, mvc_psrapplication, zephir_get_internal_ce(SL("phalcon\\application\\abstractapplication")), phalconplus_mvc_psrapplication_method_entry, 0);

	zend_declare_property_null(phalconplus_mvc_psrapplication_ce, SL("app"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(di, zephir_get_internal_ce(SL("phalcon\\di\\diinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);


	ZEPHIR_CALL_PARENT(NULL, phalconplus_mvc_psrapplication_ce, getThis(), "__construct", NULL, 0, di);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("phalcon\\mvc\\application")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, di);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("app"), &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_METHOD(&_2, &_1, "sendcookiesonhandlerequest", NULL, 0, &_3);
	zephir_check_call_status();
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_METHOD(NULL, &_2, "sendheadersonhandlerequest", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, handle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool psr;
	zval *request, request_sub, *psr_param = NULL, _0, nativeRequest, nativeResponse, reqUri, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&nativeRequest);
	ZVAL_UNDEF(&nativeResponse);
	ZVAL_UNDEF(&reqUri);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("psrext\\http\\message\\serverrequestinterface")))
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(psr)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &psr_param);
	if (!psr_param) {
		psr = 0;
	} else {
		psr = zephir_get_boolval(psr_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "There is no di(dependency injector) in PsrAppliction", "phalconplus/Mvc/PsrApplication.zep", 32);
		return;
	}
	ZEPHIR_INIT_VAR(&nativeRequest);
	object_init_ex(&nativeRequest, phalconplus_http_nonpsrrequest_ce);
	ZEPHIR_CALL_METHOD(NULL, &nativeRequest, "__construct", NULL, 151, request);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "request");
	ZEPHIR_CALL_METHOD(NULL, &_1, "setshared", NULL, 0, &_2, &nativeRequest);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&reqUri, &_3, "getpath", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "handle", NULL, 0, &reqUri);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&nativeResponse, &_5);
	if (psr == 1) {
		ZEPHIR_RETURN_CALL_CE_STATIC(phalconplus_http_psrresponsefactory_ce, "create", &_6, 0, &nativeResponse);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&nativeResponse);
}

/**
 * Sets the events manager
 */
PHP_METHOD(PhalconPlus_Mvc_PsrApplication, setEventsManager)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, eventsManager_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, zephir_get_internal_ce(SL("phalcon\\events\\managerinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventsManager);


	ZEPHIR_CALL_PARENT(NULL, phalconplus_mvc_psrapplication_ce, getThis(), "seteventsmanager", NULL, 0, eventsManager);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "seteventsmanager", NULL, 0, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

