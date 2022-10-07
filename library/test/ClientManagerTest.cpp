//
// Created by student on 13.06.2021.
//

#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "managers/LogicContainer.h"
#include "typedefs.h"

using namespace std;

struct TestSuiteClientManagerFixture {
    LogicContainerPtr container;
    AddressPtr address;
    TestSuiteClientManagerFixture() {
        container = make_shared<LogicContainer>();
        address = make_shared<Address>("Miasto", "Ulica", "3");
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(GetClientTest) {
        BOOST_TEST(container->getClientMan().getClient("4178632", DowodOsobisty)->getFirstName() == "Zbigniew");
    }

    BOOST_AUTO_TEST_CASE(RegisterUnregisterClientTest) {
        BOOST_TEST_REQUIRE(container->getClientMan().getAllClients().size() == 3);
        ClientPtr newClient = container->getClientMan().registerClient("Nowy", "Klient", "21738", Passport, address);
        BOOST_TEST(container->getClientMan().getClient("21738", Passport)->getFirstName() == "Nowy");
        BOOST_TEST(container->getClientMan().getAllClients().size() == 4);
        container->getClientMan().unregisterClient(newClient);
        BOOST_TEST(container->getClientMan().getAllClients().size() == 3);
    }

    BOOST_AUTO_TEST_CASE(FindClientsTest) {
        ClientPredicate f;
        f.func = [](ClientPtr ptr) {
            return ptr->getIdType() == DowodOsobisty;
        };
        BOOST_TEST(container->getClientMan().findClients(f).size() == 3);
        f.func = [](ClientPtr ptr) {
            return ptr->getFirstName() == "Zbigniew";
        };
        BOOST_TEST(container->getClientMan().findClients(f).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(GetAllClientsTest) {
        BOOST_TEST(container->getClientMan().getAllClients().size() == 3);
    }

BOOST_AUTO_TEST_SUITE_END()