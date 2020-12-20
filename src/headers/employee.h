#ifndef PAYROLL_EMPLOYEE_HPP
#define PAYROLL_EMPLOYEE_HPP

#include "person.h"
#include "title.h"

#include "departments.h"

class Departments;
class Employee : public Person, public Title
{
private:
    int emp_id;
    int department_id; 
    double salary;
    std::string startDate;
    double sumOvertime;
    std::string timeOfFire;
    

public:
    //getters
    std::string getTitle() const override;
    double getSumOfHoursM() const override;
    double getPerHourCost() const override;
    int getEmployeeId() const;
    int getDepartmentId() const;
    double getSalary() const;
    double getOvertime() const;
    std::string getStartDate() const;
    std::string getTimeOffFire() const;
    //setters
    void setTitle(std::string i_title) override;
    void setSumOfHoursM(double hour) override;
    void setPerHourCost(double hour) override;
    void setEmployeId(int i_id) ;
    void setDepartmentId(int i_did) ;
    void setSalary(double i_salary) ;
    void setOvertime(double i_overtime) ;
    void setStartDate(std::string i_startDate) ;
    void setTimeOffFire(std::string i_finishDate) ;
    //constructer
    Employee() = default;
};

#endif //PAYROLL_EMPLOYEE_H
