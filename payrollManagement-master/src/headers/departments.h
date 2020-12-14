#ifndef PAYROLL_Departments_H
#define PAYROLL_Departments_H

#include "employee.h"
#include <list>
class Departments
{

public:
    //getters
    virtual int getDepId() const = 0;
    virtual std::string getDepName() const = 0;
    virtual int getManagerId() const = 0;
    virtual std::list<Employee> getEmployeeList() const = 0;
    //setters
    virtual void setDepId(int id)=0;
    virtual void setDepName(std::string name)=0;
    //change manager
    virtual void setManagerId(int managerId)=0;
    //constructor
};

#endif //PAYROLL_Departments_H
