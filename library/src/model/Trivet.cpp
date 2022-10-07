//
// Created by student on 12.06.2021.
//

#include "model/Trivet.h"

double Trivet::getWeight() const {
    return weight;
}

void Trivet::setWeight(double weight) {
    Trivet::weight = weight;
}

std::string Trivet::getEquipmentFullInfo() {
    return Equipment::getEquipmentFullInfo() + "; waga: " + std::to_string(getWeight());
}

std::string Trivet::getEquipmentInfo() {
    return Equipment::getEquipmentInfo() + "; waga: " + std::to_string(getWeight());
}

Trivet::Trivet(const unsigned int id, double firstDayCost, double nextDaysCost, double bail, const std::string &name,
               double weight) try : Equipment(id, firstDayCost, nextDaysCost, bail, name), weight(weight) {
    if(weight <= 0.0) {
        throw EquipmentException ("Prosze podac prawidlawa wage");
    }
}
catch(const EquipmentException &exception) {
    throw exception;
}