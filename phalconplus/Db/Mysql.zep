namespace PhalconPlus\Db;
use Phalcon\Di\Di;

class Mysql
{
    const RETRY_TIMES = 5;  // 5 times
    const RETRY_INTERVAL = 100000; // 100 ms

    private di = null;
    private descriptor = [];
    private options = [];

    private retryTimes = self::RETRY_TIMES;
    private retryInterval = self::RETRY_INTERVAL;

    private name;
    private connection = null;
    private connected = false;

    public function __construct(<Di> di, string! name)
    {
        var config, dbConfig;
        let config = di->get("config");
        let dbConfig = config->{name};
        let this->di = di;

        let this->name = name;
        if isset(dbConfig->retryTimes) {
            let this->retryTimes = dbConfig->retryTimes;
        }
        if isset(dbConfig->retryInterval) {
            let this->retryInterval = dbConfig->retryInterval;
        }

        // Build options...
        var options = [
            \PDO::MYSQL_ATTR_INIT_COMMAND : "SET NAMES " . dbConfig->charset,
            \PDO::ATTR_TIMEOUT : dbConfig->timeout, // seconds
            \PDO::ATTR_ERRMODE : \PDO::ERRMODE_EXCEPTION
        ];
        if isset(dbConfig->options) {
            let this->options = dbConfig->options->toArray() + options;
        } else {
            let this->options = options;
        }

        let this->descriptor = [
            "host" : dbConfig->host,
            "port" : dbConfig->port,
            "username" : dbConfig->username,
            "password" : dbConfig->password,
            "dbname" : dbConfig->dbname,
            "options" : this->options
        ];
    }

    public function getConnection(boolean autoConnect = true) -> <\Phalcon\Db\Adapter\Pdo\Mysql>
    {
        var tryTimes, e;
        let tryTimes = this->retryTimes;

        while !this->connected {
            try {
                if autoConnect == true {
                    let this->connection = new \Phalcon\Db\Adapter\Pdo\Mysql(this->descriptor);
                } else {
                    // Lazy connection
                    let this->connection = new \PhalconPlus\Db\Pdo\Mysql(this->descriptor, autoConnect);
                }
                let this->connected = true;
            } catch \Exception, e {
                error_log("PHP Fatal error:  PhalconPlus::Db::MySQL::connect() failed to connect to MySQL. Detail: " .
                          json_encode(this->descriptor) .
                          ". We will try " . strval(tryTimes) . " times for you.");
                let tryTimes = tryTimes - 1;
                if tryTimes > 0 {
                    // wait for xxx ms
                    usleep(this->retryInterval);
                    error_log("PHP Notice:  PhalconPlus::Db::MySQL::connnect() retry to connect to MySQL for the ".strval(this->retryTimes - tryTimes)." time ... ");
                } else {
                    error_log("PHP Fatal error:  PhalconPlus::Db::MySQL::connect() finally failed to connect to MySQL. Detail: " .
                              json_encode(this->descriptor));
                    throw e;
                }
            }
        }
        return this->connection;
    }
}
