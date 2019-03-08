<?php
namespace PhalconPlus\Test\Tasks;

class HelpTask extends \Phalcon\CLI\Task
{
    private $c;

    public function initialize()
    {
        $this->c = 1;
    }

    public function mainAction()
    {
        echo "^ ^ Help Task is Default Task ^ ^" . PHP_EOL;
    }

    public function return1Action()
    {
        return 1;
    }
}