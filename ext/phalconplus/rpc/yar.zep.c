
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Yar) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc, Yar, phalconplus, rpc_yar, zephir_get_internal_ce(SL("phalcon\\application\\abstractapplication")), phalconplus_rpc_yar_method_entry, 0);

	zend_declare_property_null(phalconplus_rpc_yar_ce, SL("serviceObj"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_rpc_yar_ce, SL("requestArgs"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_rpc_yar_ce, SL("responseBody"), "Not supported http method.", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_rpc_yar_ce, SL("formater"), "msgpack", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_rpc_yar_ce, SL("encoder"), "msgpack_pack", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Rpc_Yar, getServiceObj) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "serviceObj");

}

PHP_METHOD(PhalconPlus_Rpc_Yar, getRequestArgs) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "requestArgs");

}

PHP_METHOD(PhalconPlus_Rpc_Yar, getResponseBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "responseBody");

}

PHP_METHOD(PhalconPlus_Rpc_Yar, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval formater;
	zval *di = NULL, di_sub, *formater_param = NULL, __$true, __$null, rawBody, _0, _1, _2, _3$$3, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&rawBody);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&formater);

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


	ZEPHIR_CALL_PARENT(NULL, phalconplus_rpc_yar_ce, getThis(), "__construct", NULL, 0, di);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "__get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&rawBody, &_0, "getrawbody", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "json");
	if (ZEPHIR_IS_EQUAL(&_2, &formater)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("formater"), &formater);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "json_encode");
		zephir_update_property_zval(this_ptr, ZEND_STRL("encoder"), &_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_json_decode(&_3$$3, &rawBody, zephir_get_intval(&__$true) );
		zephir_update_property_zval(this_ptr, ZEND_STRL("requestArgs"), &_3$$3);
	} else {
		ZEPHIR_CALL_FUNCTION(&_4$$4, "msgpack_unpack", NULL, 144, &rawBody);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("requestArgs"), &_4$$4);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Rpc_Yar, setServer) {

	zval *obj, obj_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&obj_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &obj);



	zephir_update_property_zval(this_ptr, ZEND_STRL("serviceObj"), obj);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Rpc_Yar, getServer) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "serviceObj");

}

PHP_METHOD(PhalconPlus_Rpc_Yar, handle) {

	zval encoder$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zval _SERVER, __$true, serviceName, _0, config, _1, _2, sampleCodes, _3, _4, _5, expectedRet, _6, _7, _8, _9, _40, _10$$3, _11$$3, _13$$3, _14$$3, _15$$3, _16$$3, _17$$3, _18$$3, _19$$3, e$$4, ret$$4, _20$$4, _35$$4, _36$$4, _37$$4, _38$$4, _39$$4, _21$$5, _24$$5, _28$$5, _29$$5, _30$$5, _22$$6, _23$$6, _25$$7, _26$$7, _27$$7, _31$$8, _32$$8, _33$$8, _34$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&sampleCodes);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&expectedRet);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&e$$4);
	ZVAL_UNDEF(&ret$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_35$$4);
	ZVAL_UNDEF(&_36$$4);
	ZVAL_UNDEF(&_37$$4);
	ZVAL_UNDEF(&_38$$4);
	ZVAL_UNDEF(&_39$$4);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_28$$5);
	ZVAL_UNDEF(&_29$$5);
	ZVAL_UNDEF(&_30$$5);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&encoder$$4);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	zephir_read_property(&_0, this_ptr, ZEND_STRL("serviceObj"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&serviceName);
	zephir_get_class(&serviceName, &_0, 0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "config");
	ZEPHIR_CALL_METHOD(&config, &_1, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, &_SERVER, SL("HTTP_HOST"), PH_NOISY | PH_READONLY, "phalconplus/Rpc/Yar.zep", 43);
	zephir_read_property(&_4, &config, ZEND_STRL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, &_4, ZEND_STRL("ns"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&sampleCodes);
	ZEPHIR_CONCAT_SVSVS(&sampleCodes, "<?php\n$remoteUrls = [\n	\"http://", &_3, "\",\n];\n$client = new \\PhalconPlus\\Rpc\\Client\\Adapter\\Curl($remoteUrls);\n$result = $client->callByObject([\n	\"service\" => \"\\", &_5, "Services\\Demo\",\n	\"method\" => \"demo\",\n	\"args\"   => [\n		\"foo\" => \"bar\",\n	],\n]);\nvar_export($result);\n");
	ZEPHIR_INIT_VAR(&expectedRet);
	ZVAL_STRING(&expectedRet, "<?php\narray (\n	'errorCode' => 0,\n	'errorMsg' => '',\n	'logId' => 'da0abdea3483146cd8',\n	'data' => array (\n		'params' => array (\n			'foo' => 'bar',\n		),\n	),\n)\n");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "request");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "__get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, &_6, "isget", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "request");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "__get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, &_8, "ispost", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZEPHIR_INIT_VAR(&_10$$3);
		ZEPHIR_CALL_FUNCTION(&_11$$3, "highlight_string", &_12, 145, &sampleCodes, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$3);
		ZVAL_STRING(&_13$$3, "&lt;?php");
		ZEPHIR_INIT_VAR(&_14$$3);
		ZVAL_STRING(&_14$$3, "// Client");
		zephir_fast_str_replace(&_10$$3, &_13$$3, &_14$$3, &_11$$3);
		ZEPHIR_INIT_VAR(&_15$$3);
		ZEPHIR_CALL_FUNCTION(&_16$$3, "highlight_string", &_12, 145, &expectedRet, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_17$$3);
		ZVAL_STRING(&_17$$3, "&lt;?php");
		ZEPHIR_INIT_VAR(&_18$$3);
		ZVAL_STRING(&_18$$3, "// Return");
		zephir_fast_str_replace(&_15$$3, &_17$$3, &_18$$3, &_16$$3);
		ZEPHIR_INIT_VAR(&_19$$3);
		ZEPHIR_CONCAT_SVSVSVSVS(&_19$$3, "<!DOCTYPE html>\n			<html>\n			 <head>\n			  <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n			  <title>", &serviceName, " - Phalcon+ Server</title>\n			  <style>\n			   body { margin: 0; font:14px/20px Verdana, Arial, sans-serif; color: #333; background: #f8f8f8;}\n			   h1, h2, pre { margin: 0; padding: 0;}\n			   h1 { font:bold 28px Verdana,Arial; background:#99c; padding: 12px 5px; border-bottom: 4px solid #669; box-shadow: 0 1px 4px #bbb; color: #222;}\n			   h2 { font:normal 20px/22px Georgia, Times, \"Times New Roman\", serif; padding: 5px 0 8px; margin: 20px 10px 0; border-bottom: 1px solid #ddd; cursor:pointer;}\n			   p, dd { color: #555; }\n			   .api-info { padding: 10px 0; margin-left: 20px; }\n			   .api-block, .sample-codes { margin: 0 40px;}\n			   .code {border: 1px solid #669; padding: 10px;}\n			   h2 u { font-size:20px;text-decoration:none;padding:10px; }\n			  </style>\n			  <script>\n			   function _t(elem) {\n				var block = elem.nextSibling;\n				var info = elem.getElementsByTagName('u')[0];\n				while (block) {\n				 if ( block.nodeType == 1 && block.className.indexOf('api-block') > -1 ) {\n				  break;\n				 }\n				 block = block.nextSibling;\n				}\n				var isHidden = block.style.display == 'none';\n				block.style.display = isHidden ? '' : 'none';\n				info.innerHTML = isHidden ? '-'  : '+';\n			   }\n			  </script>\n			 </head>\n			 <body>\n				<h1>Phalcon+ Server: ", &serviceName, "</h1>\n				<h2>Code Samples: </h2>\n				<div class=\"sample-codes\">\n				<p class=\"code\">", &_10$$3, "</p>\n				<p><center style=\"font-weight: bolder;\">-------------- Expected Result --------------</center></p>\n				<p class=\"code\">", &_15$$3, "</p>\n				</div>\n				<footer>\n				    <center>Copyright &copy <a href=\"https://bullsoft.org\">BullSoft.org</a></center>\n				</footer>\n			 </body>\n		    </html>");
		zephir_update_property_zval(this_ptr, ZEND_STRL("responseBody"), &_19$$3);
	} else if (zephir_is_true(&_9)) {
		ZEPHIR_INIT_VAR(&e$$4);
		ZVAL_NULL(&e$$4);
		ZEPHIR_INIT_VAR(&ret$$4);
		zephir_create_array(&ret$$4, 3, 0);
		add_assoc_long_ex(&ret$$4, SL("errorCode"), 0);
		add_assoc_stringl_ex(&ret$$4, SL("errorMsg"), SL(""));
		ZEPHIR_INIT_VAR(&_20$$4);
		array_init(&_20$$4);
		zephir_array_update_string(&ret$$4, SL("data"), &_20$$4, PH_COPY | PH_SEPARATE);

		/* try_start_1: */

			zephir_read_property(&_21$$5, this_ptr, ZEND_STRL("requestArgs"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_EMPTY(&_21$$5)) {
				ZEPHIR_INIT_VAR(&_22$$6);
				object_init_ex(&_22$$6, zend_exception_get_default(TSRMLS_C));
				ZEPHIR_INIT_VAR(&_23$$6);
				ZVAL_STRING(&_23$$6, "invalid request args");
				ZEPHIR_CALL_METHOD(NULL, &_22$$6, "__construct", NULL, 120, &_23$$6);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_22$$6, "phalconplus/Rpc/Yar.zep", 57);
				goto try_end_1;

			}
			zephir_read_property(&_24$$5, this_ptr, ZEND_STRL("serviceObj"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_EMPTY(&_24$$5)) {
				ZEPHIR_CALL_METHOD(&_25$$7, this_ptr, "getdi", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_INIT_VAR(&_27$$7);
				ZVAL_STRING(&_27$$7, "backendSrv");
				ZEPHIR_CALL_METHOD(&_26$$7, &_25$$7, "get", NULL, 0, &_27$$7);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_update_property_zval(this_ptr, ZEND_STRL("serviceObj"), &_26$$7);
			}
			zephir_read_property(&_28$$5, this_ptr, ZEND_STRL("serviceObj"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_30$$5, this_ptr, ZEND_STRL("requestArgs"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_29$$5, &_28$$5, "callbyobject", NULL, 0, &_30$$5);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_array_update_string(&ret$$4, SL("data"), &_29$$5, PH_COPY | PH_SEPARATE);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_20$$4);
			ZVAL_OBJ(&_20$$4, EG(exception));
			Z_ADDREF_P(&_20$$4);
			if (zephir_instance_of_ev(&_20$$4, zend_exception_get_default(TSRMLS_C))) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e$$4, &_20$$4);
				ZEPHIR_CALL_METHOD(&_31$$8, &e$$4, "getcode", NULL, 0);
				zephir_check_call_status();
				ZVAL_LONG(&_32$$8, 1);
				ZEPHIR_CALL_FUNCTION(&_33$$8, "max", NULL, 146, &_31$$8, &_32$$8);
				zephir_check_call_status();
				zephir_array_update_string(&ret$$4, SL("errorCode"), &_33$$8, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_34$$8, &e$$4, "getmessage", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&ret$$4, SL("errorMsg"), &_34$$8, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_VAR(&_36$$4);
		ZVAL_STRING(&_36$$4, "logger");
		ZEPHIR_CALL_METHOD(&_35$$4, this_ptr, "__get", NULL, 0, &_36$$4);
		zephir_check_call_status();
		zephir_read_property(&_37$$4, &_35$$4, ZEND_STRL("logId"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&ret$$4, SL("logId"), &_37$$4, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_38$$4, this_ptr, ZEND_STRL("encoder"), PH_NOISY_CC | PH_READONLY);
		zephir_get_strval(&encoder$$4, &_38$$4);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_39$$4, &encoder$$4, NULL, 0, &ret$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("responseBody"), &_39$$4);
	}
	zephir_read_property(&_40, this_ptr, ZEND_STRL("responseBody"), PH_NOISY_CC | PH_READONLY);
	zend_print_zval(&_40, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Rpc_Yar, responseBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "responseBody");

}

