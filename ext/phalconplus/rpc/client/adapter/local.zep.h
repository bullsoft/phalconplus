
extern zend_class_entry *phalconplus_rpc_client_adapter_local_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Client_Adapter_Local);

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Local, __construct);
PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Local, callByParams);
PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Local, callByObject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_local___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_rpc_client_adapter_local_callbyparams, 0, 3, PhalconPlus\\Base\\ProtoBuffer, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_client_adapter_local_callbyparams, 0, 3, IS_OBJECT, "PhalconPlus\\Base\\ProtoBuffer", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, service, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, service)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_OBJ_INFO(0, request, PhalconPlus\\Base\\ProtoBuffer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_local_callbyobject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rawData, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_client_adapter_local_method_entry) {
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Local, __construct, arginfo_phalconplus_rpc_client_adapter_local___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Local, callByParams, arginfo_phalconplus_rpc_client_adapter_local_callbyparams, ZEND_ACC_PRIVATE)
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Local, callByObject, arginfo_phalconplus_rpc_client_adapter_local_callbyobject, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
