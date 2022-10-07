//
// Created by student on 13.06.2021.
//

#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>
#include <boost/date_time.hpp>
#include "model/Trivet.h"
#include "managers/LogicContainer.h"
#include "typedefs.h"
namespace gr = boost::gregorian;
namespace pt = boost::posix_time;

struct TestSuiteRentManagerFixture {
    LogicContainerPtr container;
    AddressPtr address;
    ClientPtr client;
    EquipmentPtr trivet;
    ClientPtr client2;

    TestSuiteRentManagerFixture() {

        container = std::make_shared<LogicContainer>();
        address = std::make_shared<Address>("Miasto", "Ulica", "3");
        client = std::make_shared<Client>("Jan","Kowalski","2137", DowodOsobisty,address);
        trivet = std::make_shared<Trivet>(3,100,120,200,"statyw",5);
        trivet->setArchive(false);
        client2 = std::make_shared<Client>("Janek","Kowal","420", DowodOsobisty,address);
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManager, TestSuiteRentManagerFixture)


    BOOST_AUTO_TEST_CASE(ReservationTest) {
        RentPtr newOne = container->getRentMan().makeReservation(client,trivet,address,pt::ptime(gr::date(2021, 12, 27)),pt::ptime(gr::date(2021,12,30)));
        BOOST_TEST(container->getRentMan().whenAvailable(trivet)!=gr::not_a_date_time);

    }

    BOOST_AUTO_TEST_CASE(RentWhenAlreadyRentedTest) {

        RentPtr newOne = container->getRentMan().makeReservation(client,trivet,address,pt::ptime(gr::date(2021, 12, 27)),pt::ptime(gr::date(2021,12,30)));
        RentPtr newOne2 = container->getRentMan().makeReservation(client2,trivet,address,pt::ptime(gr::date(2021, 12, 28)),pt::ptime(gr::date(2021,12,29)));
        BOOST_TEST(newOne2==nullptr);

    }

    BOOST_AUTO_TEST_CASE(AvailableEquipment) {
        RentPtr newOne = container->getRentMan().makeReservation(client,trivet,address,pt::ptime(gr::date(2021, 12, 27)),pt::ptime(gr::date(2021,12,30)));
        BOOST_TEST(container->getRentMan().isAvailable(trivet));
}

    BOOST_AUTO_TEST_CASE(ClientBalance){
        RentPtr newOne = container->getRentMan().makeReservation(client,trivet,address,pt::ptime(gr::date(2021, 12, 27)),pt::ptime(gr::date(2021,12,30)));
        container->getRentMan().returnEquipment(newOne,false);
        BOOST_TEST(container->getRentMan().checkClientBalance(client)==460);
}

    BOOST_AUTO_TEST_CASE(CancelReservation){
        RentPtr newOne = container->getRentMan().makeReservation(client,trivet,address,pt::ptime(gr::date(2021, 12, 27)),pt::ptime(gr::date(2021,12,30)));
        container->getRentMan().cancelReservation(newOne);
        BOOST_TEST(container->getRentMan().findAllRents()!=container->getRentMan().getClientRents(client));
}
    BOOST_AUTO_TEST_CASE(ReturnEquipment){
        RentPtr newOne = container->getRentMan().makeReservation(client,trivet,address,pt::ptime(gr::date(2021, 12, 27)),pt::ptime(gr::date(2021,12,30)));
        container->getRentMan().returnEquipment(newOne,false);
        BOOST_TEST(newOne->isEqReturned()==true);
        BOOST_TEST(newOne->getEquipment()->isMissing()==false);
}
    BOOST_AUTO_TEST_CASE(Shipping){
        RentPtr newOne = container->getRentMan().makeReservation(client,trivet,address,pt::ptime(gr::date(2021, 12, 27)),pt::ptime(gr::date(2021,12,30)));
        BOOST_TEST(newOne->isShipped()==false);
        container->getRentMan().shipEquipment(newOne);
        BOOST_TEST(newOne->isShipped()==true);
}
BOOST_AUTO_TEST_SUITE_END()