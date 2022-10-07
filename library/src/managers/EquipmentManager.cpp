//
// Created by student on 31.05.2021.
//

#include "managers/EquipmentManager.h"

using namespace std;

EquipmentPtr
EquipmentManager::registerCamera(double firstDayCost, double nextDaysCost,
                                 double bail, const std::string &name, const std::string &resolution)  try {
    EquipmentPtr ret = make_shared<Camera>(repository.size(), firstDayCost, nextDaysCost, bail, name, resolution);
    repository.add(ret);
    return ret;
}
catch(const EquipmentException &exception) {
    throw exception;
}

EquipmentPtr
EquipmentManager::registerLens(double firstDayCost, double nextDaysCost,
                               double bail, const std::string &name, const std::string &focalLength) try {
    EquipmentPtr ret = make_shared<Lens>(repository.size(), firstDayCost, nextDaysCost, bail, name, focalLength);
    repository.add(ret);
    return ret;
}
catch(const EquipmentException &exception) {
    throw exception;
}

EquipmentPtr
EquipmentManager::registerLighting(double firstDayCost, double nextDaysCost,
                                   double bail, const std::string &name, const std::string &brightness) try {
    EquipmentPtr ret = make_shared<Lighting>(repository.size(), firstDayCost, nextDaysCost, bail, name, brightness);
    repository.add(ret);
    return ret;
}
catch(const EquipmentException & exception) {
    throw exception;
}

EquipmentPtr
EquipmentManager::registerMicrophone(double firstDayCost, double nextDaysCost,
                                     double bail, const std::string &name, const std::string &sensitivity) try {
    EquipmentPtr ret = make_shared<Microphone>(repository.size(), firstDayCost, nextDaysCost, bail, name, sensitivity);
    repository.add(ret);
    return ret;
}
catch(const EquipmentException & exception) {
    throw exception;
}

EquipmentPtr
EquipmentManager::registerTrivet(double firstDayCost, double nextDaysCost,
                                 double bail, const std::string &name, double weight) try {
    EquipmentPtr ret = make_shared<Trivet>(repository.size(), firstDayCost, nextDaysCost, bail, name, weight);
    repository.add(ret);
    return ret;
}
catch(const EquipmentException & exception) {
    throw exception;
}

void EquipmentManager::unregisterEquipment(EquipmentPtr equipment) {
    EquipmentPredicate f;
    f.func = [equipment](EquipmentPtr ptr) {
        return ptr == equipment;
    };
    if(!repository.findBy(f).empty())
        repository.findBy(f)[0]->setArchive(true);
}

EquipmentPtr EquipmentManager::getEquipment(unsigned int id) {
    EquipmentPredicate f;
    f.func = [id](EquipmentPtr ptr) {
        return ptr->getId() == id;
    };
    if(repository.findBy(f).empty()) {
        return nullptr;
    } else {
        return repository.findBy(f)[0];
    }
}

std::vector<EquipmentPtr> EquipmentManager::findEquipment(EquipmentPredicate predicate) {
    EquipmentPredicate f;
    f.func = [predicate](EquipmentPtr ptr) {
        return (predicate.func(ptr) && !ptr->isArchive() && !ptr->isMissing());
    };
    return repository.findBy(f);
}

std::vector<EquipmentPtr> EquipmentManager::getAllEquipment() {
    EquipmentPredicate f;
    f.func = [](EquipmentPtr ptr) {
        return (!ptr->isArchive() && !ptr->isMissing());
    };
    return repository.findBy(f);
}
