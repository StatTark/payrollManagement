//
// Created by StatTark on 12.12.2020.
//

#ifndef PAYROLL_INTERN_WORKER_H
#define PAYROLL_INTERN_WORKER_H

#include "title.h"

class Intern : public Title
{
private:
    int tId;
    std::string jobTitle;
    double sumHoursM;
    double perHourCost;

public:

    Intern(int id, std::string job_Title, double sumHours, double per_HourCost)
    {
        tId = id;
        jobTitle = job_Title;
        sumHoursM = sumHours;
        perHourCost = per_HourCost;
    }

    std::string getTitle() const override;
    double getSumOfHoursM() const override;
    double getPerHourCost() const override;
    void setSumOfHoursM(double hour)  override;
    void setPerHourCost(double  hour)  override;

};


#endif //PAYROLL_INTERN_WORKER_H
