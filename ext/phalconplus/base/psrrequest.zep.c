
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_PsrRequest) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, PsrRequest, phalconplus, base_psrrequest, zephir_get_internal_ce(SL("phalcon\\http\\request")), phalconplus_base_psrrequest_method_entry, 0);

	zend_declare_property_null(phalconplus_base_psrrequest_ce, SL("get"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_psrrequest_ce, SL("post"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_psrrequest_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_psrrequest_ce, SL("attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_psrrequest_ce, SL("cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_psrrequest_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_psrrequest_ce, SL("files"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_psrrequest_ce, SL("server"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_psrrequest_ce, SL("psrRequest"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_base_psrrequest_ce->create_object = zephir_init_properties_PhalconPlus_Base_PsrRequest;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "attributes");

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getCookies) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cookies");

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getFiles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "files");

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getPsrRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "psrRequest");

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, __construct) {

	zend_string *_20;
	zend_ulong _19;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _SERVER, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, k, v, _16, *_17, _18, _29, _21$$5, _22$$5, _23$$5, _24$$5, _25$$6, _26$$6, _27$$6, _28$$6, _30$$7, _31$$7, _32$$8, _33$$8, _34$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_CALL_METHOD(&_0, request, "getqueryparams", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("get"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, request, "getparsedbody", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_INIT_NVAR(&_1);
		array_init(&_1);
	} else {
		ZEPHIR_CALL_METHOD(&_1, request, "getparsedbody", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("post"), &_1);
	ZEPHIR_INIT_VAR(&_3);
	zephir_read_property(&_4, this_ptr, SL("get"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, SL("post"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_3, &_4, &_5 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("request"), &_3);
	ZEPHIR_CALL_METHOD(&_6, request, "getattributes", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("attributes"), &_6);
	ZEPHIR_CALL_METHOD(&_7, request, "getcookieparams", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("cookies"), &_7);
	ZEPHIR_CALL_METHOD(&_8, request, "getheaders", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("headers"), &_8);
	ZEPHIR_CALL_METHOD(&_9, request, "getserverparams", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("server"), &_9);
	ZEPHIR_CALL_METHOD(&_10, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "REQUEST_METHOD");
	zephir_update_property_array(this_ptr, SL("server"), &_11, &_10);
	ZEPHIR_INIT_NVAR(&_10);
	ZEPHIR_CALL_METHOD(&_10, request, "getbody", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, &_10, "__tostring", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_rawBody"), &_12);
	ZEPHIR_CALL_SELF(&_13, "getrequesttarget", NULL, 0, request);
	zephir_check_call_status();
	zephir_array_update_string(&_SERVER, SL("REQUEST_URI"), &_13, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_14, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_SERVER, SL("REQUEST_METHOD"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_15, request, "getuploadedfiles", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", NULL, 50, &_15);
	zephir_check_call_status();
	zephir_read_property(&_16, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_16, 0, "phalconplus/Base/PsrRequest.zep", 58);
	if (Z_TYPE_P(&_16) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_16), _19, _20, _17)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_20 != NULL) { 
				ZVAL_STR_COPY(&k, _20);
			} else {
				ZVAL_LONG(&k, _19);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _17);
			ZEPHIR_INIT_NVAR(&_21$$5);
			ZEPHIR_INIT_NVAR(&_22$$5);
			ZVAL_STRING(&_22$$5, "-");
			ZEPHIR_INIT_NVAR(&_23$$5);
			ZVAL_STRING(&_23$$5, "_");
			zephir_fast_str_replace(&_21$$5, &_22$$5, &_23$$5, &k TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&k);
			zephir_fast_strtoupper(&k, &_21$$5);
			ZEPHIR_INIT_LNVAR(_24$$5);
			ZEPHIR_CONCAT_SV(&_24$$5, "HTTP_", &k);
			zephir_array_update_zval(&_SERVER, &_24$$5, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_16, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_18, &_16, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_18)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &_16, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &_16, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_25$$6);
				ZEPHIR_INIT_NVAR(&_26$$6);
				ZVAL_STRING(&_26$$6, "-");
				ZEPHIR_INIT_NVAR(&_27$$6);
				ZVAL_STRING(&_27$$6, "_");
				zephir_fast_str_replace(&_25$$6, &_26$$6, &_27$$6, &k TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&k);
				zephir_fast_strtoupper(&k, &_25$$6);
				ZEPHIR_INIT_LNVAR(_28$$6);
				ZEPHIR_CONCAT_SV(&_28$$6, "HTTP_", &k);
				zephir_array_update_zval(&_SERVER, &_28$$6, &v, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_16, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_29, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_29))) {
		zephir_read_property(&_30$$7, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_31$$7, "session_name", NULL, 51);
		zephir_check_call_status();
		if (zephir_array_isset(&_30$$7, &_31$$7)) {
			zephir_read_property(&_32$$8, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_34$$8, "session_name", NULL, 51);
			zephir_check_call_status();
			zephir_array_fetch(&_33$$8, &_32$$8, &_34$$8, PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 60 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 52, &_33$$8);
			zephir_check_call_status();
		}
	}
	zephir_update_property_zval(this_ptr, SL("psrRequest"), request);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getRequestTarget) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, target, _0, _1, _2, _3$$4, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&target, &_0, "getpath", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&target, "")) {
		ZEPHIR_INIT_NVAR(&target);
		ZVAL_STRING(&target, "/");
	}
	ZEPHIR_CALL_METHOD(&_1, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "getquery", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&_2, "")) {
		ZEPHIR_CALL_METHOD(&_3$$4, request, "geturi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, &_3$$4, "getquery", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SV(&_5$$4, "?", &_4$$4);
		zephir_concat_self(&target, &_5$$4 TSRMLS_CC);
	}
	RETURN_CCTOR(&target);

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, mapFiles) {

	zval _9$$6, _16$$10;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uploads_param = NULL, file, *_0, _1, tmpname$$5, _3$$5, _5$$5, _7$$5, _11$$5, _8$$6, tmpname$$9, _12$$9, _13$$9, _14$$9, _18$$9, _15$$10;
	zval uploads, _10$$5, _17$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uploads);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&tmpname$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&tmpname$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_16$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uploads_param);

	zephir_get_arrval(&uploads, uploads_param);


	zephir_is_iterable(&uploads, 0, "phalconplus/Base/PsrRequest.zep", 102);
	if (Z_TYPE_P(&uploads) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&uploads), _0)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			if (Z_TYPE_P(&file) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", &_2, 50, &file);
				zephir_check_call_status();
			} else if (zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface") TSRMLS_CC)) {
				ZEPHIR_CALL_FUNCTION(&_3$$5, "sys_get_temp_dir", &_4, 53);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "upload");
				ZEPHIR_CALL_FUNCTION(&tmpname$$5, "tempnam", &_6, 54, &_3$$5, &_5$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$5, &file, "geterror", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_7$$5, 0)) {
					ZEPHIR_CALL_METHOD(&_8$$6, &file, "getstream", NULL, 0);
					zephir_check_call_status();
					zephir_get_strval(&_9$$6, &_8$$6);
					zephir_file_put_contents(NULL, &tmpname$$5, &_9$$6 TSRMLS_CC);
				}
				ZEPHIR_INIT_NVAR(&_10$$5);
				zephir_create_array(&_10$$5, 5, 0 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_11$$5, &file, "geterror", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_10$$5, SL("error"), &_11$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_11$$5, &file, "getclientfilename", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_10$$5, SL("name"), &_11$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_11$$5, &file, "getsize", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_10$$5, SL("size"), &_11$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$5, SL("tmp_name"), &tmpname$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_11$$5, &file, "getclientmediatype", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_10$$5, SL("type"), &_11$$5, PH_COPY | PH_SEPARATE);
				zephir_update_property_array_append(this_ptr, SL("files"), &_10$$5);
				ZEPHIR_INIT_NVAR(&_10$$5);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &uploads, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &uploads, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &uploads, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&file) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", &_2, 50, &file);
					zephir_check_call_status();
				} else if (zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface") TSRMLS_CC)) {
					ZEPHIR_CALL_FUNCTION(&_12$$9, "sys_get_temp_dir", &_4, 53);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_13$$9);
					ZVAL_STRING(&_13$$9, "upload");
					ZEPHIR_CALL_FUNCTION(&tmpname$$9, "tempnam", &_6, 54, &_12$$9, &_13$$9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_14$$9, &file, "geterror", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_14$$9, 0)) {
						ZEPHIR_CALL_METHOD(&_15$$10, &file, "getstream", NULL, 0);
						zephir_check_call_status();
						zephir_get_strval(&_16$$10, &_15$$10);
						zephir_file_put_contents(NULL, &tmpname$$9, &_16$$10 TSRMLS_CC);
					}
					ZEPHIR_INIT_NVAR(&_17$$9);
					zephir_create_array(&_17$$9, 5, 0 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_18$$9, &file, "geterror", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_string(&_17$$9, SL("error"), &_18$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_18$$9, &file, "getclientfilename", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_string(&_17$$9, SL("name"), &_18$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_18$$9, &file, "getsize", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_string(&_17$$9, SL("size"), &_18$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_17$$9, SL("tmp_name"), &tmpname$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_18$$9, &file, "getclientmediatype", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_string(&_17$$9, SL("type"), &_18$$9, PH_COPY | PH_SEPARATE);
					zephir_update_property_array_append(this_ptr, SL("files"), &_17$$9);
					ZEPHIR_INIT_NVAR(&_17$$9);
				}
			ZEPHIR_CALL_METHOD(NULL, &uploads, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, removeTmpFiles) {

	zval file, _0, *_1, _2, _3$$3, _4$$4, _6$$5, _7$$6;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalconplus/Base/PsrRequest.zep", 112);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _1);
			zephir_array_fetch_string(&_3$$3, &file, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 108 TSRMLS_CC);
			if ((zephir_file_exists(&_3$$3 TSRMLS_CC) == SUCCESS)) {
				zephir_array_fetch_string(&_4$$4, &file, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 109 TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_5, 55, &_4$$4);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &_0, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_6$$5, &file, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 108 TSRMLS_CC);
				if ((zephir_file_exists(&_6$$5 TSRMLS_CC) == SUCCESS)) {
					zephir_array_fetch_string(&_7$$6, &file, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 109 TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_5, 55, &_7$$6);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _POST, _GET, __$null, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_GET);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("post"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &_POST TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("post"), &_0);
	ZEPHIR_INIT_VAR(&_2);
	zephir_read_property(&_3, this_ptr, SL("get"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_2, &_3, &_GET TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("get"), &_2);
	ZEPHIR_INIT_VAR(&_4);
	zephir_read_property(&_5, this_ptr, SL("get"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_6, this_ptr, SL("post"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_4, &_5, &_6 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("request"), &_4);
	zephir_read_property(&_7, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	if (notAllowEmpty) {
		ZVAL_BOOL(&_8, 1);
	} else {
		ZVAL_BOOL(&_8, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_9, 1);
	} else {
		ZVAL_BOOL(&_9, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 0, &_7, &name, filters, defaultValue, &_8, &_9);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getPost) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _POST, __$null, _0, _1, _2, _3, _4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_POST);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("post"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &_POST TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("post"), &_0);
	zephir_read_property(&_2, this_ptr, SL("post"), PH_NOISY_CC | PH_READONLY);
	if (notAllowEmpty) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 0, &_2, &name, filters, defaultValue, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getQuery) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _GET, __$null, _0, _1, _2, _3, _4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_GET);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("get"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &_GET TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("get"), &_0);
	zephir_read_property(&_2, this_ptr, SL("get"), PH_NOISY_CC | PH_READONLY);
	if (notAllowEmpty) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 0, &_2, &name, filters, defaultValue, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, has) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, hasPost) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("post"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, hasQuery) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("get"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getScheme) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getscheme", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks whether request has been made using ajax
 */
PHP_METHOD(PhalconPlus_Base_PsrRequest, isAjax) {

	zend_bool _1;
	zval _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string(&_0, SL("HTTP_X_REQUESTED_WITH"));
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3, &_2, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 160 TSRMLS_CC);
		_1 = ZEPHIR_IS_STRING_IDENTICAL(&_3, "XMLHttpRequest");
	}
	RETURN_BOOL(_1);

}

/**
 * Checks whether request has been made using SOAP
 */
PHP_METHOD(PhalconPlus_Base_PsrRequest, isSoap) {

	zval contentType, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("HTTP_SOAPACTION"))) {
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&contentType))) {
			RETURN_MM_BOOL(zephir_memnstr_str(&contentType, SL("application/soap+xml"), "phalconplus/Base/PsrRequest.zep", 174));
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getServerAddress) {

	zval serverAddr, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverAddr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&serverAddr);
	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&serverAddr, &_0, SL("SERVER_ADDR"), 0)) {
		RETURN_CCTOR(&serverAddr);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "localhost");
	ZEPHIR_RETURN_CALL_FUNCTION("gethostbyname", NULL, 56, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets active server name
 */
PHP_METHOD(PhalconPlus_Base_PsrRequest, getServerName) {

	zval serverName, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverName);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&serverName, &_0, SL("SERVER_NAME"), 1)) {
		RETURN_CTORW(&serverName);
	}
	RETURN_STRING("localhost");

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getHttpHost) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "gethost", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getPort) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getport", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getClientAddress) {

	zval *trustForwardedHeader_param = NULL, address, _0$$3, _1$$4, _2$$5, _3$$7, _4$$7;
	zend_bool trustForwardedHeader;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &trustForwardedHeader_param);

	if (!trustForwardedHeader_param) {
		trustForwardedHeader = 0;
	} else {
		trustForwardedHeader = zephir_get_boolval(trustForwardedHeader_param);
	}


	ZEPHIR_INIT_VAR(&address);
	ZVAL_NULL(&address);
	if (trustForwardedHeader) {
		ZEPHIR_OBS_NVAR(&address);
		zephir_read_property(&_0$$3, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		zephir_array_isset_string_fetch(&address, &_0$$3, SL("HTTP_X_FORWARDED_FOR"), 0);
		if (Z_TYPE_P(&address) == IS_NULL) {
			ZEPHIR_OBS_NVAR(&address);
			zephir_read_property(&_1$$4, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
			zephir_array_isset_string_fetch(&address, &_1$$4, SL("HTTP_CLIENT_IP"), 0);
		}
	}
	if (Z_TYPE_P(&address) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&address);
		zephir_read_property(&_2$$5, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		zephir_array_isset_string_fetch(&address, &_2$$5, SL("REMOTE_ADDR"), 0);
	}
	if (Z_TYPE_P(&address) == IS_STRING) {
		if (zephir_memnstr_str(&address, SL(","), "phalconplus/Base/PsrRequest.zep", 232)) {
			ZEPHIR_INIT_VAR(&_3$$7);
			zephir_fast_explode_str(&_3$$7, SL(","), &address, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&_4$$7, &_3$$7, 0, PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 236 TSRMLS_CC);
			RETURN_CTOR(&_4$$7);
		}
		RETURN_CCTOR(&address);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getUserAgent) {

	zval userAgent, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&userAgent);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&userAgent, &_0, SL("HTTP_USER_AGENT"), 1)) {
		RETURN_CTORW(&userAgent);
	}
	RETURN_STRING("");

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, hasFiles) {

	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zval *onlySuccessful_param = NULL, files, file, error, _0, *_1, _2, _4$$8, _5$$8, _8$$13, _9$$13;
	zend_bool onlySuccessful, _3$$6, _7$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}


	numberFiles = 0;
	zephir_read_property(&_0, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&files, &_0);
	if (Z_TYPE_P(&files) != IS_ARRAY) {
		RETURN_MM_LONG(0);
	}
	zephir_is_iterable(&files, 0, "phalconplus/Base/PsrRequest.zep", 280);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _1)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _1);
			ZEPHIR_OBS_NVAR(&error);
			if (zephir_array_isset_string_fetch(&error, &file, SL("error"), 0)) {
				if (Z_TYPE_P(&error) != IS_ARRAY) {
					_3$$6 = !zephir_is_true(&error);
					if (!(_3$$6)) {
						_3$$6 = !onlySuccessful;
					}
					if (_3$$6) {
						numberFiles++;
					}
				}
				if (Z_TYPE_P(&error) == IS_ARRAY) {
					if (onlySuccessful) {
						ZVAL_BOOL(&_5$$8, 1);
					} else {
						ZVAL_BOOL(&_5$$8, 0);
					}
					ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "hasfilehelper", &_6, 0, &error, &_5$$8);
					zephir_check_call_status();
					numberFiles += zephir_get_numberval(&_4$$8);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &files, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&error);
				if (zephir_array_isset_string_fetch(&error, &file, SL("error"), 0)) {
					if (Z_TYPE_P(&error) != IS_ARRAY) {
						_7$$11 = !zephir_is_true(&error);
						if (!(_7$$11)) {
							_7$$11 = !onlySuccessful;
						}
						if (_7$$11) {
							numberFiles++;
						}
					}
					if (Z_TYPE_P(&error) == IS_ARRAY) {
						if (onlySuccessful) {
							ZVAL_BOOL(&_9$$13, 1);
						} else {
							ZVAL_BOOL(&_9$$13, 0);
						}
						ZEPHIR_CALL_METHOD(&_8$$13, this_ptr, "hasfilehelper", &_6, 0, &error, &_9$$13);
						zephir_check_call_status();
						numberFiles += zephir_get_numberval(&_8$$13);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_LONG(numberFiles);

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getUploadedFiles) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zval files;
	zephir_fcall_cache_entry *_10 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *onlySuccessful_param = NULL, superFiles, prefix, input, smoothInput, file, dataFile, *_0$$3, _1$$3, _4$$4, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, *_11$$5, _12$$5, _14$$6, _15$$7, _16$$7, _17$$7, _20$$8, _21$$9, _22$$9, _23$$9, _24$$9, _26$$10, _27$$11, _28$$12, _29$$13, _30$$13, _31$$13, _32$$13, _33$$13, *_34$$13, _35$$13, _37$$14, _38$$15, _39$$15, _40$$15, _41$$15, _43$$16, _44$$17, _45$$17, _46$$17, _47$$17, _49$$18, _50$$19;
	zend_bool onlySuccessful, _13$$6, _19$$8, _25$$10, _36$$14, _42$$16, _48$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&superFiles);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&smoothInput);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&dataFile);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_39$$15);
	ZVAL_UNDEF(&_40$$15);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_43$$16);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_49$$18);
	ZVAL_UNDEF(&_50$$19);
	ZVAL_UNDEF(&files);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	ZEPHIR_OBS_VAR(&superFiles);
	zephir_read_property(&superFiles, this_ptr, SL("files"), PH_NOISY_CC);
	if (zephir_fast_count_int(&superFiles TSRMLS_CC) > 0) {
		zephir_is_iterable(&superFiles, 0, "phalconplus/Base/PsrRequest.zep", 322);
		if (Z_TYPE_P(&superFiles) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&superFiles), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&prefix);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&prefix, _3$$3);
				} else {
					ZVAL_LONG(&prefix, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&input);
				ZVAL_COPY(&input, _0$$3);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch_string(&_4$$4, &input, SL("name"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 293 TSRMLS_CC);
				if (Z_TYPE_P(&_4$$4) == IS_ARRAY) {
					zephir_array_fetch_string(&_5$$5, &input, SL("name"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 295 TSRMLS_CC);
					zephir_array_fetch_string(&_6$$5, &input, SL("type"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 296 TSRMLS_CC);
					zephir_array_fetch_string(&_7$$5, &input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 297 TSRMLS_CC);
					zephir_array_fetch_string(&_8$$5, &input, SL("size"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 298 TSRMLS_CC);
					zephir_array_fetch_string(&_9$$5, &input, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 299 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_10, 0, &_5$$5, &_6$$5, &_7$$5, &_8$$5, &_9$$5, &prefix);
					zephir_check_call_status();
					zephir_is_iterable(&smoothInput, 0, "phalconplus/Base/PsrRequest.zep", 316);
					if (Z_TYPE_P(&smoothInput) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&smoothInput), _11$$5)
						{
							ZEPHIR_INIT_NVAR(&file);
							ZVAL_COPY(&file, _11$$5);
							_13$$6 = onlySuccessful == 0;
							if (!(_13$$6)) {
								zephir_array_fetch_string(&_14$$6, &file, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 304 TSRMLS_CC);
								_13$$6 = ZEPHIR_IS_LONG(&_14$$6, 0);
							}
							if (_13$$6) {
								ZEPHIR_INIT_NVAR(&dataFile);
								zephir_create_array(&dataFile, 5, 0 TSRMLS_CC);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("name"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 306 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("name"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("type"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 307 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("type"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("tmp_name"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 308 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("tmp_name"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("size"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 309 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("size"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("error"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 311 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("error"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_16$$7);
								object_init_ex(&_16$$7, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
								zephir_array_fetch_string(&_17$$7, &file, SL("key"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 313 TSRMLS_CC);
								ZEPHIR_CALL_METHOD(NULL, &_16$$7, "__construct", &_18, 0, &dataFile, &_17$$7);
								zephir_check_call_status();
								zephir_array_append(&files, &_16$$7, PH_SEPARATE, "phalconplus/Base/PsrRequest.zep", 313);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &smoothInput, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_12$$5, &smoothInput, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_12$$5)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&file, &smoothInput, "current", NULL, 0);
							zephir_check_call_status();
								_19$$8 = onlySuccessful == 0;
								if (!(_19$$8)) {
									zephir_array_fetch_string(&_20$$8, &file, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 304 TSRMLS_CC);
									_19$$8 = ZEPHIR_IS_LONG(&_20$$8, 0);
								}
								if (_19$$8) {
									ZEPHIR_INIT_NVAR(&_21$$9);
									zephir_create_array(&_21$$9, 5, 0 TSRMLS_CC);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("name"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 306 TSRMLS_CC);
									zephir_array_update_string(&_21$$9, SL("name"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("type"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 307 TSRMLS_CC);
									zephir_array_update_string(&_21$$9, SL("type"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("tmp_name"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 308 TSRMLS_CC);
									zephir_array_update_string(&_21$$9, SL("tmp_name"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("size"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 309 TSRMLS_CC);
									zephir_array_update_string(&_21$$9, SL("size"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("error"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 311 TSRMLS_CC);
									zephir_array_update_string(&_21$$9, SL("error"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_CPY_WRT(&dataFile, &_21$$9);
									ZEPHIR_INIT_NVAR(&_23$$9);
									object_init_ex(&_23$$9, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
									zephir_array_fetch_string(&_24$$9, &file, SL("key"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 313 TSRMLS_CC);
									ZEPHIR_CALL_METHOD(NULL, &_23$$9, "__construct", &_18, 0, &dataFile, &_24$$9);
									zephir_check_call_status();
									zephir_array_append(&files, &_23$$9, PH_SEPARATE, "phalconplus/Base/PsrRequest.zep", 313);
								}
							ZEPHIR_CALL_METHOD(NULL, &smoothInput, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&file);
				} else {
					_25$$10 = onlySuccessful == 0;
					if (!(_25$$10)) {
						zephir_array_fetch_string(&_26$$10, &input, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 317 TSRMLS_CC);
						_25$$10 = ZEPHIR_IS_LONG(&_26$$10, 0);
					}
					if (_25$$10) {
						ZEPHIR_INIT_NVAR(&_27$$11);
						object_init_ex(&_27$$11, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
						ZEPHIR_CALL_METHOD(NULL, &_27$$11, "__construct", &_18, 0, &input, &prefix);
						zephir_check_call_status();
						zephir_array_append(&files, &_27$$11, PH_SEPARATE, "phalconplus/Base/PsrRequest.zep", 318);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &superFiles, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &superFiles, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&prefix, &superFiles, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&input, &superFiles, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&_28$$12);
					zephir_array_fetch_string(&_28$$12, &input, SL("name"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 293 TSRMLS_CC);
					if (Z_TYPE_P(&_28$$12) == IS_ARRAY) {
						zephir_array_fetch_string(&_29$$13, &input, SL("name"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 295 TSRMLS_CC);
						zephir_array_fetch_string(&_30$$13, &input, SL("type"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 296 TSRMLS_CC);
						zephir_array_fetch_string(&_31$$13, &input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 297 TSRMLS_CC);
						zephir_array_fetch_string(&_32$$13, &input, SL("size"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 298 TSRMLS_CC);
						zephir_array_fetch_string(&_33$$13, &input, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 299 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_10, 0, &_29$$13, &_30$$13, &_31$$13, &_32$$13, &_33$$13, &prefix);
						zephir_check_call_status();
						zephir_is_iterable(&smoothInput, 0, "phalconplus/Base/PsrRequest.zep", 316);
						if (Z_TYPE_P(&smoothInput) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&smoothInput), _34$$13)
							{
								ZEPHIR_INIT_NVAR(&file);
								ZVAL_COPY(&file, _34$$13);
								_36$$14 = onlySuccessful == 0;
								if (!(_36$$14)) {
									zephir_array_fetch_string(&_37$$14, &file, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 304 TSRMLS_CC);
									_36$$14 = ZEPHIR_IS_LONG(&_37$$14, 0);
								}
								if (_36$$14) {
									ZEPHIR_INIT_NVAR(&_38$$15);
									zephir_create_array(&_38$$15, 5, 0 TSRMLS_CC);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("name"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 306 TSRMLS_CC);
									zephir_array_update_string(&_38$$15, SL("name"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("type"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 307 TSRMLS_CC);
									zephir_array_update_string(&_38$$15, SL("type"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("tmp_name"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 308 TSRMLS_CC);
									zephir_array_update_string(&_38$$15, SL("tmp_name"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("size"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 309 TSRMLS_CC);
									zephir_array_update_string(&_38$$15, SL("size"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("error"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 311 TSRMLS_CC);
									zephir_array_update_string(&_38$$15, SL("error"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_CPY_WRT(&dataFile, &_38$$15);
									ZEPHIR_INIT_NVAR(&_40$$15);
									object_init_ex(&_40$$15, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
									zephir_array_fetch_string(&_41$$15, &file, SL("key"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 313 TSRMLS_CC);
									ZEPHIR_CALL_METHOD(NULL, &_40$$15, "__construct", &_18, 0, &dataFile, &_41$$15);
									zephir_check_call_status();
									zephir_array_append(&files, &_40$$15, PH_SEPARATE, "phalconplus/Base/PsrRequest.zep", 313);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &smoothInput, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_35$$13, &smoothInput, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_35$$13)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&file, &smoothInput, "current", NULL, 0);
								zephir_check_call_status();
									_42$$16 = onlySuccessful == 0;
									if (!(_42$$16)) {
										zephir_array_fetch_string(&_43$$16, &file, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 304 TSRMLS_CC);
										_42$$16 = ZEPHIR_IS_LONG(&_43$$16, 0);
									}
									if (_42$$16) {
										ZEPHIR_INIT_NVAR(&_44$$17);
										zephir_create_array(&_44$$17, 5, 0 TSRMLS_CC);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("name"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 306 TSRMLS_CC);
										zephir_array_update_string(&_44$$17, SL("name"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("type"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 307 TSRMLS_CC);
										zephir_array_update_string(&_44$$17, SL("type"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("tmp_name"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 308 TSRMLS_CC);
										zephir_array_update_string(&_44$$17, SL("tmp_name"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("size"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 309 TSRMLS_CC);
										zephir_array_update_string(&_44$$17, SL("size"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("error"), PH_NOISY, "phalconplus/Base/PsrRequest.zep", 311 TSRMLS_CC);
										zephir_array_update_string(&_44$$17, SL("error"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_CPY_WRT(&dataFile, &_44$$17);
										ZEPHIR_INIT_NVAR(&_46$$17);
										object_init_ex(&_46$$17, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
										zephir_array_fetch_string(&_47$$17, &file, SL("key"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 313 TSRMLS_CC);
										ZEPHIR_CALL_METHOD(NULL, &_46$$17, "__construct", &_18, 0, &dataFile, &_47$$17);
										zephir_check_call_status();
										zephir_array_append(&files, &_46$$17, PH_SEPARATE, "phalconplus/Base/PsrRequest.zep", 313);
									}
								ZEPHIR_CALL_METHOD(NULL, &smoothInput, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&file);
					} else {
						_48$$18 = onlySuccessful == 0;
						if (!(_48$$18)) {
							zephir_array_fetch_string(&_49$$18, &input, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 317 TSRMLS_CC);
							_48$$18 = ZEPHIR_IS_LONG(&_49$$18, 0);
						}
						if (_48$$18) {
							ZEPHIR_INIT_NVAR(&_50$$19);
							object_init_ex(&_50$$19, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
							ZEPHIR_CALL_METHOD(NULL, &_50$$19, "__construct", &_18, 0, &input, &prefix);
							zephir_check_call_status();
							zephir_array_append(&files, &_50$$19, PH_SEPARATE, "phalconplus/Base/PsrRequest.zep", 318);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &superFiles, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&input);
		ZEPHIR_INIT_NVAR(&prefix);
	}
	RETURN_CTOR(&files);

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getHTTPReferer) {

	zval httpReferer, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpReferer);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&httpReferer, &_0, SL("HTTP_REFERER"), 1)) {
		RETURN_CTORW(&httpReferer);
	}
	RETURN_STRING("");

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getContentType) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Content-Type");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getheaderline", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getBasicAuth) {

	zend_bool _1;
	zval auth, _0, _2, _3$$3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string(&_0, SL("PHP_AUTH_USER"));
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		_1 = zephir_array_isset_string(&_2, SL("PHP_AUTH_PW"));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&auth);
		array_init(&auth);
		zephir_read_property(&_3$$3, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_4$$3, &_3$$3, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 353 TSRMLS_CC);
		zephir_array_update_string(&auth, SL("username"), &_4$$3, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_5$$3, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_6$$3, &_5$$3, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 354 TSRMLS_CC);
		zephir_array_update_string(&auth, SL("password"), &_6$$3, PH_COPY | PH_SEPARATE);
		RETURN_CCTOR(&auth);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(PhalconPlus_Base_PsrRequest, getDigestAuth) {

	zval auth;
	zval digest, matches, match, _0, _1$$3, _2$$3, _3$$3, *_4$$5, _5$$5, _6$$6, _7$$6, _8$$7, _9$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&auth);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&auth);
	array_init(&auth);
	ZEPHIR_OBS_VAR(&digest);
	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&digest, &_0, SL("PHP_AUTH_DIGEST"), 0)) {
		ZEPHIR_INIT_VAR(&matches);
		array_init(&matches);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#");
		zephir_preg_match(&_2$$3, &_3$$3, &digest, &matches, 1, 2 , 0  TSRMLS_CC);
		if (!(zephir_is_true(&_2$$3))) {
			RETURN_CTOR(&auth);
		}
		if (Z_TYPE_P(&matches) == IS_ARRAY) {
			zephir_is_iterable(&matches, 0, "phalconplus/Base/PsrRequest.zep", 376);
			if (Z_TYPE_P(&matches) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _4$$5)
				{
					ZEPHIR_INIT_NVAR(&match);
					ZVAL_COPY(&match, _4$$5);
					zephir_array_fetch_long(&_6$$6, &match, 3, PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 374 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&_7$$6);
					zephir_array_fetch_long(&_7$$6, &match, 1, PH_NOISY, "phalconplus/Base/PsrRequest.zep", 374 TSRMLS_CC);
					zephir_array_update_zval(&auth, &_7$$6, &_6$$6, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &matches, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_5$$5, &matches, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_5$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&match, &matches, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_fetch_long(&_8$$7, &match, 3, PH_NOISY | PH_READONLY, "phalconplus/Base/PsrRequest.zep", 374 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&_9$$7);
						zephir_array_fetch_long(&_9$$7, &match, 1, PH_NOISY, "phalconplus/Base/PsrRequest.zep", 374 TSRMLS_CC);
						zephir_array_update_zval(&auth, &_9$$7, &_8$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&match);
		}
	}
	RETURN_CTOR(&auth);

}

zend_object *zephir_init_properties_PhalconPlus_Base_PsrRequest(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _10, _12, _14, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9, _15$$10;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("server"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("files"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("headers"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("cookies"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("attributes"), &_9$$7);
		}
		zephir_read_property(&_10, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval(this_ptr, SL("request"), &_11$$8);
		}
		zephir_read_property(&_12, this_ptr, SL("post"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval(this_ptr, SL("post"), &_13$$9);
		}
		zephir_read_property(&_14, this_ptr, SL("get"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_14) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_15$$10);
			array_init(&_15$$10);
			zephir_update_property_zval(this_ptr, SL("get"), &_15$$10);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

