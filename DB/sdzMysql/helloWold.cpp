#include <mysql++.h>
#include <iostream>

using namespace std;

int main()
{
    mysqlpp::String greeting("Hello, world!");
    std::cout << greeting << std::endl;
    return 0;
}
