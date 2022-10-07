//
// Created by student on 12.06.2021.
//

#include "model/Lighting.h"

const std::string &Lighting::getBrightness() const {
    return brightness;
}

void Lighting::setBrightness(const std::string &brightness) {
    Lighting::brightness = brightness;
}

using namespace std;

std::string Lighting::getEquipmentInfo() {
    return Equipment::getEquipmentInfo() + "; jasnosc: " + getBrightness();
}

std::string Lighting::getEquipmentFullInfo() {
    return Equipment::getEquipmentFullInfo() + "; jasnosc: " + getBrightness();
}

Lighting::Lighting(const unsigned int id, double firstDayCost, double nextDaysCost, double bail, const string &name,
                   const string &brightness) try : Equipment(id, firstDayCost, nextDaysCost, bail, name),
                                               brightness(brightness) {
    if(brightness.empty()) {
        throw EquipmentException("Prosze podac prawidlawa jasnosc");
    }
}
catch(const EquipmentException &exception) {
    throw exception;
}