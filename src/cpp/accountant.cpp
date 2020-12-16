#include "../headers/accountant.h"

std::string Accountant::getTitle() const
{
    return "Muhasebeci";
}

double Accountant::getPerHourCost() const
{
    return this->per_hour_cost;
}

double Accountant::getSumOfHoursM() const
{
    return this->workHour_per_month;
}
void Accountant::setSumOfHoursM(double hour)
{
    this->workHour_per_month = hour;
}

void Accountant::setPerHourCost(double hour)
{
    this->per_hour_cost = hour;
}