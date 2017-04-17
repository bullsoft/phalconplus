
extern zend_class_entry *phalconplus_base_protobuffer_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_ProtoBuffer);

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, softClone);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __set);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __isset);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __get);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, getSelfVars);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, jsonSerialize);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, toArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer_softclone, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer_toarray, 0, 0, 0)
	ZEND_ARG_INFO(0, isArray)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_protobuffer_method_entry) {
	PHP_ME(PhalconPlus_Base_ProtoBuffer, softClone, arginfo_phalconplus_base_protobuffer_softclone, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, __set, arginfo_phalconplus_base_protobuffer___set, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, __isset, arginfo_phalconplus_base_protobuffer___isset, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, __get, arginfo_phalconplus_base_protobuffer___get, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, getSelfVars, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, toArray, arginfo_phalconplus_base_protobuffer_toarray, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
