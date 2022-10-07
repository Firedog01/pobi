//
// Created by student on 12.06.2021.
//

#include "model/Camera.h"

const std::string &Camera::getResolution() const {
    return resolution;
}

void Camera::setResolution(const std::string &resolution) {
    Camera::resolution = resolution;
}

std::string Camera::getEquipmentFullInfo() {
    return Equipment::getEquipmentFullInfo() + "; rozdzielczosc: " + getResolution();
}

std::string Camera::getEquipmentInfo() {
    return Equipment::getEquipmentInfo() + "; rozdzielczosc: " + getResolution();
}

Camera::Camera(const unsigned int id, double firstDayCost, double nextDaysCost, double bail, const std::string &name,
               const std::string &resolution) try : Equipment(id, firstDayCost, nextDaysCost, bail, name),
                                                resolution(resolution) {
    if(resolution.empty()) {
        throw EquipmentException ("Prosze podac prawidlowa rozdzielczosc");
    }
}
catch(const EquipmentException &exception) {
    throw exception;
}
