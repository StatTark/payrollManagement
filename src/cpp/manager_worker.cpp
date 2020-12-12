#include "../headers/manager_worker.h"

double Manager::getPerHourCost() const {
    return 10.0;
}
double Manager::getSumOfHoursM() const {
    return 10.0;
}
std::string Manager::getTitle() const {
    return "Junior Worker";
}

void Manager::setPerHourCost(double  hour)  {
    perHourCost = hour;
}

void Manager::setSumOfHoursM(double hour) {
    sumHoursM = hour;
}
