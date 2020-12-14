#include "../headers/junior_worker.h"

double JuniorWorker::getPerHourCost() const {
    return 10.0;
}
double JuniorWorker::getSumOfHoursM() const {
    return 10.0;
}
std::string JuniorWorker::getTitle() const {
    return "Junior Worker";
}

void JuniorWorker::setPerHourCost(double  hour)  {
    perHourCost = hour;
}

void JuniorWorker::setSumOfHoursM(double hour) {
    sumHoursM = hour;
}