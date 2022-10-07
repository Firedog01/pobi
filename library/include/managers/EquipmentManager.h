//
// Created by student on 31.05.2021.
//

#ifndef INTRODUCTIONPROJECT_EQUIPMENTMANAGER_H
#define INTRODUCTIONPROJECT_EQUIPMENTMANAGER_H

#include "repositories/EquipmentRepository.h"
#include "model/Equipment.h"
#include "typedefs.h"

class EquipmentManager {
    EquipmentRepository repository;
public:
    //5 klas do rejestrowania nowego sprzętu
    //UWAGA: po utworzeniu nowy sprzęt ma pole archive na true
    EquipmentPtr registerCamera(double firstDayCost, double nextDaysCost,
                                double bail, const std::string &name, const std::string &resolution);
    EquipmentPtr registerLens(double firstDayCost, double nextDaysCost,
                                double bail, const std::string &name, const std::string &focalLength);
    EquipmentPtr registerLighting(double firstDayCost, double nextDaysCost,
                                double bail, const std::string &name, const std::string &brightness);
    EquipmentPtr registerMicrophone(double firstDayCost, double nextDaysCost,
                                double bail, const std::string &name, const std::string &sensitivity);
    EquipmentPtr registerTrivet(double firstDayCost, double nextDaysCost,
                                double bail, const std::string &name, double weight);
    void unregisterEquipment(EquipmentPtr equipment); //zmienia pole archive na true
    EquipmentPtr getEquipment(unsigned int id);     //ponieważ id jest automatycznie inkrementowane można zorientować się
        //jakie id zostało nadane nowo utworzonemu wyporzyczeniu na podstawie ilości elementów w repozytorium
    std::vector<EquipmentPtr> findEquipment(EquipmentPredicate predicate);  //zwraca wszystkie sprzęty które spełniają zadany predykat
        //a ponadto nie są ani archiwalne ani zniszczone
    std::vector<EquipmentPtr> getAllEquipment(); //zwraca wszystkie sprzęty które nie są ani archiwalne ani zniszczone
};


#endif //INTRODUCTIONPROJECT_EQUIPMENTMANAGER_H
