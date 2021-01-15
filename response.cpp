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
    MysqlRow temp;
    int flag = 0;

    this->resp.clear();
    this->fields.clear();

    if(response && mysql_num_rows(res) > 0)
    {
        campos = mysql_fetch_fields(response);
        while((linhas = mysql_fetch_row(response)) != NULL)
        {
            for(int i = 0; i < mysql_num_fields(response); i++)
            {
                if(flag == 0)
                {
                    this->fields.push_back(campos[i].name);
                }

                temp[campos[i].name] = linhas[i];
            }
            this->resp.push_back(temp);
            flag++;
        }

        mysql_free_result(response);
    }
    else
    {
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

std::vector<std::string> MysqlResponse::getFields()
{
    return this->fields;
}