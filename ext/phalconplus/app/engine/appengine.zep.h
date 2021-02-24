
extern zend_class_entry *phalconplus_app_engine_appengine_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_AppEngine);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_engine_appengine_gethandler, 0, 0, Phalcon\\Application\\AbstractApplication, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_engine_appengine_gethandler, 0, 0, IS_OBJECT, "Phalcon\\Application\\AbstractApplication", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_engine_appengine_sethandler, 0, 1, PhalconPlus\\App\\Engine\\AbstractEngine, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_engine_appengine_sethandler, 0, 1, IS_OBJECT, "PhalconPlus\\App\\Engine\\AbstractEngine", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, handler, Phalcon\\Application\\AbstractApplication, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_engine_appengine_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_App_Engine_AppEngine, getHandler, arginfo_phalconplus_app_engine_appengine_gethandler)
	PHP_ABSTRACT_ME(PhalconPlus_App_Engine_AppEngine, setHandler, arginfo_phalconplus_app_engine_appengine_sethandler)
	PHP_FE_END
};
