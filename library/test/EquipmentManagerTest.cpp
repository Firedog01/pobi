//
// Created by student on 13.06.2021.
//

#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "managers/LogicContainer.h"
#include "typedefs.h"

using namespace std;

struct TestSuiteEquipmentManagerFixture {
    LogicContainerPtr container;
    AddressPtr address;
    TestSuiteEquipmentManagerFixture() {
        container = make_shared<LogicContainer>();
        address = make_shared<Address>("Miasto", "Ulica", "3");
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteEquipmentManager, TestSuiteEquipmentManagerFixture)

    BOOST_AUTO_TEST_CASE(GetEquipmentTest) {
        BOOST_TEST(container->getEqMan().getEquipment(2)->getName() == "kjfh");
    }

    BOOST_AUTO_TEST_CASE(RegisterUnregisterCameraTest) {
        BOOST_TEST_REQUIRE(container->getEqMan().getAllEquipment().size() == 2);
        EquipmentPtr newEq = container->getEqMan().registerCamera(120.0, 20.0, 2000.0, "AA", "res");
        BOOST_TEST(container->getEqMan().getEquipment(3)->getFirstDayCost() == 120.0);
        newEq->setArchive(false);
        BOOST_TEST(container->getEqMan().getAllEquipment().size() == 3);
        container->getEqMan().unregisterEquipment(newEq);
        BOOST_TEST(container->getEqMan().getAllEquipment().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RegisterUnregisterLensTest) {
        BOOST_TEST_REQUIRE(container->getEqMan().getAllEquipment().size() == 2);
        EquipmentPtr newEq = container->getEqMan().registerLens(120.0, 20.0, 2000.0, "AA", "focalLength");
        BOOST_TEST(container->getEqMan().getEquipment(3)->getFirstDayCost() == 120.0);
        newEq->setArchive(false);
        BOOST_TEST(container->getEqMan().getAllEquipment().size() == 3);
        container->getEqMan().unregisterEquipment(newEq);
        BOOST_TEST(container->getEqMan().getAllEquipment().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RegisterUnregisterLightingTest) {
        BOOST_TEST_REQUIRE(container->getEqMan().getAllEquipment().size() == 2);
        EquipmentPtr newEq = container->getEqMan().registerLighting(120.0, 20.0, 2000.0, "AA", "brightness");
        BOOST_TEST(container->getEqMan().getEquipment(3)->getFirstDayCost() == 120.0);
        newEq->setArchive(false);
        BOOST_TEST(container->getEqMan().getAllEquipment().size() == 3);
        container->getEqMan().unregisterEquipment(newEq);
        BOOST_TEST(container->getEqMan().getAllEquipment().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RegisterUnregisterMicrophoneTest) {
        BOOST_TEST_REQUIRE(container->getEqMan().getAllEquipment().size() == 2);
        EquipmentPtr newEq = container->getEqMan().registerMicrophone(120.0, 20.0, 2000.0, "AA", "sensitivity");
        BOOST_TEST(container->getEqMan().getEquipment(3)->getFirstDayCost() == 120.0);
        newEq->setArchive(false);
        BOOST_TEST(container->getEqMan().getAllEquipment().size() == 3);
        container->getEqMan().unregisterEquipment(newEq);
        BOOST_TEST(container->getEqMan().getAllEquipment().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RegisterUnregisterTrivetTest) {
        BOOST_TEST_REQUIRE(container->getEqMan().getAllEquipment().size() == 2);
        EquipmentPtr newEq = container->getEqMan().registerTrivet(120.0, 20.0, 2000.0, "AA", 10.0);
        BOOST_TEST(container->getEqMan().getEquipment(3)->getFirstDayCost() == 120.0);
        newEq->setArchive(false);
        BOOST_TEST(container->getEqMan().getAllEquipment().size() == 3);
        container->getEqMan().unregisterEquipment(newEq);
        BOOST_TEST(container->getEqMan().getAllEquipment().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(FindEquipmentTest) {
        EquipmentPredicate f;
        f.func = [](EquipmentPtr ptr) {
            return ptr->getBail() == 2000.0;
        };
        BOOST_TEST(container->getEqMan().findEquipment(f).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(GetAllEquipmentTest) {
        BOOST_TEST(container->getEqMan().getAllEquipment().size() == 2);
    }

BOOST_AUTO_TEST_SUITE_END()