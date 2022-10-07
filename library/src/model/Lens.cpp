//
// Created by student on 12.06.2021.
//

#include "model/Lens.h"

const std::string &Lens::getFocalLength() const {
    return focalLength;
}

void Lens::setFocalLength(const std::string &focalLength) {
    Lens::focalLength = focalLength;
}

std::string Lens::getEquipmentFullInfo() {
    return Equipment::getEquipmentFullInfo() + "; ogniskowa: " + getFocalLength();
}

std::string Lens::getEquipmentInfo() {
    return Equipment::getEquipmentInfo() + "; ogniskowa: " + getFocalLength();
}

Lens::Lens(const unsigned int id, double firstDayCost, double nextDaysCost, double bail, const std::string &name,
           const std::string &focalLength) try : Equipment(id, firstDayCost, nextDaysCost, bail, name),
                                             focalLength(focalLength) {
    if(focalLength.empty()) {
        throw EquipmentException("Prosze podac prawidlowa dlugosc ogniskowej");
    }
}
catch(const EquipmentException &exception) {
    throw exception;
}