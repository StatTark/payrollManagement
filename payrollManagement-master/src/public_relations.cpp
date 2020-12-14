#include "public_relations.h"

int PUBLIC_RELATIONS::getDepId() const 
{
    return depId;
}
std::string PUBLIC_RELATIONS::getDepName() const 
{
    return depName;
}

int PUBLIC_RELATIONS::getManagerId() const 
{
    return managerId;
}

std::list<Employee> PUBLIC_RELATIONS::getEmployeeList() const
{
    return employeList;
}

void PUBLIC_RELATIONS::setDepId(int id)
{
    depId = id;
}

void PUBLIC_RELATIONS::setDepName(std::string name)
{
    depName = name;
}

void PUBLIC_RELATIONS::setManagerId(int manager_id)
{
    managerId = manager_id;
}
