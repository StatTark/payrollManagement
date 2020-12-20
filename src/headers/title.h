#ifndef PAYROLL_TITLE_H
#define PAYROLL_TITLE_H

#include <string>
class Title
{
protected:
    std::string title;
    double per_hour_cost;
    double workHour_per_month;

public:
    virtual std::string getTitle() const = 0;
    virtual double getSumOfHoursM() const = 0;
    virtual double getPerHourCost() const = 0;
    virtual void setTitle(std::string i_title) = 0;
    virtual void setSumOfHoursM(double hour) = 0;
    virtual void setPerHourCost(double hour) = 0;
};

#endif //PAYROLL_TITLE_H