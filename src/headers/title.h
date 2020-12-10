#ifndef PAYROLL_TITLE_H
#define PAYROLL_TITLE_H

#include <string>
class Title
{ 
public:
    virtual std::string getTitle() const = 0;
    virtual double getSumOfHoursM() const = 0;
    virtual double getPerHourCost() const = 0;
};

#endif //PAYROLL_TITLE_H
