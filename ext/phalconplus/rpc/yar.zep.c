
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
		ZVAL_STRING(&formater, "");
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
		ZEPHIR_CALL_FUNCTION(&_4$$4, "msgpack_unpack", NULL, 124, &rawBody);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("requestArgs"), &_4$$4);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Rpc_Yar, handle) {

	zval encoder$$4;
	zval _0, _1, _2, _3, _4, _24, _5$$3, e$$4, ret$$4, _6$$4, _7$$4, _8$$4, _22$$4, _23$$4, _9$$5, _12$$5, _13$$5, _14$$5, _15$$5, _16$$5, _17$$5, _10$$6, _11$$6, _18$$7, _19$$7, _20$$7, _21$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&e$$4);
	ZVAL_UNDEF(&ret$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&encoder$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "__get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_0, "isget", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "__get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_3, "ispost", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "<h1>Welcome to Phalcon+</h1>\n			<p>If you see this page, the phalcon-rpc server is successfully installed and\n			working.</p>");
		zephir_update_property_zval(this_ptr, SL("responseBody"), &_5$$3);
	} else if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&e$$4);
		ZVAL_NULL(&e$$4);
		ZEPHIR_INIT_VAR(&ret$$4);
		zephir_create_array(&ret$$4, 4, 0);
		add_assoc_long_ex(&ret$$4, SL("errorCode"), 0);
		add_assoc_stringl_ex(&ret$$4, SL("errorMsg"), SL(""));
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "logger");
		ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "__get", NULL, 0, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&_8$$4);
		zephir_read_property(&_8$$4, &_6$$4, SL("logId"), PH_NOISY_CC);
		zephir_array_update_string(&ret$$4, SL("logId"), &_8$$4, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_7$$4);
		array_init(&_7$$4);
		zephir_array_update_string(&ret$$4, SL("data"), &_7$$4, PH_COPY | PH_SEPARATE);

		/* try_start_1: */

			zephir_read_property(&_9$$5, this_ptr, SL("requestArgs"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_EMPTY(&_9$$5)) {
				ZEPHIR_INIT_VAR(&_10$$6);
				object_init_ex(&_10$$6, zend_exception_get_default(TSRMLS_C));
				ZEPHIR_INIT_VAR(&_11$$6);
				ZVAL_STRING(&_11$$6, "invalid request args");
				ZEPHIR_CALL_METHOD(NULL, &_10$$6, "__construct", NULL, 7, &_11$$6);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_10$$6, "phalconplus/Rpc/Yar.zep", 47);
				goto try_end_1;

			}
			ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getdi", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_INIT_VAR(&_14$$5);
			ZVAL_STRING(&_14$$5, "backendSrv");
			ZEPHIR_CALL_METHOD(&_13$$5, &_12$$5, "get", NULL, 0, &_14$$5);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_zval(this_ptr, SL("serviceObj"), &_13$$5);
			zephir_read_property(&_15$$5, this_ptr, SL("serviceObj"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_17$$5, this_ptr, SL("requestArgs"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_16$$5, &_15$$5, "callbyobject", NULL, 0, &_17$$5);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_array_update_string(&ret$$4, SL("data"), &_16$$5, PH_COPY | PH_SEPARATE);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZVAL_OBJ(&_7$$4, EG(exception));
			Z_ADDREF_P(&_7$$4);
			if (zephir_instance_of_ev(&_7$$4, zend_exception_get_default(TSRMLS_C))) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e$$4, &_7$$4);
				ZEPHIR_CALL_METHOD(&_18$$7, &e$$4, "getcode", NULL, 0);
				zephir_check_call_status();
				ZVAL_LONG(&_19$$7, 1);
				ZEPHIR_CALL_FUNCTION(&_20$$7, "max", NULL, 125, &_18$$7, &_19$$7);
				zephir_check_call_status();
				zephir_array_update_string(&ret$$4, SL("errorCode"), &_20$$7, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_21$$7, &e$$4, "getmessage", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&ret$$4, SL("errorMsg"), &_21$$7, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_read_property(&_22$$4, this_ptr, SL("encoder"), PH_NOISY_CC | PH_READONLY);
		zephir_get_strval(&encoder$$4, &_22$$4);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_23$$4, &encoder$$4, NULL, 0, &ret$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("responseBody"), &_23$$4);
	}
	zephir_read_property(&_24, this_ptr, SL("responseBody"), PH_NOISY_CC | PH_READONLY);
	zend_print_zval(&_24, 0);
	ZEPHIR_MM_RESTORE();

}

