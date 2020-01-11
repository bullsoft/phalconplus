<?php
define("AUTO_HANDLE", false);
include dirname(__DIR__) . "/bootstrap.php";

use PhalconPlus\Test\Models\Classicmodels\EmployeesModel;
use Phalcon\Mvc\Model\Resultset;

// di()->getDbRead()->getInternalHandler()->setAttribute(\PDO::ATTR_EMULATE_PREPARES, false);

$a = EmployeesModel::findFirst(
    ['hydration' => Resultset::HYDRATE_ARRAYS]
);
//var_dump($a->toArray());
var_dump($a->getSnapshotData());
//$metaData = $a->getModelsMetaData();
//var_dump(ini_get("phalcon.orm.cast_on_hydrate"));
//$c = $metaData->getColumnMap($a);
//$d = $metaData->getDataTypes($a);

//var_dump($a->toArray());
//echo $a->lastName . PHP_EOL;
//$a->lastName = "Murphy1";
//var_dump($a->getDirtyState());


//var_dump($di->getShared("modelsManager")->getLastQuery());
var_dump($a->getChangedFields());
//var_dump($a->getUpdatedFields());
