#include "../headers/intern_worker.h"

double Intern::getPerHourCost() const {
    return 10.0;
}
double Intern::getSumOfHoursM() const {
    return 10.0;
}
std::string Intern::getTitle() const {
    return "Junior Worker";
}

void Intern::setPerHourCost(double  hour)  {
    perHourCost = hour;
}

void Intern::setSumOfHoursM(double hour) {
    sumHoursM = hour;
}