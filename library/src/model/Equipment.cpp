//
// Created by student on 31.05.2021.
//

#include "model/Equipment.h"

Equipment::Equipment(const unsigned int id, double firstDayCost, double nextDaysCost, double bail,
                     const std::string &name) try : id(id), firstDayCost(firstDayCost), nextDaysCost(nextDaysCost),
                                                bail(bail), name(name), archive(true), missing(false), description(nullptr) {
    if(firstDayCost <= 0.0 || nextDaysCost <= 0.0 || bail <= 0.0) {
        throw EquipmentException("Prosze podac prawidlowy koszt wyporzycznia");
    }
    if(name.empty()) {
        throw EquipmentException("Prosze podac prawidlowa nazwe");
    }
}
catch(EquipmentException exception) {
    throw exception;
}

void Equipment::setDescription(const StringPtr &description) {
    if(description != nullptr)
        Equipment::description = description;
}

void Equipment::setArchive(bool archive) {
    Equipment::archive = archive;
}

void Equipment::setMissing(bool missing) {
    Equipment::missing = missing;
}

const unsigned int Equipment::getId() const {
    return id;
}

double Equipment::getFirstDayCost() const {
    return firstDayCost;
}

double Equipment::getNextDaysCost() const {
    return nextDaysCost;
}

double Equipment::getBail() const {
    return bail;
}

const std::string &Equipment::getName() const {
    return name;
}

const StringPtr &Equipment::getDescription() const {
    return description;
}

bool Equipment::isArchive() const {
    return archive;
}

bool Equipment::isMissing() const {
    return missing;
}

Equipment::~Equipment() {

}

using namespace std;

std::string Equipment::getEquipmentInfo() {
    string ret;
    ret += "id: " + to_string(getId());
    ret += "; Nazwa: " + getName();
    ret += "; Koszt pierwszego dnia: " + to_string(getFirstDayCost());
    ret += "; Koszt następnych dni: " + to_string(getNextDaysCost());
    return ret;
}

std::string Equipment::getEquipmentFullInfo() {
    string ret;
    ret += getEquipmentInfo();
    ret += "; Opis: ";
    if(getDescription() != nullptr)
        ret += *getDescription();
    return ret;
}
