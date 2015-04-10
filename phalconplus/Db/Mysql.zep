namespace PhalconPlus\Db;

class Mysql
{
    const TRY_TIMES = 5;
    const RETRY_WAIT = 100000; // 100 ms
    
    private di;
    private descriptor = [];
    
    public function __construct(<\Phalcon\DI> di, string! confName)
    {
        var config, dbConfig;
        let config = di->get("config");
        let dbConfig = config->{confName};
        let this->di = di;
        
        let this->descriptor = [
            "host" : dbConfig->host,
            "port" : dbConfig->port,
            "username" : dbConfig->username,
            "password" : dbConfig->password,
            "dbname" : dbConfig->dbname,
            "options" : [
                \PDO::MYSQL_ATTR_INIT_COMMAND : "SET NAMES " . dbConfig->charset,
                \PDO::ATTR_TIMEOUT : dbConfig->timeout, // seconds
                \PDO::ATTR_ERRMODE : \PDO::ERRMODE_EXCEPTION
            ]
        ];
    }

    public function getConnection() -> <\Phalcon\Db\Adapter\Pdo\Mysql>
    {
        var connection = null;
        var tryTimes, e, nowTimes;
        
        let tryTimes = self::TRY_TIMES;
        
        while !is_object(connection) {
            try {
                let connection = new \Phalcon\Db\Adapter\Pdo\Mysql(this->descriptor);
            } catch Exception, e {
                error_log("PHP Fatal error:  PhalconPlus::Db::MySQL::connect() failed to connect to MySQL. Detail: " . json_encode(this->descriptor));
                let tryTimes = tryTimes - 1;
                if tryTimes > 0 {
                    // wait for xxx ms
                    usleep(self::RETRY_WAIT);
                    // let nowTimes = self::TRY_TIMES - tryTimes;
                    error_log("PHP Notice:  PhalconPlus::Db::MySQL::connnect() retry to connect to MySQL for the time ... ");
                } else {
                    error_log("PHP Fatal error:  PhalconPlus::Db::MySQL::connect() finally failed to connect to MySQL");
                    throw e;
                }
            }
        }
        return connection;
    }
}