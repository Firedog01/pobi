//
// Created by student on 12.06.2021.
//

#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "model/Rent.h"

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteRentFixture {
    const unsigned int id = 2;
    const double firstDayCost = 100.0;
    const double nextDaysCost = 50.0;
    const double bail = 2000.0;
    const string name = "Nazwa1";

    ClientPtr client;
    EquipmentPtr equipment;
    AddressPtr address1;
    AddressPtr address2;
    RentPtr rent23h59m;
    RentPtr rent24h;
    RentPtr rent5d;

    const pt::ptime timeZero = pt::ptime(gr::date(2020, 9, 04), pt::hours(22) + pt::minutes(36) + pt::seconds(0 ));
    const pt::ptime time23h59m = pt::ptime(gr::date(2020,9,05),pt::hours(22)+pt::minutes(35)+pt::seconds(0 ));
    const pt::ptime time24h = pt::ptime(gr::date(2020,9,05),pt::hours(22)+pt::minutes(36)+pt::seconds(0 ));
    const pt::ptime time5d = pt::ptime(gr::date(2020, 9, 9), pt::hours(22) + pt::minutes(36) + pt::seconds(0 ));

    TestSuiteRentFixture() {
        address1 = make_shared<Address>("Zgierz", "Prymulkowa", "432");
        address2 = make_shared<Address>("Warszawa", "Wisniowa", "48");
        client = make_shared<Client>("Zbigniew", "Nowak", "3241231", Passport, address1);
        equipment = make_shared<Camera>(0, firstDayCost, nextDaysCost, bail, name, "1920x1080");
        rent23h59m  = make_shared<Rent>(1, client, equipment, address2, timeZero, time23h59m);
        rent24h     = make_shared<Rent>(id, client, equipment, address2, timeZero, time24h);
        rent5d      = make_shared<Rent>(4, client, equipment, address2, timeZero, time5d);
    }
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstructorTest) {
        BOOST_TEST(rent24h->getId() == id);
        BOOST_TEST(rent24h->getClient() == client);
        BOOST_TEST(rent24h->getEquipment() == equipment);
        BOOST_TEST(rent24h->getShippingAddress() == address2);
        BOOST_TEST(rent24h->getBeginTime() == timeZero);
        BOOST_TEST(rent24h->getEndTime() == time24h);
        BOOST_TEST(rent24h->isShipped() == false);
        BOOST_TEST(rent24h->isEqReturned() == false);
    }

    BOOST_AUTO_TEST_CASE(SetShippedTest) {
        BOOST_TEST_REQUIRE(rent24h->isShipped() == false);
        rent24h->setShipped(true);
        BOOST_TEST(rent24h->isShipped() == true);
        rent24h->setShipped(false);
    }

    BOOST_AUTO_TEST_CASE(SetEqReturnedTest) {
        BOOST_TEST_REQUIRE(rent24h->isEqReturned() == false);
        rent24h->setEqReturned(true);
        BOOST_TEST(rent24h->isEqReturned() == true);
        rent24h->setEqReturned(false);
    }

    BOOST_AUTO_TEST_CASE(GetRentCostTestTime23h59m) {
        rent23h59m->setEqReturned(true);
        BOOST_TEST(rent23h59m->getRentCost() == firstDayCost);
    }

    BOOST_AUTO_TEST_CASE(GetRentCostTestTime24h) {
        rent24h->setEqReturned(true);
        BOOST_TEST(rent24h->getRentCost() == firstDayCost + nextDaysCost);
    }

    BOOST_AUTO_TEST_CASE(GetRentCostTestTime5d) {
        rent5d->setEqReturned(true);
        BOOST_TEST(rent5d->getRentCost() == firstDayCost + 5 * nextDaysCost);
    }

    BOOST_AUTO_TEST_CASE(GetRentCostTestBailed) {
        rent24h->getEquipment()->setMissing(true);
        rent24h->setEqReturned(true);
        BOOST_TEST(rent24h->getRentCost() == bail);
    }


BOOST_AUTO_TEST_SUITE_END()
