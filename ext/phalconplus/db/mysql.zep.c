
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Db_Mysql) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Db, Mysql, phalconplus, db_mysql, phalconplus_db_mysql_method_entry, 0);

	zend_declare_property_null(phalconplus_db_mysql_ce, SL("di"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_mysql_ce, SL("descriptor"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_mysql_ce, SL("options"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(phalconplus_db_mysql_ce, SL("retryTimes"), 5, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(phalconplus_db_mysql_ce, SL("retryInterval"), 100000, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_mysql_ce, SL("name"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_mysql_ce, SL("connection"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_bool(phalconplus_db_mysql_ce, SL("connected"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	phalconplus_db_mysql_ce->create_object = zephir_init_properties_PhalconPlus_Db_Mysql;
	zephir_declare_class_constant_long(phalconplus_db_mysql_ce, SL("RETRY_TIMES"), 5);

	zephir_declare_class_constant_long(phalconplus_db_mysql_ce, SL("RETRY_INTERVAL"), 100000);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_Mysql, __construct) {

	zval _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *di, di_sub, *name_param = NULL, config, dbConfig, _0, options, _3, _4, _5, _1$$3, _2$$4, _6$$5, _7$$5, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&dbConfig);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &di, &name_param);

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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "config");
	ZEPHIR_CALL_METHOD(&config, di, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&dbConfig);
	zephir_read_property_zval(&dbConfig, &config, &name, PH_NOISY_CC);
	zephir_update_property_zval(this_ptr, SL("di"), di);
	zephir_update_property_zval(this_ptr, SL("name"), &name);
	if (zephir_isset_property(&dbConfig, SL("retryTimes"))) {
		zephir_read_property(&_1$$3, &dbConfig, SL("retryTimes"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("retryTimes"), &_1$$3);
	}
	if (zephir_isset_property(&dbConfig, SL("retryInterval"))) {
		zephir_read_property(&_2$$4, &dbConfig, SL("retryInterval"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("retryInterval"), &_2$$4);
	}
	ZEPHIR_INIT_VAR(&options);
	zephir_create_array(&options, 3, 0 TSRMLS_CC);
	zephir_read_property(&_3, &dbConfig, SL("charset"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "SET NAMES ", &_3);
	zephir_array_update_long(&options, 1002, &_4, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, &dbConfig, SL("timeout"), PH_NOISY_CC);
	zephir_array_update_long(&options, 2, &_5, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	add_index_long(&options, 3, 2);
	if (zephir_isset_property(&dbConfig, SL("options"))) {
		zephir_read_property(&_6$$5, &dbConfig, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7$$5, &_6$$5, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$5);
		zephir_add_function(&_8$$5, &_7$$5, &options);
		zephir_update_property_zval(this_ptr, SL("options"), &_8$$5);
	} else {
		zephir_update_property_zval(this_ptr, SL("options"), &options);
	}
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_read_property(&_5, &dbConfig, SL("host"), PH_NOISY_CC);
	zephir_array_update_string(&_9, SL("host"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_read_property(&_5, &dbConfig, SL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_9, SL("port"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_read_property(&_5, &dbConfig, SL("username"), PH_NOISY_CC);
	zephir_array_update_string(&_9, SL("username"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_read_property(&_5, &dbConfig, SL("password"), PH_NOISY_CC);
	zephir_array_update_string(&_9, SL("password"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_read_property(&_5, &dbConfig, SL("dbname"), PH_NOISY_CC);
	zephir_array_update_string(&_9, SL("dbname"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("options"), PH_NOISY_CC);
	zephir_array_update_string(&_9, SL("options"), &_5, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("descriptor"), &_9);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_Mysql, getConnection) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL, *_12 = NULL, *_14 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _15$$7;
	zval *autoConnect_param = NULL, __$true, __$false, tryTimes, e, _0, _1$$5, _2$$5, _4$$6, _5$$6, _6$$6, _8$$3, _9$$7, _10$$7, _11$$7, _13$$7, _16$$8, _18$$8, _19$$8, _20$$8, _21$$8, _22$$9, _23$$9, _24$$9;
	zend_bool autoConnect;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&tryTimes);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &autoConnect_param);

	if (!autoConnect_param) {
		autoConnect = 1;
	} else {
		autoConnect = zephir_get_boolval(autoConnect_param);
	}


	ZEPHIR_OBS_VAR(&tryTimes);
	zephir_read_property(&tryTimes, this_ptr, SL("retryTimes"), PH_NOISY_CC);
	while (1) {
		zephir_read_property(&_0, this_ptr, SL("connected"), PH_NOISY_CC | PH_READONLY);
		if (!(!(zephir_is_true(&_0)))) {
			break;
		}

		/* try_start_1: */

			if (autoConnect == 1) {
				ZEPHIR_INIT_NVAR(&_1$$5);
				object_init_ex(&_1$$5, zephir_get_internal_ce(SL("phalcon\\db\\adapter\\pdo\\mysql")));
				zephir_read_property(&_2$$5, this_ptr, SL("descriptor"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", &_3, 0, &_2$$5);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_update_property_zval(this_ptr, SL("connection"), &_1$$5);
			} else {
				ZEPHIR_INIT_NVAR(&_4$$6);
				object_init_ex(&_4$$6, phalconplus_db_pdo_mysql_ce);
				zephir_read_property(&_5$$6, this_ptr, SL("descriptor"), PH_NOISY_CC | PH_READONLY);
				if (autoConnect) {
					ZVAL_BOOL(&_6$$6, 1);
				} else {
					ZVAL_BOOL(&_6$$6, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", &_7, 67, &_5$$6, &_6$$6);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_update_property_zval(this_ptr, SL("connection"), &_4$$6);
			}
			if (1) {
				zephir_update_property_zval(this_ptr, SL("connected"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("connected"), &__$false);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_OBJ(&_8$$3, EG(exception));
			Z_ADDREF_P(&_8$$3);
			if (zephir_instance_of_ev(&_8$$3, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_8$$3);
				ZEPHIR_INIT_NVAR(&_9$$7);
				zephir_read_property(&_10$$7, this_ptr, SL("descriptor"), PH_NOISY_CC | PH_READONLY);
				zephir_json_encode(&_9$$7, &_10$$7, 0 );
				ZEPHIR_CALL_FUNCTION(&_11$$7, "strval", &_12, 31, &tryTimes);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13$$7);
				ZEPHIR_CONCAT_SVSVS(&_13$$7, "PHP Fatal error:  PhalconPlus::Db::MySQL::connect() failed to connect to MySQL. Detail: ", &_9$$7, ". We will try ", &_11$$7, " times for you.");
				ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_14, 54, &_13$$7);
				zephir_check_call_status();
				_15$$7 = (zephir_get_numberval(&tryTimes) - 1);
				ZEPHIR_INIT_NVAR(&tryTimes);
				ZVAL_LONG(&tryTimes, _15$$7);
				if (ZEPHIR_GT_LONG(&tryTimes, 0)) {
					zephir_read_property(&_16$$8, this_ptr, SL("retryInterval"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_17, 68, &_16$$8);
					zephir_check_call_status();
					zephir_read_property(&_18$$8, this_ptr, SL("retryTimes"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_SINIT_NVAR(_19$$8);
					zephir_sub_function(&_19$$8, &_18$$8, &tryTimes);
					ZEPHIR_CALL_FUNCTION(&_20$$8, "strval", &_12, 31, &_19$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_21$$8);
					ZEPHIR_CONCAT_SVS(&_21$$8, "PHP Notice:  PhalconPlus::Db::MySQL::connnect() retry to connect to MySQL for the ", &_20$$8, " time ... ");
					ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_14, 54, &_21$$8);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_22$$9);
					zephir_read_property(&_23$$9, this_ptr, SL("descriptor"), PH_NOISY_CC | PH_READONLY);
					zephir_json_encode(&_22$$9, &_23$$9, 0 );
					ZEPHIR_INIT_LNVAR(_24$$9);
					ZEPHIR_CONCAT_SV(&_24$$9, "PHP Fatal error:  PhalconPlus::Db::MySQL::connect() finally failed to connect to MySQL. Detail: ", &_22$$9);
					ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_14, 54, &_24$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&e, "phalconplus/Db/Mysql.zep", 82 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	RETURN_MM_MEMBER(getThis(), "connection");

}

zend_object *zephir_init_properties_PhalconPlus_Db_Mysql(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("descriptor"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("descriptor"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

