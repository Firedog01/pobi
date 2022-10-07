//
// Created by student on 31.05.2021.
//

#include "model/Client.h"

using namespace std;

const std::string &Client::getId() const {
    return ID;
}

IDType Client::getIdType() const {
    return idType;
}

const AddressPtr &Client::getAddressPtr() const {
    return address;
}

bool Client::isArchive() const {
    return archive;
}

void Client::setAddressPtr(const AddressPtr &address) {
    if(address != nullptr)
        Client::address = address;
}

void Client::setArchive(bool archive) {
    Client::archive = archive;
}

const std::string &Client::getFirstName() const {
    return firstName;
}

void Client::setFirstName(const std::string &firstName) {
    if(!firstName.empty())
        Client::firstName = firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

void Client::setLastName(const std::string &lastName) {
    if(!lastName.empty())
        Client::lastName = lastName;
}

const std::string Client::getClientInfo() const {
    string ret;
    ret += getFirstName() + " " + getLastName();
    ret += "; id: ";
    switch(idType) {
        case Passport:
            ret += "Paszport, ";
            break;
        case DowodOsobisty:
            ret += "Dowód osobisty, ";
            break;
    }
    ret += getId();
    ret += "; Adres: " + address->getAddressInfo();

    return ret;
}

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &id, IDType idType, const AddressPtr &address) try : firstName(firstName), lastName(lastName), ID(id), idType(idType), address(address), archive(false) {
    if(firstName.empty()) {
        throw ClientException("Imie nie może byc puste");
    }
    if(lastName.empty()) {
        throw ClientException("Nazwisko nie może byc puste");
    }
    if(id.empty()) {
        throw ClientException("Id nie może byc puste");
    }
    if(address == nullptr) {
        throw ClientException("Prosze podac prawidlowy adres");
    }
}
catch(const ClientException & exception) {
    throw exception;
}
