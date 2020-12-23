#ifndef PAYROLL_DATABASE_H
#define PAYROLL_DATABASE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class DatabaseWorker{
public:
    std::string query;

    DatabaseWorker()=default;


    std::vector<std::vector<std::string>> exec_query(std::string query);


};




#endif //PAYROLL_DATABASE_H
