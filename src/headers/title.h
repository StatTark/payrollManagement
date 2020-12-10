#ifndef PAYROLL_TITLE_H
#define PAYROLL_TITLE_H

#include <string>
class Title{ //private class
private:
    int tId;
    std::string jobTitle;
    double sumHoursM;
    double perHourCost;

    Title(int id,std::string job_Title, double sumHours, double per_HourCost){
        tId = id;
        jobTitle = job_Title;
        sumHoursM = sumHours;
        perHourCost = per_HourCost;
    }
    //getter setter


};


#endif //PAYROLL_TITLE_H
