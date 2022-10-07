//
// Created by student on 12.06.2021.
//

#ifndef PROJECT_TRIVET_H
#define PROJECT_TRIVET_H

#include "Equipment.h"

class Trivet : public Equipment {
    double weight;
public:
    Trivet(const unsigned int id, double firstDayCost, double nextDaysCost, double bail,
           const std::string &name, double weight);

    double getWeight() const;
    void setWeight(double weight);

    std::string getEquipmentInfo() override;
    std::string getEquipmentFullInfo() override;
};


#endif //PROJECT_TRIVET_H
