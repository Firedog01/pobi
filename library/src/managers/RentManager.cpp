//
// Created by student on 31.05.2021.
//

#include "managers/RentManager.h"

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

RentPtr RentManager::makeReservation(ClientPtr client, EquipmentPtr equipment, AddressPtr shippingAddress, pt::ptime beginTime, pt::ptime endTime) try {
    if(equipment->isMissing() || equipment->isArchive()) {
        return nullptr;
    }
    if(client->isArchive()) {
        return nullptr;
    }
    if(beginTime < pt::second_clock::local_time()) {
        return nullptr;
    }
    if(beginTime > endTime) {
        return nullptr;
    }
    bool good = true;
    vector<RentPtr> equipmentRents = getEquipmentRents(equipment);
    for(int i = 0; i < equipmentRents.size(); i++) {
        if(beginTime > equipmentRents[i]->getBeginTime() && beginTime < equipmentRents[i]->getEndTime()) {
            good = false;
        }
        if(endTime > equipmentRents[i]->getBeginTime() && endTime < equipmentRents[i]->getEndTime()) {
            good = false;
        }
        if(beginTime < equipmentRents[i]->getBeginTime() && endTime > equipmentRents[i]->getEndTime()) {
            good = false;
        }
    }
    if(good) {
        RentPtr ret = make_shared<Rent>(repository.size(), client, equipment, shippingAddress, beginTime, endTime);
        repository.add(ret);
        return ret;
    } else {
        return nullptr;
    }
}
catch(const RentException &exception) {
    throw exception;
}

void RentManager::cancelReservation(RentPtr reservation) {
    repository.remove(reservation);
}

pt::ptime RentManager::whenAvailable(EquipmentPtr equipment) {
    if(equipment->isArchive() || equipment->isMissing()) {
        return pt::not_a_date_time;
    }
    pt::ptime when = pt::second_clock::local_time(); //obecny czas
    vector<RentPtr> equipmentRents = getEquipmentRents(equipment);
    for(int i = 0; i < equipmentRents.size(); i++) {
        if(when > equipmentRents[i]->getBeginTime() && when < equipmentRents[i]->getEndTime()) {
            when = equipmentRents[i]->getEndTime();
        }
    }
    return when;
}

pt::ptime RentManager::untilAvailable(EquipmentPtr equipment) {
    pt::ptime until = pt::not_a_date_time;
    if(equipment->isArchive() || equipment->isMissing()) {
        return until;
    }
    pt::ptime when = whenAvailable(equipment);
    vector<RentPtr> equipmentRents = getEquipmentRents(equipment);
    for(int i = 0; i < equipmentRents.size(); i++) {
        if(when < equipmentRents[i]->getBeginTime()) {
            until = equipmentRents[i]->getEndTime();
        }
    }
    return until;
}


std::vector<RentPtr> RentManager::getEquipmentRents(EquipmentPtr equipment) {
    RentPredicate predicate;
    predicate.func = [equipment](RentPtr ptr) {
        return ptr->getEquipment() == equipment && !ptr->getEquipment()->isMissing() && !ptr->getEquipment()->isArchive();
    };
    return findRents(predicate);
}

std::vector<RentPtr> RentManager::findRents(RentPredicate predicate) {
    return repository.findBy(predicate);
}

std::vector<RentPtr> RentManager::getClientRents(ClientPtr client) {
    RentPredicate predicate;
    predicate.func = [client](RentPtr ptr) {
        return ptr->getClient() == client && !ptr->getClient()->isArchive();
    };
    return findRents(predicate);
}

std::vector<RentPtr> RentManager::findAllRents() {
    return repository.findAll();
}

RentPtr RentManager::getRent(unsigned int id) {
    for(int i = 0; i < repository.size(); i++) {
        if(repository.get(i)->getId() == id) {
            return repository.get(i);
        }
    }
    return nullptr;
}

void RentManager::returnEquipment(RentPtr rent, bool missing) {
    rent->setEqReturned(true);
    rent->getEquipment()->setMissing(missing);
}

double RentManager::checkClientBalance(ClientPtr client) {
    vector<RentPtr> clientRents = getClientRents(client);
    double balance = 0.0;
    for(int i = 0; i < clientRents.size(); i++) {
        balance += clientRents[i]->getRentCost();
    }
    return balance;
}

bool RentManager::isAvailable(EquipmentPtr equipment) {
    if(whenAvailable(equipment) == pt::second_clock::local_time()) {
        return true;
    } else {
        return false;
    }
}

std::string RentManager::getEquipmentAllRents(EquipmentPtr equipment) {
    RentPredicate pred;
    string ret;
    pred.func = [equipment](RentPtr ptr) {
        return ptr->getEquipment() == equipment;
    };
    vector<RentPtr> allEqRents = findRents(pred);
    for(int i = 0; i < allEqRents.size(); i++) {
        ret += allEqRents[i]->getRentInfo() + '\n';
    }
    return ret;
}

std::string RentManager::getEquipmentNextRents(EquipmentPtr equipment) {
    RentPredicate pred;
    string ret;
    pt::ptime now = pt::second_clock::local_time();
    pred.func = [equipment, now](RentPtr ptr) {
        return ptr->getEquipment() == equipment && ptr->getBeginTime() > now;
    };
    vector<RentPtr> allEqRents = findRents(pred);
    for(int i = 0; i < allEqRents.size(); i++) {
        ret += allEqRents[i]->getRentInfo() + '\n';
    }
    return ret;
}

std::string RentManager::checkForShipments() {
    string ret;
    RentPredicate pred;
    pt::ptime now = pt::second_clock::local_time();
    pred.func = [now](RentPtr ptr) {
        return ptr->getBeginTime() > now || !ptr->isShipped();
    };
    vector<RentPtr> rents = findRents(pred);
    for(int i = 0; i < rents.size(); i++) {
        ret += rents[i]->getRentInfo() + '\n';
    }
    return ret;
}

void RentManager::shipEquipment(RentPtr rent) {
    rent->setShipped(true);
}
