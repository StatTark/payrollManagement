#include "../headers/purchasing.h"

int Purchasing::getDepId() const 
{
    return depId;
}
std::string Purchasing::getDepName() const 
{
    return depName;
}

int Purchasing::getManagerId() const 
{
    return managerId;
}

std::list<Employee> Purchasing::getEmployeeList() const
{
    return employeList;
}

void Purchasing::setDepId(int id)
{
    depId = id;
}

void Purchasing::setDepName(std::string name)
{
    depName = name;
}

void Purchasing::setManagerId(int manager_id)
{
    managerId = manager_id;
}