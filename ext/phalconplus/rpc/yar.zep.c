
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

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc, Yar, phalconplus, rpc_yar, zephir_get_internal_ce(SL("phalcon\\application")), phalconplus_rpc_yar_method_entry, 0);

	zend_declare_property_null(phalconplus_rpc_yar_ce, SL("serviceObj"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_rpc_yar_ce, SL("requestArgs"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_rpc_yar_ce, SL("responseBody"), "not supported http method", ZEND_ACC_PROTECTED);

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
		zephir_update_property_zval(this_ptr, SL("formater"), &formater);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "json_encode");
		zephir_update_property_zval(this_ptr, SL("encoder"), &_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_json_decode(&_3$$3, &rawBody, zephir_get_intval(&__$true) );
		zephir_update_property_zval(this_ptr, SL("requestArgs"), &_3$$3);
	} else {
		ZEPHIR_CALL_FUNCTION(&_4$$4, "msgpack_unpack", NULL, 126, &rawBody);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("requestArgs"), &_4$$4);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Rpc_Yar, setServer) {

	zval *obj, obj_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&obj_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &obj);



	zephir_update_property_zval(this_ptr, SL("serviceObj"), obj);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Rpc_Yar, handle) {

	zval encoder$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, __$true, serviceName, _0, sampleCodes, _1, expectedRet, _2, _3, _4, _5, _6, _37, _7$$3, _8$$3, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$3, _16$$3, e$$4, ret$$4, _17$$4, _32$$4, _33$$4, _34$$4, _35$$4, _36$$4, _18$$5, _21$$5, _25$$5, _26$$5, _27$$5, _19$$6, _20$$6, _22$$7, _23$$7, _24$$7, _28$$8, _29$$8, _30$$8, _31$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&sampleCodes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&expectedRet);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&e$$4);
	ZVAL_UNDEF(&ret$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_32$$4);
	ZVAL_UNDEF(&_33$$4);
	ZVAL_UNDEF(&_34$$4);
	ZVAL_UNDEF(&_35$$4);
	ZVAL_UNDEF(&_36$$4);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_27$$5);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&encoder$$4);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	zephir_read_property(&_0, this_ptr, SL("serviceObj"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&serviceName);
	zephir_get_class(&serviceName, &_0, 0);
	zephir_array_fetch_string(&_1, &_SERVER, SL("HTTP_HOST"), PH_NOISY | PH_READONLY, "phalconplus/Rpc/Yar.zep", 44);
	ZEPHIR_INIT_VAR(&sampleCodes);
	ZEPHIR_CONCAT_SVS(&sampleCodes, "<?php\n$remoteUrls = [\n\t\"http://", &_1, "\",\n];\n$client = new \\PhalconPlus\\Rpc\\Client\\Adapter\\Curl($remoteUrls);\n$result = $client->callByObject([\n\t\"service\" => \"\\Demo\\Services\\Dummy\",\n\t\"method\" => \"demo\",\n\t\"args\"   => [\n\t\t\"foo\" => \"bar\",\n\t],\n]);\nvar_export($result);\n");
	ZEPHIR_INIT_VAR(&expectedRet);
	ZVAL_STRING(&expectedRet, "<?php\narray (\n\t'errorCode' => 0,\n\t'errorMsg' => '',\n\t'logId' => 'da0abdea3483146cd8',\n\t'data' => array (\n\t\t'params' => array (\n\t\t\t'foo' => 'bar',\n\t\t),\n\t),\n)\n");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "request");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "__get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_2, "isget", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "request");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "__get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, &_5, "ispost", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_7$$3);
		ZEPHIR_CALL_FUNCTION(&_8$$3, "highlight_string", &_9, 127, &sampleCodes, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "&lt;?php");
		ZEPHIR_INIT_VAR(&_11$$3);
		ZVAL_STRING(&_11$$3, "// Client");
		zephir_fast_str_replace(&_7$$3, &_10$$3, &_11$$3, &_8$$3);
		ZEPHIR_INIT_VAR(&_12$$3);
		ZEPHIR_CALL_FUNCTION(&_13$$3, "highlight_string", &_9, 127, &expectedRet, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_14$$3);
		ZVAL_STRING(&_14$$3, "&lt;?php");
		ZEPHIR_INIT_VAR(&_15$$3);
		ZVAL_STRING(&_15$$3, "// Return");
		zephir_fast_str_replace(&_12$$3, &_14$$3, &_15$$3, &_13$$3);
		ZEPHIR_INIT_VAR(&_16$$3);
		ZEPHIR_CONCAT_SVSVSVSVS(&_16$$3, "<!DOCTYPE html>\n\t\t\t<html>\n\t\t\t <head>\n\t\t\t  <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n\t\t\t  <title>", &serviceName, " - Phalcon+ Server</title>\n\t\t\t  <style>\n\t\t\t   body { margin: 0; font:14px/20px Verdana, Arial, sans-serif; color: #333; background: #f8f8f8;}\n\t\t\t   h1, h2, pre { margin: 0; padding: 0;}\n\t\t\t   h1 { font:bold 28px Verdana,Arial; background:#99c; padding: 12px 5px; border-bottom: 4px solid #669; box-shadow: 0 1px 4px #bbb; color: #222;}\n\t\t\t   h2 { font:normal 20px/22px Georgia, Times, \"Times New Roman\", serif; padding: 5px 0 8px; margin: 20px 10px 0; border-bottom: 1px solid #ddd; cursor:pointer;}\n\t\t\t   p, dd { color: #555; }\n\t\t\t   .api-info { padding: 10px 0; margin-left: 20px; }\n\t\t\t   .api-block, .sample-codes { margin: 0 40px;}\n\t\t\t   .code {border: 1px solid #669; padding: 10px;}\n\t\t\t   h2 u { font-size:20px;text-decoration:none;padding:10px; }\n\t\t\t  </style>\n\t\t\t  <script>\n\t\t\t   function _t(elem) {\n\t\t\t\tvar block = elem.nextSibling;\n\t\t\t\tvar info = elem.getElementsByTagName('u')[0];\n\t\t\t\twhile (block) {\n\t\t\t\t if ( block.nodeType == 1 && block.className.indexOf('api-block') > -1 ) {\n\t\t\t\t  break;\n\t\t\t\t }\n\t\t\t\t block = block.nextSibling;\n\t\t\t\t}\n\t\t\t\tvar isHidden = block.style.display == 'none';\n\t\t\t\tblock.style.display = isHidden ? '' : 'none';\n\t\t\t\tinfo.innerHTML = isHidden ? '-'  : '+';\n\t\t\t   }\n\t\t\t  </script>\n\t\t\t </head>\n\t\t\t <body>\n\t\t\t\t<h1>Phalcon+ Server: ", &serviceName, "</h1>\n\t\t\t\t<h2>Code Samples: </h2>\n\t\t\t\t<div class=\"sample-codes\">\n\t\t\t\t<p class=\"code\">", &_7$$3, "</p>\n\t\t\t\t<p><center style=\"font-weight: bolder;\">-------------- Expected Result --------------</center></p>\n\t\t\t\t<p class=\"code\">", &_12$$3, "</p>\n\t\t\t\t</div>\n\t\t\t\t<footer>\n\t\t\t\t    <center>Copyright &copy <a href=\"https://bullsoft.org\">BullSoft.org</a></center>\n\t\t\t\t</footer>\n\t\t\t </body>\n\t\t    </html>");
		zephir_update_property_zval(this_ptr, SL("responseBody"), &_16$$3);
	} else if (zephir_is_true(&_6)) {
		ZEPHIR_INIT_VAR(&e$$4);
		ZVAL_NULL(&e$$4);
		ZEPHIR_INIT_VAR(&ret$$4);
		zephir_create_array(&ret$$4, 3, 0);
		add_assoc_long_ex(&ret$$4, SL("errorCode"), 0);
		add_assoc_stringl_ex(&ret$$4, SL("errorMsg"), SL(""));
		ZEPHIR_INIT_VAR(&_17$$4);
		array_init(&_17$$4);
		zephir_array_update_string(&ret$$4, SL("data"), &_17$$4, PH_COPY | PH_SEPARATE);

		/* try_start_1: */

			zephir_read_property(&_18$$5, this_ptr, SL("requestArgs"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_EMPTY(&_18$$5)) {
				ZEPHIR_INIT_VAR(&_19$$6);
				object_init_ex(&_19$$6, zend_exception_get_default(TSRMLS_C));
				ZEPHIR_INIT_VAR(&_20$$6);
				ZVAL_STRING(&_20$$6, "invalid request args");
				ZEPHIR_CALL_METHOD(NULL, &_19$$6, "__construct", NULL, 9, &_20$$6);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_19$$6, "phalconplus/Rpc/Yar.zep", 57);
				goto try_end_1;

			}
			zephir_read_property(&_21$$5, this_ptr, SL("serviceObj"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_EMPTY(&_21$$5)) {
				ZEPHIR_CALL_METHOD(&_22$$7, this_ptr, "getdi", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_INIT_VAR(&_24$$7);
				ZVAL_STRING(&_24$$7, "backendSrv");
				ZEPHIR_CALL_METHOD(&_23$$7, &_22$$7, "get", NULL, 0, &_24$$7);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_update_property_zval(this_ptr, SL("serviceObj"), &_23$$7);
			}
			zephir_read_property(&_25$$5, this_ptr, SL("serviceObj"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_27$$5, this_ptr, SL("requestArgs"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_26$$5, &_25$$5, "callbyobject", NULL, 0, &_27$$5);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_array_update_string(&ret$$4, SL("data"), &_26$$5, PH_COPY | PH_SEPARATE);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_17$$4);
			ZVAL_OBJ(&_17$$4, EG(exception));
			Z_ADDREF_P(&_17$$4);
			if (zephir_instance_of_ev(&_17$$4, zend_exception_get_default(TSRMLS_C))) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e$$4, &_17$$4);
				ZEPHIR_CALL_METHOD(&_28$$8, &e$$4, "getcode", NULL, 0);
				zephir_check_call_status();
				ZVAL_LONG(&_29$$8, 1);
				ZEPHIR_CALL_FUNCTION(&_30$$8, "max", NULL, 128, &_28$$8, &_29$$8);
				zephir_check_call_status();
				zephir_array_update_string(&ret$$4, SL("errorCode"), &_30$$8, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_31$$8, &e$$4, "getmessage", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&ret$$4, SL("errorMsg"), &_31$$8, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_VAR(&_33$$4);
		ZVAL_STRING(&_33$$4, "logger");
		ZEPHIR_CALL_METHOD(&_32$$4, this_ptr, "__get", NULL, 0, &_33$$4);
		zephir_check_call_status();
		zephir_read_property(&_34$$4, &_32$$4, SL("logId"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&ret$$4, SL("logId"), &_34$$4, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_35$$4, this_ptr, SL("encoder"), PH_NOISY_CC | PH_READONLY);
		zephir_get_strval(&encoder$$4, &_35$$4);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_36$$4, &encoder$$4, NULL, 0, &ret$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("responseBody"), &_36$$4);
	}
	zephir_read_property(&_37, this_ptr, SL("responseBody"), PH_NOISY_CC | PH_READONLY);
	zend_print_zval(&_37, 0);
	ZEPHIR_MM_RESTORE();

}

