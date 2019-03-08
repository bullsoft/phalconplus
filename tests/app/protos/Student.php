<?php

namespace PhalconPlus\Test\Protos;

/**
 * @Title("Student")
 * @Required({"firstName", "lastName"})
 */
class Student extends \PhalconPlus\Base\ProtoBuffer
{
    /**
     * @Key("firstName")
     * @Description("名")
     * @Type("string")
     */
    protected $firstName;
    /**
     * @Key("lastName")
     * @Description("姓")
     * @Type("string")
     */
    protected $lastName;
    /**
     * @Key("age")
     * @Description("年龄")
     * @Type("integer")
     * @Minimum(1)
     */
    protected $age;
    /**
     * @Key("classes")
     * @Ref("PhalconPlus\Test\Protos\Classes")
     */
    protected $classes;
    public function setFirstName($firstName)
    {
        $this->firstName = $firstName;
    }
    public function getFirstName()
    {
        return $this->firstName;
    }
    public function setLastName($lastName)
    {
        $this->lastName = $lastName;
    }
    public function getLastName()
    {
        return $this->lastName;
    }
    public function setAge($age)
    {
        $this->age = $age;
    }
    public function getAge()
    {
        return $this->age;
    }
    public function setClasses($classes)
    {
        $this->classes = $classes;
    }
    public function getClasses()
    {
        return $this->classes;
    }
}
