
extern zend_class_entry *phalconplus_base_protoorderby_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_ProtoOrderBy);

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getProperty);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setProperty);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setDirection);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getDirection);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getAlias);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setAlias);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protoorderby_setproperty, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protoorderby_setdirection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, orderBy, PhalconPlus\\Enum\\OrderByDirection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protoorderby_setalias, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_protoorderby_method_entry) {
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, getProperty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, setProperty, arginfo_phalconplus_base_protoorderby_setproperty, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, setDirection, arginfo_phalconplus_base_protoorderby_setdirection, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, getDirection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, getAlias, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, setAlias, arginfo_phalconplus_base_protoorderby_setalias, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
