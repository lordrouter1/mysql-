#ifndef __MYSQLPP_CONNECT__
#define __MYSQLPP_CONNECT__

#include <mysql/mysql.h>
#include <cstddef>
#include <iostream>
#include <string>

#define M_SERVER    "localhost"
#define M_USER      "mysqlcpp"
#define M_PASSWORD  "mysqlcpp"
#define M_DATABASE   "db_cpp"

class MysqlConnect
{
    public:
        MysqlConnect(std::string server, std::string user, std::string password, std::string database);
        MysqlConnect();

        MYSQL_RES *query(std::string query);
        void close();

        std::string error();
        
    private:
        MYSQL con;
};


#endif