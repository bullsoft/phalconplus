
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "phalconplus.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *phalconplus_contracts_arrayof_ce;
zend_class_entry *phalconplus_contracts_emptyornot_ce;
zend_class_entry *phalconplus_contracts_stringer_ce;
zend_class_entry *phalconplus_assert_assertionfailedexception_ce;
zend_class_entry *phalconplus_contracts_auth_access_modelevent_ce;
zend_class_entry *phalconplus_contracts_auth_policy_ce;
zend_class_entry *phalconplus_contracts_auth_userprovider_ce;
zend_class_entry *phalconplus_contracts_auth_access_authorizable_ce;
zend_class_entry *phalconplus_contracts_auth_access_dispatchevent_ce;
zend_class_entry *phalconplus_contracts_auth_access_resourceaware_ce;
zend_class_entry *phalconplus_contracts_auth_access_routerevent_ce;
zend_class_entry *phalconplus_contracts_dump_ce;
zend_class_entry *phalconplus_contracts_eventattachable_ce;
zend_class_entry *phalconplus_contracts_invoke_ce;
zend_class_entry *phalconplus_facades_abstractfacade_ce;
zend_class_entry *phalconplus_base_protobuffer_ce;
zend_class_entry *phalconplus_enum_abstractenum_ce;
zend_class_entry *phalconplus_app_engine_abstractengine_ce;
zend_class_entry *phalconplus_base_exception_ce;
zend_class_entry *phalconplus_logger_processor_abstractprocessor_ce;
zend_class_entry *phalconplus_rpc_client_abstractclient_ce;
zend_class_entry *phalconplus_db_unitofwork_abstractvalue_ce;
zend_class_entry *phalconplus_rpc_abstractservice_ce;
zend_class_entry *phalconplus_base_abstractrequest_ce;
zend_class_entry *phalconplus_base_abstractresponse_ce;
zend_class_entry *phalconplus_db_pdo_abstractmysql_ce;
zend_class_entry *phalconplus_rpc_server_abstractserver_ce;
zend_class_entry *phalconplus_0__closure_ce;
zend_class_entry *phalconplus_1__closure_ce;
zend_class_entry *phalconplus_2__closure_ce;
zend_class_entry *phalconplus_3__closure_ce;
zend_class_entry *phalconplus_app_app_ce;
zend_class_entry *phalconplus_app_engine_cli_ce;
zend_class_entry *phalconplus_app_engine_srv_ce;
zend_class_entry *phalconplus_app_engine_web_ce;
zend_class_entry *phalconplus_app_module_abstractmodule_ce;
zend_class_entry *phalconplus_app_module_moduledef_ce;
zend_class_entry *phalconplus_assert_assertion_ce;
zend_class_entry *phalconplus_assert_invalidargumentexception_ce;
zend_class_entry *phalconplus_auth_exception_ce;
zend_class_entry *phalconplus_auth_model_ce;
zend_class_entry *phalconplus_auth_policy_ce;
zend_class_entry *phalconplus_auth_userprovider_ce;
zend_class_entry *phalconplus_base_model_ce;
zend_class_entry *phalconplus_base_pagable_ce;
zend_class_entry *phalconplus_base_page_ce;
zend_class_entry *phalconplus_base_protoorderby_ce;
zend_class_entry *phalconplus_base_service_ce;
zend_class_entry *phalconplus_base_simplerequest_ce;
zend_class_entry *phalconplus_base_simpleresponse_ce;
zend_class_entry *phalconplus_bootstrap_ce;
zend_class_entry *phalconplus_curl_curl_ce;
zend_class_entry *phalconplus_curl_exception_ce;
zend_class_entry *phalconplus_curl_request_ce;
zend_class_entry *phalconplus_curl_response_ce;
zend_class_entry *phalconplus_db_mysql_ce;
zend_class_entry *phalconplus_db_pdo_mysql_ce;
zend_class_entry *phalconplus_db_unitofwork_ce;
zend_class_entry *phalconplus_db_unitofwork_field_ce;
zend_class_entry *phalconplus_db_unitofwork_lastinsertid_ce;
zend_class_entry *phalconplus_enum_assertioncode_ce;
zend_class_entry *phalconplus_enum_exception_ce;
zend_class_entry *phalconplus_enum_facade_ce;
zend_class_entry *phalconplus_enum_orderbydirection_ce;
zend_class_entry *phalconplus_enum_runenv_ce;
zend_class_entry *phalconplus_enum_runmode_ce;
zend_class_entry *phalconplus_enum_sys_ce;
zend_class_entry *phalconplus_facades_acl_ce;
zend_class_entry *phalconplus_facades_annotations_ce;
zend_class_entry *phalconplus_facades_app_ce;
zend_class_entry *phalconplus_facades_appengine_ce;
zend_class_entry *phalconplus_facades_appmodule_ce;
zend_class_entry *phalconplus_facades_assets_ce;
zend_class_entry *phalconplus_facades_config_ce;
zend_class_entry *phalconplus_facades_cookies_ce;
zend_class_entry *phalconplus_facades_crypt_ce;
zend_class_entry *phalconplus_facades_di_ce;
zend_class_entry *phalconplus_facades_dispatcher_ce;
zend_class_entry *phalconplus_facades_escaper_ce;
zend_class_entry *phalconplus_facades_eventsmanager_ce;
zend_class_entry *phalconplus_facades_filter_ce;
zend_class_entry *phalconplus_facades_flash_ce;
zend_class_entry *phalconplus_facades_flashsession_ce;
zend_class_entry *phalconplus_facades_log_ce;
zend_class_entry *phalconplus_facades_modelscache_ce;
zend_class_entry *phalconplus_facades_modelsmanager_ce;
zend_class_entry *phalconplus_facades_modelsmetadata_ce;
zend_class_entry *phalconplus_facades_redis_ce;
zend_class_entry *phalconplus_facades_request_ce;
zend_class_entry *phalconplus_facades_response_ce;
zend_class_entry *phalconplus_facades_router_ce;
zend_class_entry *phalconplus_facades_security_ce;
zend_class_entry *phalconplus_facades_service_ce;
zend_class_entry *phalconplus_facades_session_ce;
zend_class_entry *phalconplus_facades_sessionbag_ce;
zend_class_entry *phalconplus_facades_tag_ce;
zend_class_entry *phalconplus_facades_transactionmanager_ce;
zend_class_entry *phalconplus_facades_url_ce;
zend_class_entry *phalconplus_facades_user_ce;
zend_class_entry *phalconplus_facades_view_ce;
zend_class_entry *phalconplus_featuretest_splobjectstoragetest_ce;
zend_class_entry *phalconplus_helper_arr_ce;
zend_class_entry *phalconplus_helper_exception_ce;
zend_class_entry *phalconplus_helper_ns_ce;
zend_class_entry *phalconplus_helper_str_ce;
zend_class_entry *phalconplus_helper_variable_ce;
zend_class_entry *phalconplus_http_nonpsrrequest_ce;
zend_class_entry *phalconplus_http_nonpsrresponse_ce;
zend_class_entry *phalconplus_http_psrresponsefactory_ce;
zend_class_entry *phalconplus_logger_multiplefile_ce;
zend_class_entry *phalconplus_logger_processor_logid_ce;
zend_class_entry *phalconplus_logger_processor_msec_ce;
zend_class_entry *phalconplus_logger_processor_trace_ce;
zend_class_entry *phalconplus_mvc_psrapplication_ce;
zend_class_entry *phalconplus_rpc_client_adapter_local_ce;
zend_class_entry *phalconplus_rpc_client_adapter_simple_ce;
zend_class_entry *phalconplus_rpc_client_adapter_yar_ce;
zend_class_entry *phalconplus_rpc_server_simpleserver_ce;
zend_class_entry *phalconplus_rpc_simpleservice_ce;
zend_class_entry *phalconplus_rpc_yarservice_ce;
zend_class_entry *phalconplus_volt_extension_phpfunction_ce;

ZEND_DECLARE_MODULE_GLOBALS(phalconplus)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(phalconplus)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(PhalconPlus_Contracts_ArrayOf);
	ZEPHIR_INIT(PhalconPlus_Contracts_EmptyOrNot);
	ZEPHIR_INIT(PhalconPlus_Contracts_Stringer);
	ZEPHIR_INIT(PhalconPlus_Assert_AssertionFailedException);
	ZEPHIR_INIT(PhalconPlus_Contracts_Auth_Access_ModelEvent);
	ZEPHIR_INIT(PhalconPlus_Contracts_Auth_Policy);
	ZEPHIR_INIT(PhalconPlus_Contracts_Auth_UserProvider);
	ZEPHIR_INIT(PhalconPlus_Contracts_Auth_Access_Authorizable);
	ZEPHIR_INIT(PhalconPlus_Contracts_Auth_Access_DispatchEvent);
	ZEPHIR_INIT(PhalconPlus_Contracts_Auth_Access_ResourceAware);
	ZEPHIR_INIT(PhalconPlus_Contracts_Auth_Access_RouterEvent);
	ZEPHIR_INIT(PhalconPlus_Contracts_Dump);
	ZEPHIR_INIT(PhalconPlus_Contracts_EventAttachable);
	ZEPHIR_INIT(PhalconPlus_Contracts_Invoke);
	ZEPHIR_INIT(PhalconPlus_Facades_AbstractFacade);
	ZEPHIR_INIT(PhalconPlus_Base_ProtoBuffer);
	ZEPHIR_INIT(PhalconPlus_Enum_AbstractEnum);
	ZEPHIR_INIT(PhalconPlus_App_Engine_AbstractEngine);
	ZEPHIR_INIT(PhalconPlus_Base_Exception);
	ZEPHIR_INIT(PhalconPlus_Logger_Processor_AbstractProcessor);
	ZEPHIR_INIT(PhalconPlus_Rpc_Client_AbstractClient);
	ZEPHIR_INIT(PhalconPlus_Db_UnitOfWork_AbstractValue);
	ZEPHIR_INIT(PhalconPlus_Rpc_AbstractService);
	ZEPHIR_INIT(PhalconPlus_Base_AbstractRequest);
	ZEPHIR_INIT(PhalconPlus_Base_AbstractResponse);
	ZEPHIR_INIT(PhalconPlus_Db_Pdo_AbstractMysql);
	ZEPHIR_INIT(PhalconPlus_Rpc_Server_AbstractServer);
	ZEPHIR_INIT(PhalconPlus_App_App);
	ZEPHIR_INIT(PhalconPlus_App_Engine_Cli);
	ZEPHIR_INIT(PhalconPlus_App_Engine_Srv);
	ZEPHIR_INIT(PhalconPlus_App_Engine_Web);
	ZEPHIR_INIT(PhalconPlus_App_Module_AbstractModule);
	ZEPHIR_INIT(PhalconPlus_App_Module_ModuleDef);
	ZEPHIR_INIT(PhalconPlus_Assert_Assertion);
	ZEPHIR_INIT(PhalconPlus_Assert_InvalidArgumentException);
	ZEPHIR_INIT(PhalconPlus_Auth_Exception);
	ZEPHIR_INIT(PhalconPlus_Auth_Model);
	ZEPHIR_INIT(PhalconPlus_Auth_Policy);
	ZEPHIR_INIT(PhalconPlus_Auth_UserProvider);
	ZEPHIR_INIT(PhalconPlus_Base_Model);
	ZEPHIR_INIT(PhalconPlus_Base_Pagable);
	ZEPHIR_INIT(PhalconPlus_Base_Page);
	ZEPHIR_INIT(PhalconPlus_Base_ProtoOrderBy);
	ZEPHIR_INIT(PhalconPlus_Base_Service);
	ZEPHIR_INIT(PhalconPlus_Base_SimpleRequest);
	ZEPHIR_INIT(PhalconPlus_Base_SimpleResponse);
	ZEPHIR_INIT(PhalconPlus_Bootstrap);
	ZEPHIR_INIT(PhalconPlus_Curl_Curl);
	ZEPHIR_INIT(PhalconPlus_Curl_Exception);
	ZEPHIR_INIT(PhalconPlus_Curl_Request);
	ZEPHIR_INIT(PhalconPlus_Curl_Response);
	ZEPHIR_INIT(PhalconPlus_Db_Mysql);
	ZEPHIR_INIT(PhalconPlus_Db_Pdo_Mysql);
	ZEPHIR_INIT(PhalconPlus_Db_UnitOfWork);
	ZEPHIR_INIT(PhalconPlus_Db_UnitOfWork_Field);
	ZEPHIR_INIT(PhalconPlus_Db_UnitOfWork_LastInsertId);
	ZEPHIR_INIT(PhalconPlus_Enum_AssertionCode);
	ZEPHIR_INIT(PhalconPlus_Enum_Exception);
	ZEPHIR_INIT(PhalconPlus_Enum_Facade);
	ZEPHIR_INIT(PhalconPlus_Enum_OrderByDirection);
	ZEPHIR_INIT(PhalconPlus_Enum_RunEnv);
	ZEPHIR_INIT(PhalconPlus_Enum_RunMode);
	ZEPHIR_INIT(PhalconPlus_Enum_Sys);
	ZEPHIR_INIT(PhalconPlus_Facades_Acl);
	ZEPHIR_INIT(PhalconPlus_Facades_Annotations);
	ZEPHIR_INIT(PhalconPlus_Facades_App);
	ZEPHIR_INIT(PhalconPlus_Facades_AppEngine);
	ZEPHIR_INIT(PhalconPlus_Facades_AppModule);
	ZEPHIR_INIT(PhalconPlus_Facades_Assets);
	ZEPHIR_INIT(PhalconPlus_Facades_Config);
	ZEPHIR_INIT(PhalconPlus_Facades_Cookies);
	ZEPHIR_INIT(PhalconPlus_Facades_Crypt);
	ZEPHIR_INIT(PhalconPlus_Facades_Di);
	ZEPHIR_INIT(PhalconPlus_Facades_Dispatcher);
	ZEPHIR_INIT(PhalconPlus_Facades_Escaper);
	ZEPHIR_INIT(PhalconPlus_Facades_EventsManager);
	ZEPHIR_INIT(PhalconPlus_Facades_Filter);
	ZEPHIR_INIT(PhalconPlus_Facades_Flash);
	ZEPHIR_INIT(PhalconPlus_Facades_FlashSession);
	ZEPHIR_INIT(PhalconPlus_Facades_Log);
	ZEPHIR_INIT(PhalconPlus_Facades_ModelsCache);
	ZEPHIR_INIT(PhalconPlus_Facades_ModelsManager);
	ZEPHIR_INIT(PhalconPlus_Facades_ModelsMetadata);
	ZEPHIR_INIT(PhalconPlus_Facades_Redis);
	ZEPHIR_INIT(PhalconPlus_Facades_Request);
	ZEPHIR_INIT(PhalconPlus_Facades_Response);
	ZEPHIR_INIT(PhalconPlus_Facades_Router);
	ZEPHIR_INIT(PhalconPlus_Facades_Security);
	ZEPHIR_INIT(PhalconPlus_Facades_Service);
	ZEPHIR_INIT(PhalconPlus_Facades_Session);
	ZEPHIR_INIT(PhalconPlus_Facades_SessionBag);
	ZEPHIR_INIT(PhalconPlus_Facades_Tag);
	ZEPHIR_INIT(PhalconPlus_Facades_TransactionManager);
	ZEPHIR_INIT(PhalconPlus_Facades_Url);
	ZEPHIR_INIT(PhalconPlus_Facades_User);
	ZEPHIR_INIT(PhalconPlus_Facades_View);
	ZEPHIR_INIT(PhalconPlus_FeatureTest_SplObjectStorageTest);
	ZEPHIR_INIT(PhalconPlus_Helper_Arr);
	ZEPHIR_INIT(PhalconPlus_Helper_Exception);
	ZEPHIR_INIT(PhalconPlus_Helper_Ns);
	ZEPHIR_INIT(PhalconPlus_Helper_Str);
	ZEPHIR_INIT(PhalconPlus_Helper_Variable);
	ZEPHIR_INIT(PhalconPlus_Http_NonPsrRequest);
	ZEPHIR_INIT(PhalconPlus_Http_NonPsrResponse);
	ZEPHIR_INIT(PhalconPlus_Http_PsrResponseFactory);
	ZEPHIR_INIT(PhalconPlus_Logger_MultiPleFile);
	ZEPHIR_INIT(PhalconPlus_Logger_Processor_LogId);
	ZEPHIR_INIT(PhalconPlus_Logger_Processor_Msec);
	ZEPHIR_INIT(PhalconPlus_Logger_Processor_Trace);
	ZEPHIR_INIT(PhalconPlus_Mvc_PsrApplication);
	ZEPHIR_INIT(PhalconPlus_Rpc_Client_Adapter_Local);
	ZEPHIR_INIT(PhalconPlus_Rpc_Client_Adapter_Simple);
	ZEPHIR_INIT(PhalconPlus_Rpc_Client_Adapter_Yar);
	ZEPHIR_INIT(PhalconPlus_Rpc_Server_SimpleServer);
	ZEPHIR_INIT(PhalconPlus_Rpc_SimpleService);
	ZEPHIR_INIT(PhalconPlus_Rpc_YarService);
	ZEPHIR_INIT(PhalconPlus_Volt_Extension_PhpFunction);
	ZEPHIR_INIT(phalconplus_0__closure);
	ZEPHIR_INIT(phalconplus_1__closure);
	ZEPHIR_INIT(phalconplus_2__closure);
	ZEPHIR_INIT(phalconplus_3__closure);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(phalconplus)
{
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_phalconplus_globals *phalconplus_globals)
{
	phalconplus_globals->initialized = 0;

	/* Cache Enabled */
	phalconplus_globals->cache_enabled = 1;

	/* Recursive Lock */
	phalconplus_globals->recursive_lock = 0;

	/* Static cache */
	memset(phalconplus_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_phalconplus_globals *phalconplus_globals)
{
	
}

static PHP_RINIT_FUNCTION(phalconplus)
{
	zend_phalconplus_globals *phalconplus_globals_ptr;
	phalconplus_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(phalconplus_globals_ptr);
	zephir_initialize_memory(phalconplus_globals_ptr);

		zephir_init_static_properties_PhalconPlus_Curl_Request();
		zephir_init_static_properties_PhalconPlus_Enum_Facade();
		zephir_init_static_properties_PhalconPlus_Enum_Sys();
	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phalconplus)
{
	
	zephir_deinitialize_memory();
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(phalconplus)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PHALCONPLUS_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PHALCONPLUS_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PHALCONPLUS_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PHALCONPLUS_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PHALCONPLUS_ZEPVERSION);
	php_info_print_table_end();
		php_info_print_table_start();
	php_info_print_table_header(2, "Directive", "Value");
	php_info_print_table_row(2, "phalconplus.env", "Your environment, such as: dev, test, production etc.");
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(phalconplus)
{
#if defined(COMPILE_DL_PHALCONPLUS) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(phalconplus_globals);
	php_zephir_init_module_globals(phalconplus_globals);
}

static PHP_GSHUTDOWN_FUNCTION(phalconplus)
{
	
}


zend_function_entry php_phalconplus_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_phalconplus_deps[] = {
	ZEND_MOD_REQUIRED("phalcon")
	ZEND_MOD_REQUIRED("mbstring")
	ZEND_MOD_REQUIRED("psr")
	ZEND_MOD_END
};

zend_module_entry phalconplus_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_phalconplus_deps,
	PHP_PHALCONPLUS_EXTNAME,
	php_phalconplus_functions,
	PHP_MINIT(phalconplus),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(phalconplus),
#else
	NULL,
#endif
	PHP_RINIT(phalconplus),
	PHP_RSHUTDOWN(phalconplus),
	PHP_MINFO(phalconplus),
	PHP_PHALCONPLUS_VERSION,
	ZEND_MODULE_GLOBALS(phalconplus),
	PHP_GINIT(phalconplus),
	PHP_GSHUTDOWN(phalconplus),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(phalconplus),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_PHALCONPLUS
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(phalconplus)
#endif
