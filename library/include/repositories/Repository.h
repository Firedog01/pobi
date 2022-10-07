//
// Created by student on 31.05.2021.
//

#ifndef INTRODUCTIONPROJECT_REPOSITORY_H
#define INTRODUCTIONPROJECT_REPOSITORY_H

#include <vector>
#include "model/Rent.h"
#include "typedefs.h"

//szablon klasy repozytorium
template<class T>
class Repository {
    std::vector<T> repository;
public:
    T get(const unsigned int& pos) const; //zwraca element w repozytorium na pozycji id
    void add(T ptr);                        //dodaje element do repozytorium
    void remove(T ptr);                     //usuwa element z repozytorium
    std::string report() const;             //wyświetla informacje o elementach znajdujących się w repozytorium
    unsigned int size() const;              //zwraca ilość elementów przechowywanych w repozytorium
    std::vector<T> findBy(Predicate<T> predicate);  //na podstawie predykatu zwraca wszystkie pasujące elementy w postaci tablicy
    std::vector<T> findAll();               //zwraca wszystkie elementy repozytorium w postaci tablicy
};

//deklaracje wyprzedzające które typy repozytoriów będą wykorzystywane
//potrzebne do procesu kompilacji
template class Repository<RentPtr>;
template class Repository<EquipmentPtr>;
template class Repository<ClientPtr>;

#endif //INTRODUCTIONPROJECT_REPOSITORY_H
