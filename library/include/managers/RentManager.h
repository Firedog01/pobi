//
// Created by student on 31.05.2021.
//

#ifndef INTRODUCTIONPROJECT_RENTMANAGER_H
#define INTRODUCTIONPROJECT_RENTMANAGER_H

#include "model/Rent.h"
#include "repositories/RentRepository.h"

namespace pt = boost::posix_time;

class RentManager {
    RentRepository repository;
public:
    //rezerwacja zostanie utworzona tylko i wyłącznie jeśli
    //  * sprzęt nie jest archiwalny ani zgubiony
    //  * klient nie jest archiwalny
    //  * podany beginTime nie jest datą wcześniejszą niż teraz
    //  * przedział jest podany poprawnie (beginTime < endTime)
    //  * sprzęt w tym czasie nie został już wcześniej zarezerwowany
    //
    //Są 3 możliwe przypadki kiedy sprzęt został wcześniej zarezerwowany:
    //  1. beginTime należy do wcześniej zarezerwowanego przedziału
    //  2. endTime należy do wcześniej zarezerwowanego przedziału
    //  3. jakiś wcześniej zarezerwowany przedział w całości zawiera się pomiędzy beginTime i endTime
    RentPtr makeReservation(ClientPtr client, EquipmentPtr equipment, AddressPtr shippingAddress, pt::ptime beginTime, pt::ptime endTime);
    void cancelReservation(RentPtr reservation);    //usuwa rezerwację z repozytorium
    void returnEquipment(RentPtr rent, bool missing);   //ustawia w wyporzyczeniu flagę eqReturned na true a w sprzęcie ustawia czy sprzęt
        //został zwrócony
    void shipEquipment(RentPtr rent);   //ustawia flagę shipped na true

    std::string checkForShipments();    //tekstowo wypisuje wszystkie nie wysłane sprzęty wraz z danymi klienta i adresem
    std::string getEquipmentNextRents(EquipmentPtr equipment);  //zwraca wszystkie nadchodzące wyporzyczenia danego sprzętu w formie tekstowej
    std::string getEquipmentAllRents(EquipmentPtr equipment);   //zwraca wszystkie wyporzyczenia danego sprzętu
    bool isAvailable(EquipmentPtr equipment);   //sprawdza, czy sprzęt jest akurat teraz wyporzyczony i czy nie jest ani archiwalny ani zgubiony
    double checkClientBalance(ClientPtr client);    //zwraca sumę opłat dla danego klienta

    //poniższe metody zwracają przedział w którym jest dostępny dany sprzęt.
    //jeśli jest więcej niż jeden przedział zamknięty to tylko jeden
    //jeśli sprzęt nie jest wyporzyczony do zwróci przedział od teraz do not_a_date_time
    //jeśli sprzęt jest zniszczony lub archiwalny to przedział będzie od not_a_date_time do not_a_date_time
    pt::ptime whenAvailable(EquipmentPtr equipment);
    pt::ptime untilAvailable(EquipmentPtr equipment);

    std::vector<RentPtr> getClientRents(ClientPtr client);          //wszystkie wyporzyczenia danego klienta. Klient musi nie być archiwalny
    std::vector<RentPtr> getEquipmentRents(EquipmentPtr equipment); //zwraca wszystkie wyporzyczenia danego sprzętu. Sprzęt musi nie być archiwalny ani zgubiony
    std::vector<RentPtr> findRents(RentPredicate predicate);        //szuka wszystkich wyporzyczzeń spełniających predykat
    std::vector<RentPtr> findAllRents();        //zwraca wszystkie wyporzyczenia znajdujące się w repozytorium
    RentPtr getRent(unsigned int id);
};


#endif //INTRODUCTIONPROJECT_RENTMANAGER_H
