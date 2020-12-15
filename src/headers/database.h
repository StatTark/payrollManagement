//
// Created by StatTark on 15.12.2020.
//

#ifndef PAYROLL_DATABASE_H
#define PAYROLL_DATABASE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class DatabaseWorker{
public:
    std::string query;

    DatabaseWorker(std::string queryy){query = queryy;}


    std::vector<std::string> pullAnything();


};




#endif //PAYROLL_DATABASE_H
