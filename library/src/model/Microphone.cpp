//
// Created by student on 12.06.2021.
//

#include "model/Microphone.h"

const std::string &Microphone::getSensitivity() const {
    return sensitivity;
}

void Microphone::setSensitivity(const std::string &sensitivity) {
    Microphone::sensitivity = sensitivity;
}

std::string Microphone::getEquipmentFullInfo() {
    return Equipment::getEquipmentFullInfo() + "; czulosc: " + getSensitivity();
}

std::string Microphone::getEquipmentInfo() {
    return Equipment::getEquipmentInfo() + "; czulosc: " + getSensitivity();
}

Microphone::Microphone(const unsigned int id, double firstDayCost, double nextDaysCost, double bail,
                       const std::string &name, const std::string &sensitivity) try : Equipment(id, firstDayCost,
                                                                                            nextDaysCost, bail, name),
                                                                                  sensitivity(sensitivity) {
    if(sensitivity.empty()) {
        throw EquipmentException ("Prosze podac prawidlawa czulosc");
    }
}
catch(const EquipmentException &exception) {
    throw exception;
}