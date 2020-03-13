namespace PhalconPlus\Auth;
use PhalconPlus\Contracts\Auth\Access\ModelEvent;
use Phalcon\Mvc\Model as ARModel;
use Phalcon\Events\Event;
use PhalconPlus\Contracts\Auth\Policy as PolicyContract;
use PhalconPlus\Contracts\Auth\UserProvider;

class Model implements ModelEvent
{
    protected user = null { get };
    protected policies = [
    ];

    public function __construct(<UserProvider> user)
    {
        let this->user = user;
    }

    public function setUser(<UserProvider> user) -> <Model>
    {
        let this->user = user;
        return this;
    }

    public function beforeDelete(<Event> event, <ARModel> model, var context = null) -> bool
    {
        var instance = this->getPolicy(model);
        return instance ? instance->delete(this->user, model) : false;
    }

    public function beforeCreate(<Event> event, <ARModel> model, var context = null) -> bool
    {
        var instance = this->getPolicy(model);   
        return instance ? instance->create(this->user, model) : false;
    }

    public function beforeUpdate(<Event> event, <ARModel> model, var context = null) -> bool
    {
        var instance = this->getPolicy(model);
        return instance ? instance->update(this->user, model) : false;
    }

    public function beforeValidation(<Event> event, <ARModel> model, var context = null) -> bool
    {
        return true;
    }

    public function getPolicy(var model) -> <PolicyContract> | null
    {
        var modelClass, policyClass, instance;
        if typeof model == "object" && model instanceof ARModel {
            let modelClass = get_class(model);
        }  else {
            let modelClass = (string) model;
        }
        if fetch policyClass, this->policies[modelClass] {
            let instance = new {policyClass}();
        } else {
            let instance = new Policy();
        }        
        return instance;
    }

}