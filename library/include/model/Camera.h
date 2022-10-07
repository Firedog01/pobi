//
// Created by student on 12.06.2021.
//

#ifndef PROJECT_CAMERA_H
#define PROJECT_CAMERA_H

#include "Equipment.h"

class Camera : public Equipment {
    std::string resolution;
public:
    Camera(const unsigned int id, double firstDayCost, double nextDaysCost, double bail, const std::string &name,
           const std::string &resolution);

    const std::string &getResolution() const;
    void setResolution(const std::string &resolution);

    std::string getEquipmentInfo() override;
    std::string getEquipmentFullInfo() override;
};


#endif //PROJECT_CAMERA_H
