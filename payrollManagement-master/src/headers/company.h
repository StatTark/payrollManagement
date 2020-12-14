#ifndef PAYROLL_COMPANY_H
#define PAYROLL_COMPANY_H

#include <string>
#include <list>

#include "departments.h"
#include "employee.h"

class Company{
public:
        std::string companyName;
        std::list<Departments*> departmans;



        Company(std::string company_Name){
            companyName = company_Name;
        };

        void addDepartman(Departments *departments){
            departmans.push_back(departments);
        }
        //remove de koyulabilir.



};
#endif //PAYROLL_COMPANY_H
