#ifndef ADVERTISEMENT_H
#define ADVERTISEMENT_H

#include "departments.h"

class Advertisement : public Departments
{
private:
    int depId = 4;
    std::string depName = "Advertisement";
    int managerId;
    std::list<Employee*> employeList;

public:
    //getters
    int getDepId() const override;
    std::string getDepName() const override;
    int getManagerId() const override;
    std::list<Employee*> getEmployeeList() const override;
    //setters
    void setDepId(int id) override;
    void setDepName(std::string name) override;
    //change manager
    void setManagerId(int managerId) override;
};

#endif