#ifndef IT_H
#define IT_H

#include "departments.h"

class IT : public Department
{
private:
    int depId;
    std::string depName;
    int managerId;
    std::list<Employee> employeList;

public:
    IT(int id, std::string name, int manager_id, std::list<Employee> empList)
    {
        depId = id;
        depName = name;
        managerId = manager_id;
        employeList = empList;
    }
    //getters
    virtual int getDepId() const override;
    virtual std::string getDepName() const override;
    virtual int getManagerId() const override;
    virtual std::list<Employee> getEmployeeList() const override;
    //setters
    virtual void setDepId(int id) override;
    virtual void setDepName(std::string name) override;
    //change manager
    virtual void setManagerId(int managerId) override;
};

#endif