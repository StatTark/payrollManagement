//
// Created by StatTark on 12.12.2020.
//

#include "../headers/senior_worker.h"

double SeniorWorker::getPerHourCost() const {
    return 10.0;
}
double SeniorWorker::getSumOfHoursM() const {
    return 10.0;
}
std::string SeniorWorker::getTitle() const {
    return "Junior Worker";
}

void SeniorWorker::setPerHourCost(double  hour)  {
    perHourCost = hour;
}

void SeniorWorker::setSumOfHoursM(double hour) {
    sumHoursM = hour;
}