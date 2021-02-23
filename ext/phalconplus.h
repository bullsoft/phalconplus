
/* This file was generated automatically by Zephir do not modify it! */

#ifndef ZEPHIR_CLASS_ENTRIES_H
#define ZEPHIR_CLASS_ENTRIES_H

#include "phalconplus/facades/abstractfacade.zep.h"
#include "phalconplus/contracts/arrayof.zep.h"
#include "phalconplus/contracts/emptyornot.zep.h"
#include "phalconplus/base/protobuffer.zep.h"
#include "phalconplus/enum/abstractenum.zep.h"
#include "phalconplus/app/engine/appengine.zep.h"
#include "phalconplus/base/exception.zep.h"
#include "phalconplus/contracts/stringer.zep.h"
#include "phalconplus/logger/processor/abstractprocessor.zep.h"
#include "phalconplus/rpc/client/abstractclient.zep.h"
#include "phalconplus/db/unitofwork/abstractvalue.zep.h"
#include "phalconplus/assert/assertionfailedexception.zep.h"
#include "phalconplus/base/abstractrequest.zep.h"
#include "phalconplus/base/abstractresponse.zep.h"
#include "phalconplus/contracts/auth/access/modelevent.zep.h"
#include "phalconplus/contracts/auth/policy.zep.h"
#include "phalconplus/contracts/auth/userprovider.zep.h"
#include "phalconplus/db/pdo/abstractmysql.zep.h"
#include "phalconplus/rpc/server/abstractserver.zep.h"
#include "phalconplus/app/app.zep.h"
#include "phalconplus/app/engine/cli.zep.h"
#include "phalconplus/app/engine/srv.zep.h"
#include "phalconplus/app/engine/web.zep.h"
#include "phalconplus/app/module/abstractmodule.zep.h"
#include "phalconplus/app/module/moduledef.zep.h"
#include "phalconplus/assert/assertion.zep.h"
#include "phalconplus/assert/invalidargumentexception.zep.h"
#include "phalconplus/auth/exception.zep.h"
#include "phalconplus/auth/model.zep.h"
#include "phalconplus/auth/policy.zep.h"
#include "phalconplus/auth/userprovider.zep.h"
#include "phalconplus/base/model.zep.h"
#include "phalconplus/base/pagable.zep.h"
#include "phalconplus/base/page.zep.h"
#include "phalconplus/base/protoorderby.zep.h"
#include "phalconplus/base/service.zep.h"
#include "phalconplus/base/simplerequest.zep.h"
#include "phalconplus/base/simpleresponse.zep.h"
#include "phalconplus/bootstrap.zep.h"
#include "phalconplus/contracts/auth/access/authorizable.zep.h"
#include "phalconplus/contracts/auth/access/dispatchevent.zep.h"
#include "phalconplus/contracts/auth/access/resourceaware.zep.h"
#include "phalconplus/contracts/auth/access/routerevent.zep.h"
#include "phalconplus/contracts/dump.zep.h"
#include "phalconplus/contracts/eventattachable.zep.h"
#include "phalconplus/contracts/invoke.zep.h"
#include "phalconplus/curl/curl.zep.h"
#include "phalconplus/curl/exception.zep.h"
#include "phalconplus/curl/request.zep.h"
#include "phalconplus/curl/response.zep.h"
#include "phalconplus/db/mysql.zep.h"
#include "phalconplus/db/pdo/mysql.zep.h"
#include "phalconplus/db/unitofwork.zep.h"
#include "phalconplus/db/unitofwork/field.zep.h"
#include "phalconplus/db/unitofwork/lastinsertid.zep.h"
#include "phalconplus/enum/assertioncode.zep.h"
#include "phalconplus/enum/exception.zep.h"
#include "phalconplus/enum/facade.zep.h"
#include "phalconplus/enum/orderbydirection.zep.h"
#include "phalconplus/enum/runenv.zep.h"
#include "phalconplus/enum/runmode.zep.h"
#include "phalconplus/enum/sys.zep.h"
#include "phalconplus/facades/acl.zep.h"
#include "phalconplus/facades/annotations.zep.h"
#include "phalconplus/facades/app.zep.h"
#include "phalconplus/facades/appengine.zep.h"
#include "phalconplus/facades/appmodule.zep.h"
#include "phalconplus/facades/assets.zep.h"
#include "phalconplus/facades/config.zep.h"
#include "phalconplus/facades/cookies.zep.h"
#include "phalconplus/facades/crypt.zep.h"
#include "phalconplus/facades/di.zep.h"
#include "phalconplus/facades/dispatcher.zep.h"
#include "phalconplus/facades/escaper.zep.h"
#include "phalconplus/facades/eventsmanager.zep.h"
#include "phalconplus/facades/filter.zep.h"
#include "phalconplus/facades/flash.zep.h"
#include "phalconplus/facades/flashsession.zep.h"
#include "phalconplus/facades/log.zep.h"
#include "phalconplus/facades/modelscache.zep.h"
#include "phalconplus/facades/modelsmanager.zep.h"
#include "phalconplus/facades/modelsmetadata.zep.h"
#include "phalconplus/facades/redis.zep.h"
#include "phalconplus/facades/request.zep.h"
#include "phalconplus/facades/response.zep.h"
#include "phalconplus/facades/router.zep.h"
#include "phalconplus/facades/security.zep.h"
#include "phalconplus/facades/service.zep.h"
#include "phalconplus/facades/session.zep.h"
#include "phalconplus/facades/sessionbag.zep.h"
#include "phalconplus/facades/tag.zep.h"
#include "phalconplus/facades/transactionmanager.zep.h"
#include "phalconplus/facades/url.zep.h"
#include "phalconplus/facades/user.zep.h"
#include "phalconplus/facades/view.zep.h"
#include "phalconplus/featuretest/splobjectstoragetest.zep.h"
#include "phalconplus/helper/arr.zep.h"
#include "phalconplus/helper/exception.zep.h"
#include "phalconplus/helper/ns.zep.h"
#include "phalconplus/helper/str.zep.h"
#include "phalconplus/helper/variable.zep.h"
#include "phalconplus/http/nonpsrrequest.zep.h"
#include "phalconplus/http/nonpsrresponse.zep.h"
#include "phalconplus/http/psrresponsefactory.zep.h"
#include "phalconplus/logger/multiplefile.zep.h"
#include "phalconplus/logger/processor/logid.zep.h"
#include "phalconplus/logger/processor/msec.zep.h"
#include "phalconplus/logger/processor/trace.zep.h"
#include "phalconplus/mvc/psrapplication.zep.h"
#include "phalconplus/rpc/client/adapter/curl.zep.h"
#include "phalconplus/rpc/client/adapter/local.zep.h"
#include "phalconplus/rpc/client/adapter/remote.zep.h"
#include "phalconplus/rpc/server/simpleserver.zep.h"
#include "phalconplus/rpc/yar.zep.h"
#include "phalconplus/volt/extension/phpfunction.zep.h"
#include "phalconplus/0__closure.zep.h"
#include "phalconplus/1__closure.zep.h"
#include "phalconplus/2__closure.zep.h"
#include "phalconplus/3__closure.zep.h"

#endif