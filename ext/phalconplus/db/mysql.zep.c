
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Db_Mysql) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Db, Mysql, phalconplus, db_mysql, phalconplus_db_mysql_method_entry, 0);

	zend_declare_property_null(phalconplus_db_mysql_ce, SL("di"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_mysql_ce, SL("descriptor"), ZEND_ACC_PRIVATE TSRMLS_CC);

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

	zval _3, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *di, di_sub, *name_param = NULL, config, dbConfig, _0, _4, _6, _7, _1$$3, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&dbConfig);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &di, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
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
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_4);
	zephir_read_property(&_4, &dbConfig, SL("host"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("host"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_read_property(&_4, &dbConfig, SL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("port"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_read_property(&_4, &dbConfig, SL("username"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("username"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_read_property(&_4, &dbConfig, SL("password"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("password"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_read_property(&_4, &dbConfig, SL("dbname"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("dbname"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 3, 0 TSRMLS_CC);
	zephir_read_property(&_6, &dbConfig, SL("charset"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SV(&_7, "SET NAMES ", &_6);
	zephir_array_update_long(&_5, 1002, &_7, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_read_property(&_4, &dbConfig, SL("timeout"), PH_NOISY_CC);
	zephir_array_update_long(&_5, 2, &_4, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	add_index_long(&_5, 3, 2);
	zephir_array_update_string(&_3, SL("options"), &_5, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("descriptor"), &_3);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_Mysql, getConnection) {

	zval __$true, __$false, tryTimes, e, _0, _1$$4, _2$$4, _4$$3, _5$$5, _6$$5, _7$$5, _9$$5, _12$$6, _14$$6, _15$$6, _16$$6, _17$$6, _18$$7, _19$$7, _20$$7;
	zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL, *_10 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _11$$5;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&tryTimes);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&tryTimes);
	zephir_read_property(&tryTimes, this_ptr, SL("retryTimes"), PH_NOISY_CC);
	while (1) {
		zephir_read_property(&_0, this_ptr, SL("connected"), PH_NOISY_CC | PH_READONLY);
		if (!(!(zephir_is_true(&_0)))) {
			break;
		}

		/* try_start_1: */

			ZEPHIR_INIT_NVAR(&_1$$4);
			object_init_ex(&_1$$4, zephir_get_internal_ce(SL("phalcon\\db\\adapter\\pdo\\mysql")));
			zephir_read_property(&_2$$4, this_ptr, SL("descriptor"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", &_3, 0, &_2$$4);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_zval(this_ptr, SL("connection"), &_1$$4);
			if (1) {
				zephir_update_property_zval(this_ptr, SL("connected"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("connected"), &__$false);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_OBJ(&_4$$3, EG(exception));
			Z_ADDREF_P(&_4$$3);
			if (zephir_instance_of_ev(&_4$$3, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_4$$3);
				ZEPHIR_INIT_NVAR(&_5$$5);
				zephir_read_property(&_6$$5, this_ptr, SL("descriptor"), PH_NOISY_CC | PH_READONLY);
				zephir_json_encode(&_5$$5, &_6$$5, 0 );
				ZEPHIR_CALL_FUNCTION(&_7$$5, "strval", &_8, 24, &tryTimes);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_9$$5);
				ZEPHIR_CONCAT_SVSVS(&_9$$5, "PHP Fatal error:  PhalconPlus::Db::MySQL::connect() failed to connect to MySQL. Detail: ", &_5$$5, ". We will try ", &_7$$5, " times for you.");
				ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_10, 53, &_9$$5);
				zephir_check_call_status();
				_11$$5 = (zephir_get_numberval(&tryTimes) - 1);
				ZEPHIR_INIT_NVAR(&tryTimes);
				ZVAL_LONG(&tryTimes, _11$$5);
				if (ZEPHIR_GT_LONG(&tryTimes, 0)) {
					zephir_read_property(&_12$$6, this_ptr, SL("retryInterval"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_13, 54, &_12$$6);
					zephir_check_call_status();
					zephir_read_property(&_14$$6, this_ptr, SL("retryTimes"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_SINIT_NVAR(_15$$6);
					zephir_sub_function(&_15$$6, &_14$$6, &tryTimes);
					ZEPHIR_CALL_FUNCTION(&_16$$6, "strval", &_8, 24, &_15$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_17$$6);
					ZEPHIR_CONCAT_SVS(&_17$$6, "PHP Notice:  PhalconPlus::Db::MySQL::connnect() retry to connect to MySQL for the ", &_16$$6, " time ... ");
					ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_10, 53, &_17$$6);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_18$$7);
					zephir_read_property(&_19$$7, this_ptr, SL("descriptor"), PH_NOISY_CC | PH_READONLY);
					zephir_json_encode(&_18$$7, &_19$$7, 0 );
					ZEPHIR_INIT_LNVAR(_20$$7);
					ZEPHIR_CONCAT_SV(&_20$$7, "PHP Fatal error:  PhalconPlus::Db::MySQL::connect() finally failed to connect to MySQL. Detail: ", &_18$$7);
					ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_10, 53, &_20$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&e, "phalconplus/Db/Mysql.zep", 68 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	RETURN_MM_MEMBER(getThis(), "connection");

}

zend_object *zephir_init_properties_PhalconPlus_Db_Mysql(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("descriptor"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("descriptor"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

