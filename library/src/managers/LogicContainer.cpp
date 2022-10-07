//
// Created by student on 13.06.2021.
//

#include "managers/LogicContainer.h"

EquipmentManager &LogicContainer::getEqMan(){
    return eqMan;
}

RentManager &LogicContainer::getRentMan()  {
    return rentMan;
}

ClientManager &LogicContainer::getClientMan() {
    return clientMan;
}

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

LogicContainer::LogicContainer() try {
    AddressPtr address1 = make_shared<Address>("Uc", "Czeresniowa", "23A");
    AddressPtr address2 = make_shared<Address>("Warszawa", "Wisniowa", "48");
    AddressPtr address3 = make_shared<Address>("Krakow", "Ananasowa", "3C");
    AddressPtr address4 = make_shared<Address>("Zakopane", "Brzoskwiniowa", "75");

    string id1 = "4178632";
    string id2 = "SDK43987";
    string id3 = "LFKSJDL";

    getClientMan().registerClient("Zbigniew", "Nowak", id1, DowodOsobisty, address1);
    getClientMan().registerClient("Andrzej", "Wisinewski", id2, DowodOsobisty, address2);
    getClientMan().registerClient("Stefan", "Kowalski", id3, DowodOsobisty, address3);

    getEqMan().registerCamera(100.0, 50.0, 2000.0, "Panasonic GX80", "4K");
    getEqMan().registerLens(30.0, 25.0, 1500.0, "jdksahg", "100 - 350 mm");
    getEqMan().registerLighting(40.0, 30.0, 1200.0, "kjfh", "300 W");

    getEqMan().getEquipment(0)->setArchive(false);
    getEqMan().getEquipment(1)->setArchive(false);
    getEqMan().getEquipment(2)->setArchive(false);

    const pt::ptime timeNow = pt::second_clock::local_time();
    const pt::ptime time2d = timeNow + pt::hours(24*2);
    const pt::ptime time4d = timeNow + pt::hours(24*4);
    const pt::ptime time6d = timeNow + pt::hours(24*6);
    const pt::ptime time7d = timeNow + pt::hours(24*7);
    const pt::ptime time9d = timeNow + pt::hours(24*9);
    const pt::ptime time11d = timeNow + pt::hours(24*11);

    getRentMan().makeReservation(getClientMan().getClient(id3, DowodOsobisty), getEqMan().getEquipment(2), address3, timeNow, time2d);
    getRentMan().makeReservation(getClientMan().getClient(id1, DowodOsobisty), getEqMan().getEquipment(0), address1, time2d, time4d);
    getRentMan().makeReservation(getClientMan().getClient(id1, DowodOsobisty), getEqMan().getEquipment(1), address1, time4d, time6d);
    getRentMan().makeReservation(getClientMan().getClient(id2, DowodOsobisty), getEqMan().getEquipment(2), address2, time4d, time6d);
    getRentMan().makeReservation(getClientMan().getClient(id2, DowodOsobisty), getEqMan().getEquipment(0), address4, time6d, time7d);
    getRentMan().makeReservation(getClientMan().getClient(id2, DowodOsobisty), getEqMan().getEquipment(0), address2, time9d, time11d);

    getRentMan().returnEquipment(getRentMan().getRent(0), false);
    getRentMan().returnEquipment(getRentMan().getRent(1), false);
    getRentMan().returnEquipment(getRentMan().getRent(2), true);
    getRentMan().returnEquipment(getRentMan().getRent(3), false);
    getRentMan().returnEquipment(getRentMan().getRent(4), false);
    getRentMan().returnEquipment(getRentMan().getRent(5), false);

    /* spis wszystkich wyporzyczeń w kontenerze:
     *
     * 3 klienci: 1, 2, 3
     *                  |<- teraz
     * Kamera(id: 0)    |   |-1-|   |-2-|   |-2-|
     * Obiektyw(id: 1)  |       |-1-x
     * Lampa(id: 2)     |-3-|   |-2-|
     *       czas:      +0  +2  +4  +6  +7  +9  +11
     *
     * x - sprzęt zgubiony
     */
}
catch(const RentException &exception) {
    throw exception;
}
catch(const ClientException &exception) {
    throw exception;
}
catch(const EquipmentException &exception) {
    throw exception;
}


