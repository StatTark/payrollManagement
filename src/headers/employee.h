#ifndef PAYROLL_EMPLOYEE_H
#define PAYROLL_EMPLOYEE_H

#include <string>
#include "person.h"
#include "title.h"

#include "departments.h"

class Departments
{
};

class Employee : public Person
{
private:
    int emp_id;
    Title *title;
    Departments *department;
    double salary;
    std::string startDate;
    double sumOvertime;
    std::string timeOfFire;

public:
    //getter-setter
    //constructer
    Employee(int emp_i,
             Title *titl,
             Departments *departmen,
             double salar,
             std::string startDat,
             double sumOvertim,
             std::string timeOfFir)
    {
        emp_id = emp_i;
        title = titl;
        department = departmen;
        salary = salar;
        startDate = startDat;
        sumOvertime = sumOvertim;
        timeOfFire = timeOfFir;
    }
};

#endif //PAYROLL_EMPLOYEE_H
