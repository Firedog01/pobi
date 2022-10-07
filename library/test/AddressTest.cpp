//
// Created by student on 12.06.2021.
//

#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "model/Address.h"
#include "typedefs.h"

using namespace std;

struct TestSuiteAddressFixture {
    const std::string city1 = "Zgierz";
    const std::string city2 = "Uc";
    const std::string street1 = "Prymulkowa";
    const std::string street2 = "Czeresniowa";
    const std::string nr1 = "432";
    const std::string nr2 = "23A";
    AddressPtr address;
    TestSuiteAddressFixture() {
        address = make_shared<Address>(city1, street1, nr1);
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstructorTest) {
        BOOST_TEST(address->getCity() == city1);
        BOOST_TEST(address->getStreet() == street1);
        BOOST_TEST(address->getStreetNr() == nr1);
    }

    BOOST_AUTO_TEST_CASE(SetCityTest) {
        BOOST_TEST_REQUIRE(address->getCity() == city1);
        address->setCity("");
        BOOST_TEST(address->getCity() == city1);
        address->setCity(city2);
        BOOST_TEST(address->getCity() == city2);
    }

    BOOST_AUTO_TEST_CASE(SetStreetTest) {
        BOOST_TEST_REQUIRE(address->getStreet() == street1);
        address->setStreet("");
        BOOST_TEST(address->getStreet() == street1);
        address->setStreet(street2);
        BOOST_TEST(address->getStreet() == street2);
    }

    BOOST_AUTO_TEST_CASE(SetStreetNrTest) {
        BOOST_TEST_REQUIRE(address->getStreetNr() == nr1);
        address->setStreetNr("");
        BOOST_TEST(address->getStreetNr() == nr1);
        address->setStreetNr(nr2);
        BOOST_TEST(address->getStreetNr() == nr2);
    }


BOOST_AUTO_TEST_SUITE_END()
