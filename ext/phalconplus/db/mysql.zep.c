
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

	zend_declare_class_constant_long(phalconplus_db_mysql_ce, SL("RETRY_TIMES"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_db_mysql_ce, SL("RETRY_INTERVAL"), 100000 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_Mysql, __construct) {

	zval *_2, *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL;
	zval *di, *name_param = NULL, *config = NULL, *dbConfig, *_0, *_1 = NULL, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &di, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	if (EG(called_scope) == phalconplus_db_mysql_ce) {
		zephir_init_properties(this_ptr TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&config, di, "get", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(dbConfig);
	zephir_read_property_zval(&dbConfig, config, name, PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	if (zephir_isset_property(dbConfig, SS("retryTimes") TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property(&_1, dbConfig, SL("retryTimes"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("retryTimes"), _1 TSRMLS_CC);
	}
	if (zephir_isset_property(dbConfig, SS("retryInterval") TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(_1);
		zephir_read_property(&_1, dbConfig, SL("retryInterval"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("retryInterval"), _1 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property(&_1, dbConfig, SL("host"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("host"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property(&_1, dbConfig, SL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("port"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property(&_1, dbConfig, SL("username"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("username"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property(&_1, dbConfig, SL("password"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("password"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property(&_1, dbConfig, SL("dbname"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("dbname"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 3, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property(&_1, dbConfig, SL("charset"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "SET NAMES ", _1);
	zephir_array_update_long(&_3, 1002, &_4, PH_COPY, "phalconplus/Db/Mysql.zep", 44);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property(&_5, dbConfig, SL("timeout"), PH_NOISY_CC);
	zephir_array_update_long(&_3, 2, &_5, PH_COPY, "phalconplus/Db/Mysql.zep", 44);
	add_index_long(_3, 3, 2);
	zephir_array_update_string(&_2, SL("options"), &_3, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("descriptor"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_Mysql, getConnection) {

	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_7 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, _8;
	zval *tryTimes = NULL, *e = NULL, *_0, *_1 = NULL, *_2, *_4 = NULL, *_6 = NULL, *_9, *_11, _12 = zval_used_for_init, *_13 = NULL, *_14 = NULL, *_15 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(tryTimes);
	zephir_read_property_this(&tryTimes, this_ptr, SL("retryTimes"), PH_NOISY_CC);
	while (1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("connected"), PH_NOISY_CC);
		if (!(!(zephir_is_true(_0)))) {
			break;
		}

		/* try_start_1: */

			ZEPHIR_INIT_NVAR(_1);
			object_init_ex(_1, zephir_get_internal_ce(SS("phalcon\\db\\adapter\\pdo\\mysql") TSRMLS_CC));
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("descriptor"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_3, 0, _2);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_this(this_ptr, SL("connection"), _1 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("connected"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_INIT_NVAR(_1);
				_2 = zephir_fetch_nproperty_this(this_ptr, SL("descriptor"), PH_NOISY_CC);
				zephir_json_encode(_1, &(_1), _2, 0  TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(&_4, "strval", &_5, 4, tryTimes);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVSVS(_6, "PHP Fatal error:  PhalconPlus::Db::MySQL::connect() failed to connect to MySQL. Detail: ", _1, ". We will try ", _4, " times for you.");
				ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_7, 38, _6);
				zephir_check_call_status();
				_8 = (zephir_get_numberval(tryTimes) - 1);
				ZEPHIR_INIT_NVAR(tryTimes);
				ZVAL_LONG(tryTimes, _8);
				if (ZEPHIR_GT_LONG(tryTimes, 0)) {
					_9 = zephir_fetch_nproperty_this(this_ptr, SL("retryInterval"), PH_NOISY_CC);
					ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_10, 39, _9);
					zephir_check_call_status();
					_11 = zephir_fetch_nproperty_this(this_ptr, SL("retryTimes"), PH_NOISY_CC);
					ZEPHIR_SINIT_NVAR(_12);
					sub_function(&_12, _11, tryTimes TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(&_13, "strval", &_5, 4, &_12);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_14);
					ZEPHIR_CONCAT_SVS(_14, "PHP Notice:  PhalconPlus::Db::MySQL::connnect() retry to connect to MySQL for the ", _13, " time ... ");
					ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_7, 38, _14);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(_15);
					_9 = zephir_fetch_nproperty_this(this_ptr, SL("descriptor"), PH_NOISY_CC);
					zephir_json_encode(_15, &(_15), _9, 0  TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_14);
					ZEPHIR_CONCAT_SV(_14, "PHP Fatal error:  PhalconPlus::Db::MySQL::connect() finally failed to connect to MySQL. Detail: ", _15);
					ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_7, 38, _14);
					zephir_check_call_status();
					zephir_throw_exception_debug(e, "phalconplus/Db/Mysql.zep", 68 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	RETURN_MM_MEMBER(this_ptr, "connection");

}

static void zephir_init_properties(zval *this_ptr TSRMLS_DC) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("descriptor"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

