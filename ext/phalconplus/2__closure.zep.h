
extern zend_class_entry *phalconplus_2__closure_ce;

ZEPHIR_INIT_CLASS(phalconplus_2__closure);

PHP_METHOD(phalconplus_2__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_2__closure___invoke, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, iterator, Iterator, 0)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_2__closure_method_entry) {
	PHP_ME(phalconplus_2__closure, __invoke, arginfo_phalconplus_2__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
