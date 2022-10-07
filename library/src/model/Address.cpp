//
// Created by student on 31.05.2021.
//

#include "model/Address.h"

using namespace std;

Address::Address(const std::string &city, const std::string &street, const std::string &streetNr) : city(city),
                                                                                                    street(street),
                                                                                                    streetNr(
                                                                                                            streetNr) {}

const std::string &Address::getCity() const {
    return city;
}

void Address::setCity(const std::string &city) {
    if(!city.empty())
        Address::city = city;
}

const std::string &Address::getStreet() const {
    return street;
}

void Address::setStreet(const std::string &street) {
    if(!street.empty())
        Address::street = street;
}

const std::string &Address::getStreetNr() const {
    return streetNr;
}

void Address::setStreetNr(const std::string &streetNr) {
    if(!streetNr.empty())
        Address::streetNr = streetNr;
}

std::string Address::getAddressInfo() {
    string ret;
    ret += getCity() + ", " + getStreet() + " " + getStreetNr();
    return ret;
}
