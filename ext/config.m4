PHP_ARG_ENABLE(phalconplus, whether to enable phalconplus, [ --enable-phalconplus   Enable Phalconplus])

if test "$PHP_PHALCONPLUS" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PHALCONPLUS_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PHALCONPLUS, 1, [Whether you have Phalconplus])
	phalconplus_sources="phalconplus.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c phalconplus/facades/abstractfacade.zep.c
	phalconplus/enum/abstractenum.zep.c
	phalconplus/base/protobuffer.zep.c
	phalconplus/app/engine/appengine.zep.c
	phalconplus/logger/processor/abstractprocessor.zep.c
	phalconplus/rpc/client/abstractclient.zep.c
	phalconplus/db/unitofwork/abstractvalue.zep.c
	phalconplus/assert/assertionfailedexception.zep.c
	phalconplus/base/abstractrequest.zep.c
	phalconplus/base/abstractresponse.zep.c
	phalconplus/base/exception.zep.c
	phalconplus/contracts/auth/access/modelevent.zep.c
	phalconplus/contracts/auth/policy.zep.c
	phalconplus/db/pdo/abstractmysql.zep.c
	phalconplus/enum/exception.zep.c
	phalconplus/rpc/server/abstractserver.zep.c
	phalconplus/app/app.zep.c
	phalconplus/app/engine/cli.zep.c
	phalconplus/app/engine/srv.zep.c
	phalconplus/app/engine/web.zep.c
	phalconplus/app/module/abstractmodule.zep.c
	phalconplus/app/module/moduledef.zep.c
	phalconplus/assert/assertion.zep.c
	phalconplus/assert/invalidargumentexception.zep.c
	phalconplus/auth/exception.zep.c
	phalconplus/auth/model.zep.c
	phalconplus/auth/policy.zep.c
	phalconplus/base/model.zep.c
	phalconplus/base/pagable.zep.c
	phalconplus/base/page.zep.c
	phalconplus/base/protoorderby.zep.c
	phalconplus/base/service.zep.c
	phalconplus/base/simplerequest.zep.c
	phalconplus/base/simpleresponse.zep.c
	phalconplus/bootstrap.zep.c
	phalconplus/contracts/auth/access/authorizable.zep.c
	phalconplus/contracts/auth/access/dispatchevent.zep.c
	phalconplus/contracts/auth/access/resourceaware.zep.c
	phalconplus/contracts/auth/access/routerevent.zep.c
	phalconplus/contracts/auth/userprovider.zep.c
	phalconplus/contracts/eventattachable.zep.c
	phalconplus/curl/curl.zep.c
	phalconplus/curl/exception.zep.c
	phalconplus/curl/request.zep.c
	phalconplus/curl/response.zep.c
	phalconplus/db/mysql.zep.c
	phalconplus/db/pdo/mysql.zep.c
	phalconplus/db/unitofwork.zep.c
	phalconplus/db/unitofwork/field.zep.c
	phalconplus/db/unitofwork/lastinsertid.zep.c
	phalconplus/enum/assertioncode.zep.c
	phalconplus/enum/facade.zep.c
	phalconplus/enum/orderbydirection.zep.c
	phalconplus/enum/runenv.zep.c
	phalconplus/enum/runmode.zep.c
	phalconplus/enum/sys.zep.c
	phalconplus/facades/acl.zep.c
	phalconplus/facades/annotations.zep.c
	phalconplus/facades/app.zep.c
	phalconplus/facades/appengine.zep.c
	phalconplus/facades/appmodule.zep.c
	phalconplus/facades/assets.zep.c
	phalconplus/facades/config.zep.c
	phalconplus/facades/cookies.zep.c
	phalconplus/facades/crypt.zep.c
	phalconplus/facades/di.zep.c
	phalconplus/facades/dispatcher.zep.c
	phalconplus/facades/escaper.zep.c
	phalconplus/facades/eventsmanager.zep.c
	phalconplus/facades/filter.zep.c
	phalconplus/facades/flash.zep.c
	phalconplus/facades/flashsession.zep.c
	phalconplus/facades/log.zep.c
	phalconplus/facades/modelscache.zep.c
	phalconplus/facades/modelsmanager.zep.c
	phalconplus/facades/modelsmetadata.zep.c
	phalconplus/facades/redis.zep.c
	phalconplus/facades/request.zep.c
	phalconplus/facades/response.zep.c
	phalconplus/facades/router.zep.c
	phalconplus/facades/security.zep.c
	phalconplus/facades/service.zep.c
	phalconplus/facades/session.zep.c
	phalconplus/facades/sessionbag.zep.c
	phalconplus/facades/tag.zep.c
	phalconplus/facades/transactionmanager.zep.c
	phalconplus/facades/url.zep.c
	phalconplus/facades/user.zep.c
	phalconplus/facades/view.zep.c
	phalconplus/featuretest/splobjectstoragetest.zep.c
	phalconplus/http/nonpsrrequest.zep.c
	phalconplus/http/nonpsrresponse.zep.c
	phalconplus/http/psrresponsefactory.zep.c
	phalconplus/logger/multiplefile.zep.c
	phalconplus/logger/processor/logid.zep.c
	phalconplus/logger/processor/msec.zep.c
	phalconplus/logger/processor/trace.zep.c
	phalconplus/mvc/psrapplication.zep.c
	phalconplus/rpc/client/adapter/curl.zep.c
	phalconplus/rpc/client/adapter/local.zep.c
	phalconplus/rpc/client/adapter/remote.zep.c
	phalconplus/rpc/server/simpleserver.zep.c
	phalconplus/rpc/yar.zep.c
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
