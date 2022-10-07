//
// Created by student on 31.05.2021.
//

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

#include <vector>

#include "Address.h"
#include "typedefs.h"

//klient może identyfikować się dwoma rodajami dokumentów, paszportem i dowodem osobistym.
//w przyszłości można rozszerzyć metody identyfikacji
enum IDType {DowodOsobisty, Passport};

class Client {
    std::string firstName;
    std::string lastName;

    std::string ID; //zakładamy, że sposób identyfikacji się nie zmienia, więc para id i idType posłóży nam
    IDType idType;  //do identyfikacji klientów. Przez to nie mogą być modyfikowane

    AddressPtr address; //adres zamieszkania klienta
    bool archive;
public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &id, IDType idType,
           const AddressPtr &address);

    //standardowe metody dostępowe
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getId() const;
    IDType getIdType() const;
    const AddressPtr &getAddressPtr() const;
    bool isArchive() const;

    void setFirstName(const std::string &firstName);    //
    void setLastName(const std::string &lastName);      //nie mogą być puste
    void setAddressPtr(const AddressPtr &address);
    void setArchive(bool archive);

    const std::string getClientInfo() const;    //opisowo zwraca wszystkie informacje o kliencie
    const std::string getInfo() const {return getClientInfo();} //alias do getClientInfo potrzebny przez szablon repozytorium
};

#endif //PROJECT_CLIENT_H
