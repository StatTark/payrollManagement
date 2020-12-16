#ifndef HUMAN_RES_H
#define HUMAN_RES_H

#include "departments.h"

class HumanRes : public Departments
{
private:
    int depId;
    std::string depName;
    int managerId;
    std::list<Employee> employeList;

public:
    HumanRes(int id, std::string name, int manager_id, std::list<Employee> empList)
    {
        depId = id;
        depName = name;
        managerId = manager_id;
        employeList = empList;
    }
    //getters
    int getDepId() const override;
    std::string getDepName() const override;
    int getManagerId() const override;
    std::list<Employee> getEmployeeList() const override;
    //setters
    void setDepId(int id) override;
    void setDepName(std::string name) override;
    //change manager
    void setManagerId(int managerId) override;
};

#endif