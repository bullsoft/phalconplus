
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(phalconplus_3__closure) {

	ZEPHIR_REGISTER_CLASS(phalconplus, 3__closure, phalconplus, 3__closure, phalconplus_3__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalconplus_3__closure, __invoke) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *iterator, iterator_sub, __$null, m, metaData, columnMap, whiteList, attrField, _0$$3, *_1$$3, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&iterator_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&whiteList);
	ZVAL_UNDEF(&attrField);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &iterator);



	ZEPHIR_CALL_METHOD(&m, iterator, "current", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&metaData, &m, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, &m);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&whiteList);
	array_init(&whiteList);
	if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_is_iterable(&columnMap, 0, "phalconplus/Db/UnitOfWork.zep", 198);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columnMap), _2$$3, _3$$3, _1$$3)
		{
			ZEPHIR_INIT_NVAR(&_0$$3);
			if (_3$$3 != NULL) { 
				ZVAL_STR_COPY(&_0$$3, _3$$3);
			} else {
				ZVAL_LONG(&_0$$3, _2$$3);
			}
			ZEPHIR_INIT_NVAR(&attrField);
			ZVAL_COPY(&attrField, _1$$3);
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_read_property_zval(&_4$$4, &m, &attrField, PH_NOISY_CC);
			if (ZEPHIR_IS_EMPTY(&_4$$4)) {
				zephir_array_update_zval(&whiteList, &attrField, &__$null, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&attrField);
		ZEPHIR_INIT_NVAR(&_0$$3);
	}
	ZEPHIR_CALL_METHOD(NULL, &m, "setsnapshotdata", NULL, 0, &whiteList);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

