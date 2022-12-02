
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_SimpleService)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc, SimpleService, phalconplus, rpc_simpleservice, phalconplus_rpc_abstractservice_ce, phalconplus_rpc_simpleservice_method_entry, 0);

	zend_declare_property_string(phalconplus_rpc_simpleservice_ce, SL("formater"), "msgpack", ZEND_ACC_PROTECTED);
	zend_declare_property_string(phalconplus_rpc_simpleservice_ce, SL("encoder"), "msgpack_pack", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Rpc_SimpleService, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval formater;
	zval *di = NULL, di_sub, *formater_param = NULL, __$null, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&formater);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(di, zephir_get_internal_ce(SL("phalcon\\di\\diinterface")))
		Z_PARAM_STR(formater)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &di, &formater_param);
	if (!di) {
		di = &di_sub;
		di = &__$null;
	}
	if (!formater_param) {
		ZEPHIR_INIT_VAR(&formater);
		ZVAL_STRING(&formater, "json");
	} else {
		zephir_get_strval(&formater, formater_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalconplus_rpc_simpleservice_ce, getThis(), "__construct", NULL, 0, di);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "json");
	if (ZEPHIR_IS_EQUAL(&_0, &formater)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("formater"), &formater);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "json_encode");
		zephir_update_property_zval(this_ptr, ZEND_STRL("encoder"), &_1$$3);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Rpc_SimpleService, setServer)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *obj, obj_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&obj_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(obj, zephir_get_internal_ce(SL("phalconplus\\rpc\\server\\abstractserver")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	zephir_array_update_string(&_0, SL("backendSrv"), obj, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermodules", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_Rpc_SimpleService, handle)
{
	zval encoder$$5;
	zval _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, serviceObj, serviceName, config, _0, _1, responseBody, _2, _3, _4, _5, _7$$4, _8$$4, _9$$4, e$$5, ret$$5, rawRequestBody$$5, requestArgs$$5, _10$$5, _11$$5, _12$$5, _20$$5, _21$$5, _22$$5, _23$$5, _13$$9, _14$$9, _15$$8, _16$$10, _17$$10, _18$$10, _19$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&serviceObj);
	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&responseBody);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&e$$5);
	ZVAL_UNDEF(&ret$$5);
	ZVAL_UNDEF(&rawRequestBody$$5);
	ZVAL_UNDEF(&requestArgs$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&encoder$$5);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&serviceObj, this_ptr, "getserver", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&serviceObj)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "You need set a server before handler request", "phalconplus/Rpc/SimpleService.zep", 35);
		return;
	}
	ZEPHIR_INIT_VAR(&serviceName);
	zephir_get_class(&serviceName, &serviceObj, 0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "config");
	ZEPHIR_CALL_METHOD(&config, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&responseBody);
	ZVAL_STRING(&responseBody, "Not supported http method.");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "__get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &_2, "isget", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "__get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &_4, "ispost", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_create_array(&_6$$4, 3, 0);
		zephir_read_property(&_7$$4, &config, ZEND_STRL("application"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_8$$4);
		zephir_read_property(&_8$$4, &_7$$4, ZEND_STRL("ns"), PH_NOISY_CC);
		zephir_array_update_string(&_6$$4, SL("ns"), &_8$$4, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_6$$4, SL("serviceName"), &serviceName, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_9$$4, &config, ZEND_STRL("application"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_8$$4);
		zephir_read_property(&_8$$4, &_9$$4, ZEND_STRL("mode"), PH_NOISY_CC);
		zephir_array_update_string(&_6$$4, SL("originalMode"), &_8$$4, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&responseBody, this_ptr, "defaultresponse", NULL, 156, &_6$$4);
		zephir_check_call_status();
		zend_print_zval(&responseBody, 0);
	} else if (zephir_is_true(&_5)) {
		ZEPHIR_INIT_VAR(&e$$5);
		ZVAL_NULL(&e$$5);
		ZEPHIR_INIT_VAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "request");
		ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "__get", NULL, 0, &_11$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&rawRequestBody$$5, &_10$$5, "getrawbody", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("formater"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_STRING(&_12$$5, "json")) {
			ZEPHIR_INIT_VAR(&requestArgs$$5);
			zephir_json_decode(&requestArgs$$5, &rawRequestBody$$5, zephir_get_intval(&__$true) );
		} else {
			ZEPHIR_CALL_FUNCTION(&requestArgs$$5, "msgpack_unpack", NULL, 157, &rawRequestBody$$5);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&ret$$5);
		zephir_create_array(&ret$$5, 3, 0);
		add_assoc_long_ex(&ret$$5, SL("errorCode"), 0);
		add_assoc_stringl_ex(&ret$$5, SL("errorMsg"), SL(""));
		ZEPHIR_INIT_NVAR(&_11$$5);
		array_init(&_11$$5);
		zephir_array_update_string(&ret$$5, SL("data"), &_11$$5, PH_COPY | PH_SEPARATE);

		/* try_start_1: */

			if (ZEPHIR_IS_EMPTY(&requestArgs$$5)) {
				ZEPHIR_INIT_VAR(&_13$$9);
				object_init_ex(&_13$$9, phalconplus_base_exception_ce);
				ZEPHIR_INIT_VAR(&_14$$9);
				ZVAL_STRING(&_14$$9, "invalid request args");
				ZEPHIR_CALL_METHOD(NULL, &_13$$9, "__construct", NULL, 2, &_14$$9);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_13$$9, "phalconplus/Rpc/SimpleService.zep", 65);
				goto try_end_1;

			}
			ZEPHIR_CALL_METHOD(&_15$$8, &serviceObj, "callbyobject", NULL, 0, &requestArgs$$5);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_array_update_string(&ret$$5, SL("data"), &_15$$8, PH_COPY | PH_SEPARATE);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_11$$5);
			ZVAL_OBJ(&_11$$5, EG(exception));
			Z_ADDREF_P(&_11$$5);
			if (zephir_is_instance_of(&_11$$5, SL("Exception"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e$$5, &_11$$5);
				ZEPHIR_CALL_METHOD(&_16$$10, &e$$5, "getcode", NULL, 0);
				zephir_check_call_status();
				ZVAL_LONG(&_17$$10, 1);
				ZEPHIR_CALL_FUNCTION(&_18$$10, "max", NULL, 158, &_16$$10, &_17$$10);
				zephir_check_call_status();
				zephir_array_update_string(&ret$$5, SL("errorCode"), &_18$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_19$$10, &e$$5, "getmessage", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&ret$$5, SL("errorMsg"), &_19$$10, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_VAR(&_21$$5);
		ZVAL_STRING(&_21$$5, "logger");
		ZEPHIR_CALL_METHOD(&_20$$5, this_ptr, "__get", NULL, 0, &_21$$5);
		zephir_check_call_status();
		zephir_read_property(&_22$$5, &_20$$5, ZEND_STRL("logId"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&ret$$5, SL("logId"), &_22$$5, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_23$$5, this_ptr, ZEND_STRL("encoder"), PH_NOISY_CC | PH_READONLY);
		zephir_get_strval(&encoder$$5, &_23$$5);
		ZEPHIR_CALL_ZVAL_FUNCTION(&responseBody, &encoder$$5, NULL, 0, &ret$$5);
		zephir_check_call_status();
		zend_print_zval(&responseBody, 0);
	} else {
		zend_print_zval(&responseBody, 0);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

PHP_METHOD(PhalconPlus_Rpc_SimpleService, defaultResponse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_7 = NULL;
	zval *vals_param = NULL, _SERVER, __$true, sampleCodes, expectedRet, host, _0, _2, _3, _4, _5, _6, _8, _9, _10, _11, _12, _13, _1$$3;
	zval vals;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&vals);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&sampleCodes);
	ZVAL_UNDEF(&expectedRet);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(vals)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 1, &vals_param);
	if (!vals_param) {
		ZEPHIR_INIT_VAR(&vals);
		array_init(&vals);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&vals, vals_param);
	}


	ZEPHIR_OBS_VAR(&host);
	zephir_array_fetch_string(&host, &_SERVER, SL("HTTP_HOST"), PH_NOISY, "phalconplus/Rpc/SimpleService.zep", 88);
	zephir_array_fetch_string(&_0, &vals, SL("originalMode"), PH_NOISY | PH_READONLY, "phalconplus/Rpc/SimpleService.zep", 89);
	if (ZEPHIR_IS_STRING(&_0, "Web")) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VS(&_1$$3, &host, "/rpc.php");
		ZEPHIR_CPY_WRT(&host, &_1$$3);
	}
	zephir_array_fetch_string(&_2, &vals, SL("ns"), PH_NOISY | PH_READONLY, "phalconplus/Rpc/SimpleService.zep", 92);
	ZEPHIR_INIT_VAR(&sampleCodes);
	ZEPHIR_CONCAT_SVSVS(&sampleCodes, "\n<?php\n$remoteUrls = [\n    \"http://", &host, "\",\n];\n$client = new PhalconPlus\\Rpc\\Client\\Adapter\\Curl($remoteUrls);\n$result = $client->callByObject([\n    \"service\" => \"", &_2, "Services\\Demo\",\n    \"method\" => \"main\",\n    \"args\"   => [\n        \"foo\" => \"bar\",\n    ],\n]);\nvar_export($result);\n");
	ZEPHIR_INIT_VAR(&expectedRet);
	ZVAL_STRING(&expectedRet, "<?php\narray (\n	'errorCode' => 0,\n	'errorMsg' => '',\n	'logId' => 'da0abdea3483146cd8',\n	'data' => array (\n		'params' => array (\n			'foo' => 'bar',\n		),\n	),\n)\n");
	zephir_array_fetch_string(&_3, &vals, SL("serviceName"), PH_NOISY | PH_READONLY, "phalconplus/Rpc/SimpleService.zep", 94);
	zephir_array_fetch_string(&_4, &vals, SL("serviceName"), PH_NOISY | PH_READONLY, "phalconplus/Rpc/SimpleService.zep", 94);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CALL_FUNCTION(&_6, "highlight_string", &_7, 159, &sampleCodes, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "&lt;?php");
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "// Client");
	zephir_fast_str_replace(&_5, &_8, &_9, &_6);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CALL_FUNCTION(&_11, "highlight_string", &_7, 159, &expectedRet, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "&lt;?php");
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "// Return");
	zephir_fast_str_replace(&_10, &_12, &_13, &_11);
	ZEPHIR_CONCAT_SVSVSVSVS(return_value, "<!DOCTYPE html>\n<html>\n <head>\n  <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n  <title>", &_3, " - Phalcon+ Server</title>\n  <style type=\"text/css\">\n   body { margin: 0; font:14px/20px Verdana, Arial, sans-serif; color: #333; background: #f8f8f8;}\n   h1, h2, pre { margin: 0; padding: 0;}\n   h1 { font:bold 28px Verdana,Arial; background:#99c; padding: 12px 5px; border-bottom: 4px solid #669; box-shadow: 0 1px 4px #bbb; color: #222;}\n   h2 { font:normal 20px/22px Georgia, Times, \"Times New Roman\", serif; padding: 5px 0 8px; margin: 20px 10px 0; border-bottom: 1px solid #ddd; cursor:pointer;}\n   p, dd { color: #555; }\n   .api-info { padding: 10px 0; margin-left: 20px; }\n   .api-block, .sample-codes { margin: 0 40px;}\n   .code {border: 1px solid #669; padding: 10px;}\n   h2 u { font-size:20px;text-decoration:none;padding:10px; }\n  </style>\n  <script type=\"text/javascript\">\n   function _t(elem) {\n    var block = elem.nextSibling;\n    var info = elem.getElementsByTagName('u')[0];\n    while (block) {\n     if ( block.nodeType == 1 && block.className.indexOf('api-block') > -1 ) {\n      break;\n     }\n     block = block.nextSibling;\n    }\n    var isHidden = block.style.display == 'none';\n    block.style.display = isHidden ? '' : 'none';\n    info.innerHTML = isHidden ? '-'  : '+';\n   }\n  </script>\n </head>\n <body>\n    <h1>Phalcon+ Server: ", &_4, "</h1>\n    <h2>Code Samples: </h2>\n    <div class=\"sample-codes\">\n    <p class=\"code\">", &_5, "</p>\n    <p><center style=\"font-weight: bolder;\">-------------- Expected Result --------------</center></p>\n    <p class=\"code\">", &_10, "</p>\n    </div>\n    <footer>\n        <center>Copyright &copy <a href=\"https://bullsoft.org\">BullSoft.org</a></center>\n    </footer>\n </body>\n</html>");
	RETURN_MM();
}

