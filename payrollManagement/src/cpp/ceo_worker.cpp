//
// Created by StatTark on 12.12.2020.
//

#include "../headers/ceo_worker.h"

double Ceo::getPerHourCost() const {
    return 10.0;
}
double Ceo::getSumOfHoursM() const {
    return 10.0;
}
std::string Ceo::getTitle() const {
    return "Junior Worker";
}

void Ceo::setPerHourCost(double  hour)  {
    perHourCost = hour;
}

void Ceo::setSumOfHoursM(double hour) {
    sumHoursM = hour;
}