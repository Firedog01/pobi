//
// Created by student on 31.05.2021.
//

#ifndef PROJECT_RENT_H
#define PROJECT_RENT_H

#include <boost/date_time.hpp>

#include "Client.h"
#include "model/Camera.h"
#include "model/Lens.h"
#include "model/Lighting.h"
#include "model/Microphone.h"
#include "model/Trivet.h"
#include "typedefs.h"

namespace pt = boost::posix_time;

class Rent {
    int id;
    ClientPtr const client;
    EquipmentPtr const equipment;
    AddressPtr const shippingAddress;
    pt::ptime beginTime;
    pt::ptime endTime;
    bool shipped;
    bool eqReturned; //false - sprzęt jeszcze nie oddany, true - sprzęt oddany lub zgubiony
public:
    Rent(int id, ClientPtr client, EquipmentPtr equipment, AddressPtr shippingAddress,
         const pt::ptime &beginTime, const pt::ptime &endTime);

    void setShipped(bool shipped);
    void setEqReturned(bool eqReturned);

    int getId() const;
    ClientPtr getClient() const;
    EquipmentPtr getEquipment() const;
    AddressPtr getShippingAddress() const;
    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;
    bool isShipped() const;
    bool isEqReturned() const;

    double getRentCost();
    const std::string getRentInfo() const;
    const std::string getInfo() const {return getRentInfo();}
};

#endif //PROJECT_RENT_H
