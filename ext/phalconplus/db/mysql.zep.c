
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
	zend_declare_class_constant_long(phalconplus_db_mysql_ce, SL("RETRY_TIMES"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_db_mysql_ce, SL("RETRY_INTERVAL"), 100000 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_Mysql, __construct) {

	zval *_3, *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL;
	zval *di, *name_param = NULL, *config = NULL, *dbConfig = NULL, *_0, *_4 = NULL, *_6, *_7, *_1$$3, *_2$$4;

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
		ZEPHIR_OBS_VAR(_1$$3);
		zephir_read_property(&_1$$3, dbConfig, SL("retryTimes"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("retryTimes"), _1$$3 TSRMLS_CC);
	}
	if (zephir_isset_property(dbConfig, SS("retryInterval") TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_2$$4);
		zephir_read_property(&_2$$4, dbConfig, SL("retryInterval"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("retryInterval"), _2$$4 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, dbConfig, SL("host"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("host"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_4);
	zephir_read_property(&_4, dbConfig, SL("port"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("port"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_4);
	zephir_read_property(&_4, dbConfig, SL("username"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("username"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_4);
	zephir_read_property(&_4, dbConfig, SL("password"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("password"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_4);
	zephir_read_property(&_4, dbConfig, SL("dbname"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("dbname"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 3, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_4);
	zephir_read_property(&_4, dbConfig, SL("charset"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SV(_6, "SET NAMES ", _4);
	zephir_array_update_long(&_5, 1002, &_6, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property(&_7, dbConfig, SL("timeout"), PH_NOISY_CC);
	zephir_array_update_long(&_5, 2, &_7, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	add_index_long(_5, 3, 2);
	zephir_array_update_string(&_3, SL("options"), &_5, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("descriptor"), _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_Mysql, getConnection) {

	zval *tryTimes = NULL, *e = NULL, *_0, *_1$$4 = NULL, *_2$$4, *_4$$5 = NULL, *_5$$5, *_6$$5 = NULL, *_8$$5 = NULL, *_11$$6, *_13$$6, _14$$6 = zval_used_for_init, *_15$$6 = NULL, *_16$$6 = NULL, *_17$$7 = NULL, *_18$$7, *_19$$7 = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL, *_9 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, _10$$5;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(tryTimes);
	zephir_read_property_this(&tryTimes, this_ptr, SL("retryTimes"), PH_NOISY_CC);
	while (1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("connected"), PH_NOISY_CC);
		if (!(!(zephir_is_true(_0)))) {
			break;
		}

		/* try_start_1: */

			ZEPHIR_INIT_NVAR(_1$$4);
			object_init_ex(_1$$4, zephir_get_internal_ce(SS("phalcon\\db\\adapter\\pdo\\mysql") TSRMLS_CC));
			_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("descriptor"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", &_3, 0, _2$$4);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_this(this_ptr, SL("connection"), _1$$4 TSRMLS_CC);
			if (1) {
				zephir_update_property_this(this_ptr, SL("connected"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(this_ptr, SL("connected"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_INIT_NVAR(_4$$5);
				_5$$5 = zephir_fetch_nproperty_this(this_ptr, SL("descriptor"), PH_NOISY_CC);
				zephir_json_encode(_4$$5, &(_4$$5), _5$$5, 0  TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(&_6$$5, "strval", &_7, 21, tryTimes);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_8$$5);
				ZEPHIR_CONCAT_SVSVS(_8$$5, "PHP Fatal error:  PhalconPlus::Db::MySQL::connect() failed to connect to MySQL. Detail: ", _4$$5, ". We will try ", _6$$5, " times for you.");
				ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_9, 52, _8$$5);
				zephir_check_call_status();
				_10$$5 = (zephir_get_numberval(tryTimes) - 1);
				ZEPHIR_INIT_NVAR(tryTimes);
				ZVAL_LONG(tryTimes, _10$$5);
				if (ZEPHIR_GT_LONG(tryTimes, 0)) {
					_11$$6 = zephir_fetch_nproperty_this(this_ptr, SL("retryInterval"), PH_NOISY_CC);
					ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_12, 53, _11$$6);
					zephir_check_call_status();
					_13$$6 = zephir_fetch_nproperty_this(this_ptr, SL("retryTimes"), PH_NOISY_CC);
					ZEPHIR_SINIT_NVAR(_14$$6);
					zephir_sub_function(&_14$$6, _13$$6, tryTimes);
					ZEPHIR_CALL_FUNCTION(&_15$$6, "strval", &_7, 21, &_14$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_16$$6);
					ZEPHIR_CONCAT_SVS(_16$$6, "PHP Notice:  PhalconPlus::Db::MySQL::connnect() retry to connect to MySQL for the ", _15$$6, " time ... ");
					ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_9, 52, _16$$6);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(_17$$7);
					_18$$7 = zephir_fetch_nproperty_this(this_ptr, SL("descriptor"), PH_NOISY_CC);
					zephir_json_encode(_17$$7, &(_17$$7), _18$$7, 0  TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_19$$7);
					ZEPHIR_CONCAT_SV(_19$$7, "PHP Fatal error:  PhalconPlus::Db::MySQL::connect() finally failed to connect to MySQL. Detail: ", _17$$7);
					ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_9, 52, _19$$7);
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

zend_object_value zephir_init_properties_PhalconPlus_Db_Mysql(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("descriptor"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("descriptor"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

