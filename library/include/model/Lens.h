//
// Created by student on 12.06.2021.
//

#ifndef PROJECT_LENS_H
#define PROJECT_LENS_H

#include "Equipment.h"

class Lens : public Equipment {
    std::string focalLength;
public:
    Lens(const unsigned int id, double firstDayCost, double nextDaysCost, double bail, const std::string &name,
         const std::string &focalLength);

    const std::string &getFocalLength() const;
    void setFocalLength(const std::string &focalLength);

    std::string getEquipmentInfo() override;
    std::string getEquipmentFullInfo() override;
};


#endif //PROJECT_LENS_H
