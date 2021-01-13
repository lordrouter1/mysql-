#include "connect.h"

MysqlConnect::MysqlConnect(std::string server, std::string user, std::string password, std::string database)
{
    mysql_init(&this->con);

    if(&this->con == NULL)
    {
        std::cout << "Erro ao iniciar a con!" << std::endl;
        return;
    }

    if(!mysql_real_connect(&this->con,server.c_str(),user.c_str(),password.c_str(),database.c_str(),0,NULL,0))
    {
        std::cout << "Erro ao conectar ao banco de dados!" << std::endl;
        return;
    }

    return;
}

MysqlConnect::MysqlConnect()
{
    mysql_init(&this->con); 

    if(&this->con == NULL)
    {
        std::cout << "Erro ao iniciar a con!" << std::endl;
        return;
    }

    if(!mysql_real_connect(&this->con,M_SERVER,M_USER,M_PASSWORD,M_DATABASE,0,NULL,0))
    {
        std::cout << "Erro ao conectar ao banco de dados!" << std::endl;
        return;
    }
    
}

MYSQL_RES *MysqlConnect::query(std::string query)
{
    if(mysql_query(&this->con,query.c_str()))
    {
        return NULL;
    }
    else
    {
        return mysql_store_result(&this->con);
    }

    return NULL;
}

std::string MysqlConnect::error()
{
    return mysql_error(&this->con);
}