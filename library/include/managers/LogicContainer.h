//
// Created by student on 13.06.2021.
//

#ifndef PROJECT_LOGICCONTAINER_H
#define PROJECT_LOGICCONTAINER_H

#include "managers/ClientManager.h"
#include "managers/RentManager.h"
#include "managers/EquipmentManager.h"


//Klasa utworzona w celu ułatwienia pisania testów i weryfikacji poprawności

class LogicContainer {
    ClientManager clientMan;
    EquipmentManager eqMan;
    RentManager rentMan;
public:
    LogicContainer();
    EquipmentManager &getEqMan();
    RentManager &getRentMan();
    ClientManager &getClientMan();

};


#endif //PROJECT_LOGICCONTAINER_H
