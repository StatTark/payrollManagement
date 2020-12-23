#include "../headers/human_res.h"

int HumanRes::getDepId() const 
{
    return depId;
}
std::string HumanRes::getDepName() const 
{
    return depName;
}

int HumanRes::getManagerId() const 
{
    return managerId;
}

std::list<Employee*> HumanRes::getEmployeeList() const
{
    return employeList;
}

void HumanRes::setDepId(int id)
{
    depId = id;
}

void HumanRes::setDepName(std::string name)
{
    depName = name;
}

void HumanRes::setManagerId(int manager_id)
{
    managerId = manager_id;
}