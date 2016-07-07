
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PHALCONPLUS_H
#define PHP_PHALCONPLUS_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_PHALCONPLUS_NAME        "phalconplus"
#define PHP_PHALCONPLUS_VERSION     "1.0.0-dev"
#define PHP_PHALCONPLUS_EXTNAME     "phalconplus"
#define PHP_PHALCONPLUS_AUTHOR      "Gu Weigang<guweigang@outlook.com> and NCF Group"
#define PHP_PHALCONPLUS_ZEPVERSION  "0.9.3a-dev"
#define PHP_PHALCONPLUS_DESCRIPTION "Phalcon+ is a new framework based on Phalcon."



ZEND_BEGIN_MODULE_GLOBALS(phalconplus)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(phalconplus)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(phalconplus)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(phalconplus_globals_id, zend_phalconplus_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (phalconplus_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_phalconplus_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(phalconplus_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(phalconplus_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def phalconplus_globals
#define zend_zephir_globals_def zend_phalconplus_globals

extern zend_module_entry phalconplus_module_entry;
#define phpext_phalconplus_ptr &phalconplus_module_entry

#endif
