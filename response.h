#ifndef __MYSQLPP_RESPONSE__
#define __MYSQLPP_RESPONSE__

#include <mysql/mysql.h>
#include <cstddef>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#define MysqlRow std::map<std::string,std::string> 

class MysqlResponse
{
    public:
        MysqlResponse();

        int num_rows();
        int next();
        std::vector<std::string> getFields();

        void operator=(MYSQL_RES *res);
        MysqlRow operator[](int row);
        std::string operator[](std::string field);

    private:
        std::vector<MysqlRow> resp;
        std::vector<std::string> fields;
};


#endif