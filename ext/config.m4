PHP_ARG_ENABLE(phalconplus, whether to enable phalconplus, [ --enable-phalconplus   Enable Phalconplus])

if test "$PHP_PHALCONPLUS" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PHALCONPLUS_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PHALCONPLUS, 1, [Whether you have Phalconplus])
	phalconplus_sources="phalconplus.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c phalconplus/base/protobuffer.zep.c
	phalconplus/enum/abstractenum.zep.c
	phalconplus/db/unitofwork/abstractvalue.zep.c
	phalconplus/logger/processor/abstractprocessor.zep.c
	phalconplus/rpc/client/abstractclient.zep.c
	phalconplus/assert/assertionfailedexception.zep.c
	phalconplus/base/abstractrequest.zep.c
	phalconplus/base/abstractresponse.zep.c
	phalconplus/rpc/server/abstractserver.zep.c
	phalconplus/assert/assertion.zep.c
	phalconplus/assert/invalidargumentexception.zep.c
	phalconplus/base/abstractmodule.zep.c
	phalconplus/base/exception.zep.c
	phalconplus/base/model.zep.c
	phalconplus/base/moduledef.zep.c
	phalconplus/base/pagable.zep.c
	phalconplus/base/page.zep.c
	phalconplus/base/protoorderby.zep.c
	phalconplus/base/service.zep.c
	phalconplus/base/simplerequest.zep.c
	phalconplus/base/simpleresponse.zep.c
	phalconplus/bootstrap.zep.c
	phalconplus/db/mysql.zep.c
	phalconplus/db/unitofwork.zep.c
	phalconplus/db/unitofwork/field.zep.c
	phalconplus/db/unitofwork/lastinsertid.zep.c
	phalconplus/enum/assertioncode.zep.c
	phalconplus/enum/exception.zep.c
	phalconplus/enum/orderbydirection.zep.c
	phalconplus/enum/runenv.zep.c
	phalconplus/enum/runmode.zep.c
	phalconplus/enum/sys.zep.c
	phalconplus/http/psrrequest.zep.c
	phalconplus/logger/adapter/fileplus.zep.c
	phalconplus/logger/formatter/lineplus.zep.c
	phalconplus/logger/processor/trace.zep.c
	phalconplus/logger/processor/uid.zep.c
	phalconplus/mvc/psrapplication.zep.c
	phalconplus/rpc/client/adapter/local.zep.c
	phalconplus/rpc/client/adapter/remote.zep.c
	phalconplus/rpc/server/simpleserver.zep.c
	phalconplus/volt/extension/phpfunction.zep.c
	phalconplus/0__closure.zep.c
	phalconplus/1__closure.zep.c
	phalconplus/2__closure.zep.c "
	PHP_NEW_EXTENSION(phalconplus, $phalconplus_sources, $ext_shared,, )
	PHP_SUBST(PHALCONPLUS_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phalconplus], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phalconplus], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/phalconplus], [php_PHALCONPLUS.h])

fi
