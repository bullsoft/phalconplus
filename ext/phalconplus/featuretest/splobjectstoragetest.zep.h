
extern zend_class_entry *phalconplus_featuretest_splobjectstoragetest_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_FeatureTest_SplObjectStorageTest);

PHP_METHOD(PhalconPlus_FeatureTest_SplObjectStorageTest, __construct);
PHP_METHOD(PhalconPlus_FeatureTest_SplObjectStorageTest, insert);
PHP_METHOD(PhalconPlus_FeatureTest_SplObjectStorageTest, exec);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_featuretest_splobjectstoragetest___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_featuretest_splobjectstoragetest_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_OBJ_INFO(0, obj, stdClass, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_featuretest_splobjectstoragetest_exec, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_featuretest_splobjectstoragetest_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_FeatureTest_SplObjectStorageTest, __construct, arginfo_phalconplus_featuretest_splobjectstoragetest___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(PhalconPlus_FeatureTest_SplObjectStorageTest, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
	PHP_ME(PhalconPlus_FeatureTest_SplObjectStorageTest, insert, arginfo_phalconplus_featuretest_splobjectstoragetest_insert, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_FeatureTest_SplObjectStorageTest, exec, arginfo_phalconplus_featuretest_splobjectstoragetest_exec, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_FeatureTest_SplObjectStorageTest, exec, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
