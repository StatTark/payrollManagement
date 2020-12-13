#include "../headers/it.h"

int IT::getDepId() const
{
    return depId;
}
std::string IT::getDepName() const
{
    return depName;
}

int IT::getManagerId() const
{
    return managerId;
}

std::list<Employee> IT::getEmployeeList() const
{
    return employeList;
}

void IT::setDepId(int id)
{
    depId = id;
}

void IT::setDepName(std::string name)
{
    depName = name;
}

void IT::setManagerId(int manager_id)
{
    managerId = manager_id;
}