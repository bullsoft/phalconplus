
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
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

	zend_declare_class_constant_long(phalconplus_db_mysql_ce, SL("TRY_TIMES"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_db_mysql_ce, SL("RETRY_WAIT"), 100000 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_Mysql, __construct) {

	zval *_2, *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *confName = NULL;
	zval *di, *confName_param = NULL, *_0, *config = NULL, *dbConfig, *_1, *_3 = NULL, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &di, &confName_param);

	if (unlikely(Z_TYPE_P(confName_param) != IS_STRING && Z_TYPE_P(confName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'confName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(confName_param) == IS_STRING)) {
		zephir_get_strval(confName, confName_param);
	} else {
		ZEPHIR_INIT_VAR(confName);
		ZVAL_EMPTY_STRING(confName);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("descriptor"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&config, di, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(dbConfig);
	zephir_read_property_zval(&dbConfig, config, confName, PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, dbConfig, SL("host"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("host"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_3);
	zephir_read_property(&_3, dbConfig, SL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("port"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_3);
	zephir_read_property(&_3, dbConfig, SL("username"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("username"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_3);
	zephir_read_property(&_3, dbConfig, SL("password"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("password"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_3);
	zephir_read_property(&_3, dbConfig, SL("dbname"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("dbname"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 3, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_3);
	zephir_read_property(&_3, dbConfig, SL("charset"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SV(_5, "SET NAMES ", _3);
	zephir_array_update_long(&_4, 1002, &_5, PH_COPY, "phalconplus/Db/Mysql.zep", 29);
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property(&_6, dbConfig, SL("timeout"), PH_NOISY_CC);
	zephir_array_update_long(&_4, 2, &_6, PH_COPY, "phalconplus/Db/Mysql.zep", 29);
	add_index_long(_4, 3, 2);
	zephir_array_update_string(&_2, SL("options"), &_4, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("descriptor"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_Mysql, getConnection) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, _5;
	zval *connection = NULL, *tryTimes = NULL, *e = NULL, *_0, *_2 = NULL, *_3 = NULL, _6 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(connection);
	ZVAL_NULL(connection);

	ZEPHIR_INIT_VAR(tryTimes);
	ZVAL_LONG(tryTimes, 5);
	while (1) {
		if (!(!(Z_TYPE_P(connection) == IS_OBJECT))) {
			break;
		}

		/* try_start_1: */

			ZEPHIR_INIT_NVAR(connection);
			object_init_ex(connection, zephir_get_internal_ce(SS("phalcon\\db\\adapter\\pdo\\mysql") TSRMLS_CC));
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("descriptor"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, connection, "__construct", &_1, _0);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_is_instance_of(e, SL("PhalconPlus\\Db\\Exception") TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_INIT_NVAR(_2);
				_0 = zephir_fetch_nproperty_this(this_ptr, SL("descriptor"), PH_NOISY_CC);
				zephir_json_encode(_2, &(_2), _0, 0  TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SV(_3, "PHP Fatal error:  PhalconPlus::Db::MySQL::connect() failed to connect to MySQL. Detail: ", _2);
				ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_4, _3);
				zephir_check_call_status();
				_5 = (zephir_get_numberval(tryTimes) - 1);
				ZEPHIR_INIT_NVAR(tryTimes);
				ZVAL_LONG(tryTimes, _5);
				if (ZEPHIR_GT_LONG(tryTimes, 0)) {
					ZEPHIR_SINIT_NVAR(_6);
					ZVAL_LONG(&_6, 100000);
					ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_7, &_6);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_6);
					ZVAL_STRING(&_6, "PHP Notice:  PhalconPlus::Db::MySQL::connnect() retry to connect to MySQL for the time ... ", 0);
					ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_4, &_6);
					zephir_check_call_status();
				} else {
					ZEPHIR_SINIT_NVAR(_6);
					ZVAL_STRING(&_6, "PHP Fatal error:  PhalconPlus::Db::MySQL::connect() finally failed to connect to MySQL", 0);
					ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_4, &_6);
					zephir_check_call_status();
					zephir_throw_exception_debug(e, "phalconplus/Db/Mysql.zep", 52 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	RETURN_CCTOR(connection);

}

