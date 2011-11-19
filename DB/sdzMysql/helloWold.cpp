//#include <sqlstring.h>
#include <mysql++.h>

#include <iostream>

using namespace std;

int main()
{
    mysqlpp::String greeting("Hello, world!");
    std::cout << greeting << std::endl;
    return 0;
}


//g++ -I/usr/local/mysql -I./mysql-connector-c++-1.1.0-osx10.5-x86-32bit/include -L/usr/local/lib -lmysqlpp -lmysqlclient helloWold.cpp -o hello 
