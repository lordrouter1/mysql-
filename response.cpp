#include "response.h"

MysqlResponse::MysqlResponse()
{
    return;
}

void MysqlResponse::operator=(MYSQL_RES *res)
{
    //this->response = resp;
    MYSQL_FIELD *campos;
    MYSQL_ROW linhas;
    MYSQL_RES *response = res;

    if(!response) return;

    MysqlRow temp;

    this->resp.clear();

    campos = mysql_fetch_fields(response);
    while((linhas = mysql_fetch_row(response)) != NULL)
    {
        for(int i = 0; i < mysql_num_fields(response); i++)
        {
            temp[campos[i].name] = linhas[i];
        }
        this->resp.push_back(temp);
    }
}

MysqlRow MysqlResponse::operator[](int row)
{
    return this->resp[row];
}

std::string MysqlResponse::operator[](std::string field)
{
    return this->resp[0][field];
}

int MysqlResponse::num_rows()
{
    return this->resp.size();
}

int MysqlResponse::next()
{
    if(this->resp.size() > 1)
    {
        this->resp.erase(this->resp.begin());
        return 0;
    }
    else
    {
        return -1;
    }
}