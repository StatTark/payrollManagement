#include "../headers/employee.h"


double Employee::getPerHourCost() const
{
    return per_hour_cost;
}
double Employee::getSumOfHoursM() const
{
    return sumOvertime;
}
std::string Employee::getTitle() const
{
    return title;
}

int Employee::getEmployeeId() const
{
    return emp_id;
}

int Employee::getDepartmentId() const
{
    return department_id;
}

double Employee::getSalary() const
{
    return salary;
}

double Employee::getOvertime() const
{
    return sumOvertime;
}

std::string Employee::getStartDate() const
{
    return startDate;
}

std::string Employee::getTimeOffFire() const
{
    return timeOfFire;
}

void Employee::setTitle(std::string i_title)
{
    title = i_title;
}

void Employee::setPerHourCost(double hour)
{
    per_hour_cost = hour;
}

void Employee::setSumOfHoursM(double hour)
{
    sumOvertime = hour;
}

void Employee::setEmployeId(int i_id){
    emp_id = i_id;
}

void Employee::setDepartmentId(int i_did){
    department_id = i_did;
}

void Employee::setSalary(double i_salary){
    salary = i_salary;
}

void Employee::setOvertime(double i_overtime){
    sumOvertime=i_overtime;
}

void Employee::setStartDate(std::string i_startDate){
    startDate = i_startDate;
}

void Employee::setTimeOffFire(std::string i_finishDate){
    timeOfFire = i_finishDate;
}