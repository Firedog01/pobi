//
// Created by student on 12.06.2021.
//

#ifndef PROJECT_LIGHTING_H
#define PROJECT_LIGHTING_H

#include "Equipment.h"

class Lighting : public Equipment {
    std::string brightness;
public:
    Lighting(const unsigned int id, double firstDayCost, double nextDaysCost, double bail, const std::string &name,
             const std::string &brightness);

    const std::string &getBrightness() const;
    void setBrightness(const std::string &brightness);

    std::string getEquipmentInfo() override;
    std::string getEquipmentFullInfo() override;
};


#endif //PROJECT_LIGHTING_H
