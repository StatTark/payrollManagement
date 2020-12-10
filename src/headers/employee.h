#ifndef PAYROLL_EMPLOYEE_H
#define PAYROLL_EMPLOYEE_H

#include <string>
#include "person.h"
#include "title.h"
#include "departments.h"
class Employee: public Person, public Title{
private:

    int emp_id;
    Person person;
    Title *title;
    Department department;
    double salary;
    std::string startDate;
    double sumOvertime;
    std::string timeOfFire;

public:
    //getter-setter
    //constructer

};

#endif //PAYROLL_EMPLOYEE_H
