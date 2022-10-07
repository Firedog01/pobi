#include <iostream>
#include <boost/date_time.hpp>
#include <memory>

#include "managers/LogicContainer.h"
#include "typedefs.h"

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

int main () {
    LogicContainer container
    try {
        Client cl();
    }
    catch(ClientException ex) {

    }
    cout << "---------------SPRZĘT W SKLEPIE--------------\n";
    vector<EquipmentPtr> equipment = container.getEqMan().getAllEquipment();
    for(int i = 0; i < equipment.size(); i++) {
        cout << equipment[i]->getInfo() << "\n\n";
    }
    cout << "------------ZAREJESTROWANI KLENCI------------\n";
    vector<ClientPtr> clients = container.getClientMan().getAllClients();
    for(int i = 0; i < clients.size(); i++) {
        cout << clients[i]->getInfo() << "\n\n";
    }
    cout << "----------------WYPORZYCZENIA----------------\n";
    vector<RentPtr> rents = container.getRentMan().findAllRents();
    for(int i = 0; i < rents.size(); i++) {
        cout << rents[i]->getInfo() << "\n\n";
    }
    return 0;
}
