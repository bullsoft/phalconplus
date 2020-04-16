# Phalcon+

[Phalcon+](http://phalconplus.bullsoft.org) 是一个轻量级的基于 [PhalconPHP](http://www.phalconphp.com) 的Zephir/C框架。我们想为Phalcon开发者构建一个一步到位的解决方案。正是因为Phalcon极高的灵活性，赋予了开发者过多的选择权。有时候路口太多容易迷失，所以当我做完这一系列选择后，我把这个过程记录了下来，并逐渐演化成了现在的Phalcon+。为了让每个开发者不重复去做这些选择，我毅然将Phalcon+开源，供大家交流和学习。

So, 总结来说，Phalcon+并不是一个全新的框架，而是对Phalcon框架的一次优秀实践，是对Phalcon框架的再次加工和补充，能让Phalcon开发者更简单地入门和精通，最后达到天人合一的最高境界。

## 依赖
    * PHP 7.0 or above
    * cPhalcon 3.4.x - https://github.com/phalcon/cphalcon/tree/3.4.x

## 约束
 - 不支持Phalcon的多模块结构，Phalcon+有自己的模块机制
 - 所有模块目录结构都是同构的
 - 模块是有工作模式的，如：Web, Srv, Cli等...，不同模式的模块角色不一样
 - 无论哪种模式，入口文件都完全一样
 - 内置RPC服务端和客户端
 - 所有模块都依赖全局的common（实际上是Cli Module）

## 安装
```
➜ git clone https://github.com/bullsoft/phalconplus.git
➜ cd phalconplus/ext/
➜ /usr/bin/phpize
➜ ./configure --with-php-config=/usr/bin/php-configure
➜ make
➜ make install
```

## 创建应用
```
# 下载骨架
composer create-project bullsoft/fp-project fp-app
# 生成模块，假设模块名为test
cd fp-app
./common/bin/fp-devtool module:create
```

## 运行

使用[Phalcon+DevTool](https://github.com/bullsoft/fp-common)
```bash
./common/bin/fp-devtool server:start test
```
使用[PPM](https://github.com/php-pm/php-pm)
```
cd test
../vendor/bin/ppm start --bridge="PhalconPlus\\Bridge" --bootstrap="PhalconPlus\\Bootstrap" --static-directory=public/ --port=8181 --workers=1
```
使用[RoadRunner](https://github.com/spiral/roadrunner)
```
cd test
touch .rr.json
touch psr-worker.php
```
.rr.json
```json
{
  "http": {
    "address": "0.0.0.0:8181",
    "workers": {
      "command": "/usr/local/opt/php@7.2/bin/php psr-worker.php",
      "relay": "unix://rr.sock",
      "pool": {
        "numWorkers": 4
      }
    }
  },
  "static" : {
  	"enable" : true,
  	"dir": "public",
  	"forbid": [".php", ".htaccess"]
  }
}
```
psr-worker.php
```php
<?php

use Spiral\Goridge;
use Spiral\RoadRunner;
use PhalconPlus\Http\PsrResponseFactory;

ini_set('display_errors', 'stderr');

$app = (new PhalconPlus\Bootstrap(__DIR__))->app();

$worker = new RoadRunner\Worker(
    new Goridge\SocketRelay(__DIR__."/rr.sock", null, Goridge\SocketRelay::SOCK_UNIX)
);

$psr7 = new RoadRunner\PSR7Client($worker);

while ($req = $psr7->acceptRequest()) {

    try {
        $resp = $app->handle($req);
    } catch (\Throwable $e) {
        LightCloud\Uc\Exceptions\Handler::catch($e);
        $resp = $app->response();
    }

    $psr7->respond(PsrResponseFactory::create($resp));
    $app->terminate();
    unset($req, $resp);
}
```
然后在模块目录下执行
```
rr serve -d -v
```

## Demos
  * 雪品应用：[http://shopbigbang.com](http://shopbigbang.com)
  * Phalcon+: [http://phalconphp.org](http://phalconphp.org)
      



