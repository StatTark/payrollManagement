#include "../headers/advertisement.h"

int Advertisement::getDepId() const 
{
    return depId;
}
std::string Advertisement::getDepName() const 
{
    return depName;
}

int Advertisement::getManagerId() const 
{
    return managerId;
}

std::list<Employee*> Advertisement::getEmployeeList() const
{
    return employeList;
}

void Advertisement::setDepId(int id)
{
    depId = id;
}

void Advertisement::setDepName(std::string name)
{
    depName = name;
}

void Advertisement::setManagerId(int manager_id)
{
    managerId = manager_id;
}