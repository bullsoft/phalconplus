
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_FeatureTest_SplObjectStorageTest) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\FeatureTest, SplObjectStorageTest, phalconplus, featuretest_splobjectstoragetest, phalconplus_featuretest_splobjectstoragetest_method_entry, 0);

	zend_declare_property_null(phalconplus_featuretest_splobjectstoragetest_ce, SL("objects"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_FeatureTest_SplObjectStorageTest, __construct) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("objects"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_FeatureTest_SplObjectStorageTest, insert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data, _2;
	zval *name, name_sub, *obj, obj_sub, *data_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&obj_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name, &obj, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	zephir_read_property(&_0, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "detach", NULL, 0, obj);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("name"), name, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_2, SL("method"), SL("insert"));
	zephir_array_update_string(&_2, SL("initial_data"), &data, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_1, "attach", NULL, 0, obj, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_FeatureTest_SplObjectStorageTest, exec) {

	zval obj, info, _0, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_1, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2, &_1, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_2))) {
			break;
		}
		zephir_read_property(&_3$$3, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&obj, &_3$$3, "current", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&info, &_4$$3, "getinfo", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_5$$3, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_6$$3, &_5$$3, "key", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_string(&_7$$3, &info, SL("name"), PH_NOISY | PH_READONLY, "phalconplus/FeatureTest/SplObjectStorageTest.zep", 29 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_8$$3);
		zephir_get_class(&_8$$3, &obj, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_9$$3);
		ZEPHIR_GET_CONSTANT(&_9$$3, "PHP_EOL");
		ZEPHIR_INIT_LNVAR(_10$$3);
		ZEPHIR_CONCAT_SVSVSVV(&_10$$3, "Key: ", &_6$$3, " Name: ", &_7$$3, " Obj: ", &_8$$3, &_9$$3);
		zend_print_zval(&_10$$3, 0);
		zephir_read_property(&_11$$3, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_11$$3, "next", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

