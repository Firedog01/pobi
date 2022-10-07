//
// Created by student on 31.05.2021.
//

#include "model/Rent.h"

using namespace std;

Rent::Rent(int id, ClientPtr client, EquipmentPtr equipment, AddressPtr shippingAddress,
           const pt::ptime &beginTime, const pt::ptime &endTime) try : id(id), client(client), equipment(equipment),
                                                                   shippingAddress(shippingAddress),
                                                                   beginTime(beginTime), endTime(endTime), shipped(false),
                                                                   eqReturned(false) {
    if(client == nullptr) {
        throw RentException("Client nie może być nullptr");
    }
    if(equipment == nullptr) {
        throw RentException("Equipment nie może być nullptr");
    }
    if(shippingAddress == nullptr) {
        throw RentException("ShippingAddress nie może być nullptr");
    }
    if(beginTime == pt::not_a_date_time || endTime == pt::not_a_date_time) {
        throw RentException("Prosze podac prawidlowa date");
    }
}
catch(RentException exception) {
    throw exception;
}

ClientPtr Rent::getClient() const {
    return client;
}

EquipmentPtr Rent::getEquipment() const {
    return equipment;
}

AddressPtr Rent::getShippingAddress() const {
    return shippingAddress;
}

bool Rent::isShipped() const {
    return shipped;
}

void Rent::setShipped(bool shipped) {
    Rent::shipped = shipped;
}

void Rent::setEqReturned(bool eqReturned) {
    Rent::eqReturned = eqReturned;
}

int Rent::getId() const {
    return id;
}

const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

bool Rent::isEqReturned() const {
    return eqReturned;
}

double Rent::getRentCost() {
    if(isEqReturned()) {
        if(getEquipment()->isMissing()) {
            return getEquipment()->getBail();
        } else {
            pt::time_duration durPTime = pt::time_period(getBeginTime(), getEndTime()).length();
            unsigned int dur = durPTime.hours() / 24 + 1; //ilość dni wyporzyczenia
            return getEquipment()->getFirstDayCost() + (dur - 1) * getEquipment()->getNextDaysCost(); //długość wyporzyczenia musi być większa niż 1
        }
    } else {
        return 0;
    }
}

const std::string Rent::getRentInfo() const {
    string ret;
    ret += "id: " + to_string(getId()) + "\n";
    ret += "Klient: " + getClient()->getClientInfo() + "\n";
    ret += "Sprzęt: " + getEquipment()->getEquipmentInfo() + "\n";
    ret += "Adres dostawy: " + getShippingAddress()->getAddressInfo() + "\n";
    ret += "Czas wyporzyczenia: ";
    stringstream str;
    str << getBeginTime() << " do " << getEndTime();
    ret += str.str();
    return ret;
}


