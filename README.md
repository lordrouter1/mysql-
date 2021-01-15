#include "cabecalho.h"

int main(){
    MysqlConnect *con = new MysqlConnect("localhost","mysqlcpp","mysqlcpp","db_cpp");
    MysqlResponse resp;

    std::cout << con->error();

    resp = con->query("select * from tbl_usuario");

    do
    {
        std::cout << resp["nome"] << std::endl;
    }while(resp.next() != -1);
}