//
// Created by student on 12.06.2021.
//

#ifndef PROJECT_MICROPHONE_H
#define PROJECT_MICROPHONE_H

#include "Equipment.h"

class Microphone : public Equipment {
    std::string sensitivity;
public:
    Microphone(const unsigned int id, double firstDayCost, double nextDaysCost, double bail, const std::string &name,
               const std::string &sensitivity);

    const std::string &getSensitivity() const;
    void setSensitivity(const std::string &sensitivity);

    std::string getEquipmentInfo() override;
    std::string getEquipmentFullInfo() override;
};


#endif //PROJECT_MICROPHONE_H
