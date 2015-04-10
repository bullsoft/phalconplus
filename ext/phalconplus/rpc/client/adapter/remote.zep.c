
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(PhalconPlus_RPC_Client_Adapter_Remote) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\RPC\\Client\\Adapter, Remote, phalconplus, rpc_client_adapter_remote, phalconplus_rpc_client_abstractclient_ce, phalconplus_rpc_client_adapter_remote_method_entry, 0);

	zend_declare_property_null(phalconplus_rpc_client_adapter_remote_ce, SL("remoteServerUrl"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_client_adapter_remote_ce, SL("client"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *remoteServerUrl_param = NULL, *key = NULL, *_1, *_2, *_3;
	zval *remoteServerUrl = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &remoteServerUrl_param);

	zephir_get_arrval(remoteServerUrl, remoteServerUrl_param);


	if (ZEPHIR_IS_EMPTY(remoteServerUrl)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "server url can not be empty", "phalconplus/RPC/Client/Adapter/Remote.zep", 12);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&key, "array_rand", &_0, remoteServerUrl);
	zephir_check_call_status();
	zephir_array_fetch(&_1, remoteServerUrl, key, PH_NOISY | PH_READONLY, "phalconplus/RPC/Client/Adapter/Remote.zep", 16 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("remoteServerUrl"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, zephir_get_internal_ce(SS("yar_client") TSRMLS_CC));
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("remoteServerUrl"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("client"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, callByObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, *_0;
	zval *rawData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(rawData, rawData_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "callbyobject", NULL, rawData);
	zephir_check_call_status();
	RETURN_MM();

}

