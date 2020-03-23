
extern zend_class_entry *phalconplus_base_protobuffer_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_ProtoBuffer);

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __construct);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, softClone);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __set);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __isset);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __get);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __unset);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, isSetGet);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, getSelfVars);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, jsonSerialize);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, toArray);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, offsetSet);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, offsetExists);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, offsetUnset);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, offsetGet);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, count);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, isEmpty);
PHP_METHOD(PhalconPlus_Base_ProtoBuffer, getIterator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_protobuffer_softclone, 0, 1, PhalconPlus\\Base\\ProtoBuffer, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_softclone, 0, 1, IS_OBJECT, "PhalconPlus\\Base\\ProtoBuffer", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, deep, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, deep)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer___set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer___isset, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer___unset, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer___unset, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer___unset, 0, 0, 1)
#define arginfo_phalconplus_base_protobuffer___unset NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer_issetget, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_getselfvars, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_getselfvars, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_toarray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_toarray, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, inputPros, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_offsetset, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_offsetset, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer_offsetset, 0, 0, 2)
#define arginfo_phalconplus_base_protobuffer_offsetset NULL
#endif

	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_offsetexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_offsetexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_offsetunset, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_offsetunset, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer_offsetunset, 0, 0, 1)
#define arginfo_phalconplus_base_protobuffer_offsetunset NULL
#endif

	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protobuffer_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_count, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_isempty, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_isempty, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_protobuffer_getiterator, 0, 0, RecursiveArrayIterator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protobuffer_getiterator, 0, 0, IS_OBJECT, "RecursiveArrayIterator", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_protobuffer_method_entry) {
	PHP_ME(PhalconPlus_Base_ProtoBuffer, __construct, arginfo_phalconplus_base_protobuffer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, softClone, arginfo_phalconplus_base_protobuffer_softclone, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, __set, arginfo_phalconplus_base_protobuffer___set, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, __isset, arginfo_phalconplus_base_protobuffer___isset, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, __get, arginfo_phalconplus_base_protobuffer___get, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, __unset, arginfo_phalconplus_base_protobuffer___unset, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, isSetGet, arginfo_phalconplus_base_protobuffer_issetget, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, getSelfVars, arginfo_phalconplus_base_protobuffer_getselfvars, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, toArray, arginfo_phalconplus_base_protobuffer_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, offsetSet, arginfo_phalconplus_base_protobuffer_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, offsetExists, arginfo_phalconplus_base_protobuffer_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, offsetUnset, arginfo_phalconplus_base_protobuffer_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, offsetGet, arginfo_phalconplus_base_protobuffer_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, count, arginfo_phalconplus_base_protobuffer_count, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, isEmpty, arginfo_phalconplus_base_protobuffer_isempty, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoBuffer, getIterator, arginfo_phalconplus_base_protobuffer_getiterator, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
