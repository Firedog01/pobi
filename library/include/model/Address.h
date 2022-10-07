//
// Created by student on 31.05.2021.
//

#ifndef PROJECT_ADDRESS_H
#define PROJECT_ADDRESS_H

#include <string>

//klasa adresu używana przez klasy Client i Rent
class Address {
    std::string city;
    std::string street;
    std::string streetNr;
public:
    Address(const std::string &city, const std::string &street, const std::string &streetNr);

    const std::string &getCity() const;
    const std::string &getStreet() const;
    const std::string &getStreetNr() const;

    void setCity(const std::string &city);          //
    void setStreet(const std::string &street);      //
    void setStreetNr(const std::string &streetNr);  //nie mogą być puste

    std::string getAddressInfo();   //opisowo zwraca informacje o adresie (w jednej linii)
};


#endif //PROJECT_ADDRESS_H
