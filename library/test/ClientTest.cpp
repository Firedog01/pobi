//
// Created by student on 10.06.2021.
//

#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "model/Client.h"

using namespace std;

struct TestSuiteClientFixture {
    const string testFirstName1 = "Zbigniew";
    const string testFirstName2 = "Andrzej";
    const string testLastName1 = "Nowak";
    const string testLastName2 = "Wisniewski";
    const IDType testIdType1 = Passport;
    const string testPersonalID1 = "3241231";
    AddressPtr testAddress1;
    AddressPtr testAddress2;
    ClientPtr client;
    TestSuiteClientFixture() {
        testAddress1 = make_shared<Address>("Uc", "Czeresniowa", "23A");
        testAddress2 = make_shared<Address>("Warszawa", "Wisniowa", "48");
        client = make_shared<Client>(testFirstName1, testLastName1, testPersonalID1, testIdType1, testAddress1);
    }
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstructorTest) {
        BOOST_TEST(client->getFirstName() == testFirstName1);
        BOOST_TEST(client->getLastName() == testLastName1);
        BOOST_TEST(client->getId() == testPersonalID1);
        BOOST_TEST(client->getIdType() == testIdType1);
        BOOST_TEST(client->getAddressPtr() == testAddress1);
        BOOST_TEST(client->isArchive() == false);
    }

    BOOST_AUTO_TEST_CASE(SetFirstNameTest) {
        BOOST_TEST_REQUIRE(client->getFirstName() == testFirstName1);
        client->setFirstName("");
        BOOST_TEST(client->getFirstName() == testFirstName1);
        client->setFirstName(testFirstName2);
        BOOST_TEST(client->getFirstName() == testFirstName2);
    }

    BOOST_AUTO_TEST_CASE(SetLastNameTest) {
        BOOST_TEST_REQUIRE(client->getLastName() == testLastName1);
        client->setLastName("");
        BOOST_TEST(client->getLastName() == testLastName1);
        client->setLastName(testLastName2);
        BOOST_TEST(client->getLastName() == testLastName2);
    }

    BOOST_AUTO_TEST_CASE(SetAddressTest) {
        BOOST_TEST_REQUIRE(client->getAddressPtr() == testAddress1);
        client->setAddressPtr(nullptr);
        BOOST_TEST(client->getAddressPtr() == testAddress1);
        client->setAddressPtr(testAddress2);
        BOOST_TEST(client->getAddressPtr() == testAddress2);
    }

    BOOST_AUTO_TEST_CASE(SetArchiveTest) {
        BOOST_TEST_REQUIRE(client->isArchive() == false);
        client->setArchive(true);
        BOOST_TEST(client->isArchive() == true);
    }


BOOST_AUTO_TEST_SUITE_END()
