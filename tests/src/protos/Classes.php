<?php

namespace PhalconPlus\Test\Protos;

/**
 * @Title("Classes")
 */
class Classes extends \PhalconPlus\Base\ProtoBuffer
{
    /**
     * @Key("grade")
     * @Type("integer")
     * @Minimum(1)
     */
    protected $grade;
    public function setGrade($grade)
    {
        $this->grade = $grade;
    }
    public function getGrade()
    {
        return $this->grade;
    }
}
