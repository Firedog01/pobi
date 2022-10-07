//
// Created by student on 31.05.2021.
//

#ifndef INTRODUCTIONPROJECT_CLIENTMANAGER_H
#define INTRODUCTIONPROJECT_CLIENTMANAGER_H

#include "repositories/ClientRepository.h"
#include "model/Client.h"
#include "typedefs.h"

//klasa managera klientów
class ClientManager {
    ClientRepository repository;
public:
    //jeśli kllient o zadanej kombinacji id i idtype istnieje w repozytorium to jest zwracany jego wskaźnik
    //jeśli nie to jest tworzony nowy klient i zwracany wskaźnik do nowego klienta
    ClientPtr registerClient(const std::string &firstName, const std::string &lastName, const std::string &id, IDType idType, const AddressPtr &address);
    void unregisterClient(ClientPtr client);    //zmienia pole klienta archive na true. Nie usuwa obiektu klienta
    ClientPtr getClient(std::string id, IDType idtype); //potrzebna jest para id i idtype żeby zidentyfikować klienta
    std::vector<ClientPtr> findClients(ClientPredicate predicate);  //zwraca wszystkich niearchiwalnych klientów spełniających predykat
    std::vector<ClientPtr> getAllClients();     //zwraca wszystkich niearchiwalnych klientów znajdujących się w repozytorium
};


#endif //INTRODUCTIONPROJECT_CLIENTMANAGER_H
