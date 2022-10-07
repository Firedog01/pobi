//
// Created by student on 12.06.2021.
//

#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "model/Camera.h"
#include "model/Lens.h"
#include "model/Lighting.h"
#include "model/Microphone.h"
#include "model/Trivet.h"

using namespace std;

struct TestSuiteEquipmentFixture {
    const unsigned int testid1 = 0;
    const double testFirstDayCost1 = 100.0;
    const double testNextDaysCost1 = 50.0;
    const double testBail1 = 2000.0;
    const string name = "Nazwa1";
    const string descStr = "Bardzo dlugi opis zawierajacy mnostwo szczegolow.";
    StringPtr description;
    shared_ptr<Camera> camera;
    const string resolution = "1920x1080";
    shared_ptr<Lens> lens;
    const string focalLength = "15 - 60 mm";
    shared_ptr<Lighting> lighting;
    const string brightness = "150 W";
    shared_ptr<Microphone> microphone;
    const string sensitivity = "40 Hz - 20 kHz";
    shared_ptr<Trivet> trivet;
    const double weight = 5.5;

    TestSuiteEquipmentFixture() {
        camera      = make_shared<Camera>(testid1, testFirstDayCost1, testNextDaysCost1, testBail1, name, resolution);
        lens        = make_shared<Lens>(testid1, testFirstDayCost1, testNextDaysCost1, testBail1, name, focalLength);
        lighting    = make_shared<Lighting>(testid1, testFirstDayCost1, testNextDaysCost1, testBail1, name, brightness);
        microphone  = make_shared<Microphone>(testid1, testFirstDayCost1, testNextDaysCost1, testBail1, name, sensitivity);
        trivet      = make_shared<Trivet>(testid1, testFirstDayCost1, testNextDaysCost1, testBail1, name, weight);
        description = make_shared<string>(descStr);
    }
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteEquipment, TestSuiteEquipmentFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstructorTest) {
        BOOST_TEST(camera->getId() == testid1);
        BOOST_TEST(camera->getFirstDayCost() == testFirstDayCost1);
        BOOST_TEST(camera->getNextDaysCost() == testNextDaysCost1);
        BOOST_TEST(camera->getBail() == testBail1);
        BOOST_TEST(camera->getName() == name);

        BOOST_TEST(camera->getResolution() == resolution);
        BOOST_TEST(lens->getFocalLength() == focalLength);
        BOOST_TEST(lighting->getBrightness() == brightness);
        BOOST_TEST(microphone->getSensitivity() == sensitivity);
        BOOST_TEST(trivet->getWeight() == weight);

        BOOST_TEST(camera->isArchive() == true);
        BOOST_TEST(camera->isMissing() == false);
        BOOST_TEST(camera->getDescription() == nullptr);
        BOOST_TEST(!camera->getEquipmentInfo().empty());
        BOOST_TEST(!camera->getEquipmentFullInfo().empty());
    }

    BOOST_AUTO_TEST_CASE(SetDescriptionTest) {
        BOOST_TEST_REQUIRE(camera->getDescription() == nullptr);
        camera->setDescription(description);
        BOOST_TEST(camera->getDescription() == description);
        BOOST_TEST(*camera->getDescription() == descStr);
        camera->setDescription(nullptr);
        BOOST_TEST(camera->getDescription() == description);
    }

    BOOST_AUTO_TEST_CASE(SetArchiveTest) {
        BOOST_TEST_REQUIRE(camera->isArchive() == true);
        camera->setArchive(false);
        BOOST_TEST(camera->isArchive() == false);
    }

    BOOST_AUTO_TEST_CASE(SetMissingTest) {
        BOOST_TEST_REQUIRE(camera->isMissing() == false);
        camera->setMissing(true);
        BOOST_TEST(camera->isMissing() == true);
    }


BOOST_AUTO_TEST_SUITE_END()
