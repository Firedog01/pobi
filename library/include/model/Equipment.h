//
// Created by student on 31.05.2021.
//

#ifndef PROJECT_EQUIPMENT_H
#define PROJECT_EQUIPMENT_H

#include <string>

#include "typedefs.h"

//wirtualna klasa sprzętu
//UWAGA: nie można utworzyć obiektu klasy Equipment, tylko jej klasy pochodne
class Equipment {
    const unsigned int id;  //identyfikator, inkrementowany automatycznie
    double firstDayCost;    //koszt pierwszego dnia wyporzyczenia
    double nextDaysCost;    //koszt kolejnych dni wyporzyczeń, zwykle niższy
    double bail;            //koszt wykupienia sprzętu. Naliczany automatycznie w przypadku zgubienia

    std::string name;   //nazwa ogólna
    StringPtr description; //opis. Nie musi być dodany żeby klasa działała poprawnie

    bool archive; //metoda archiwizacji
    bool missing; //czy sprzęt został zgubiony
public:
    //konstruktor nie potrzebuje descriprion żeby działać poprawnie
    //UWAGA: domyślnie konstruktor ustawia equipment na archiwalny
    Equipment(const unsigned int id, double firstDayCost, double nextDaysCost, double bail, const std::string &name);

    //standardowe metody dostępowe
    const unsigned int getId() const;
    double getFirstDayCost() const;
    double getNextDaysCost() const;
    double getBail() const;
    const std::string &getName() const;
    const StringPtr &getDescription() const;
    bool isArchive() const;
    bool isMissing() const;

    void setDescription(const StringPtr &description);  //nie może być nullptr
    void setArchive(bool archive);
    void setMissing(bool missing);

    virtual std::string getEquipmentInfo();     //zwraca informacje w postaci tekstowej o wyporzyczonym sprzęcie bez opisu
    virtual std::string getEquipmentFullInfo(); //zwraca informacje o wyporzyczonym sprzęcie z opisem
    std::string getInfo() {return getEquipmentInfo();}  //alias potrzebny przez szablon repozytorium

    virtual ~Equipment() = 0;   //wirtualny konstruktor, przez którego cała klasa jest wirtualna
};


#endif //PROJECT_EQUIPMENT_H
