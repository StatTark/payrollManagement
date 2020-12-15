#ifndef PAYROLL_EMPLOYEE_HPP
#define PAYROLL_EMPLOYEE_HPP

#include "person.h"
#include "title.h"

#include "departments.h"

class Departments;

class Employee : public Person
{
private:
    int emp_id;
    Person person;
    Title *title;
    Departments *department;
    double salary;
    std::string startDate;
    double sumOvertime;
    std::string timeOfFire;

public:
    //getters
    int getEmployeeId() { return emp_id; }
    Person getPerson() { return person; }
    //setters
    //constructer
    Employee() = default;
    Employee(Person perso,
             Title &titl,
             Departments &d,
             int id,
             double sal,
             double sum,
             std::string start,
             std::string finish)
    {
        emp_id = id;
        title = &titl;
        person = perso;
        department = &d;
        salary = sal;
        startDate = start;
        sumOvertime = sum;
        timeOfFire = finish;
    }
};

/*
: person(person),
                                   title(titl),
                                   departments(depertmen),
                                   emp_id(id),
                                   salary(sal),
                                   sumOvertime(sum),
                                   startDate(startDate),
                                   timeOfFire(finish)
*/

#endif //PAYROLL_EMPLOYEE_H
