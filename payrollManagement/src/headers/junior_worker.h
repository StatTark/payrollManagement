#ifndef JUNIORWORKER_H
#define JUNIORWORKER_H

#include "title.h"

class JuniorWorker : public Title
{
private:
    int tId;
    std::string jobTitle;
    double sumHoursM;
    double perHourCost;

public:

    JuniorWorker(int id, std::string job_Title, double sumHours, double per_HourCost)
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

#endif