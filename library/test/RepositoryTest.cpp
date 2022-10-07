//
// Created by student on 12.06.2021.
//

//ponieważ każda klasa repozytorium dziedziczy z klasy Repository i nie dodaje innych metod nie ma potrzeby pisać trzech testów dla każdego z tych repozytoriów

#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "repositories/ClientRepository.h"
#include "model/Rent.h"
#include "typedefs.h"

using namespace std;

struct TestSuiteRepositoryFixture {
    AddressPtr address1;
    AddressPtr address2;

    ClientPtr client1;
    ClientPtr client2;
    ClientPtr client3;
    ClientPtr client4;

    ClientRepository repository;

    TestSuiteRepositoryFixture() {
        address1 = make_shared<Address>("Gotham", "Nietoparza", "2");
        address2 = make_shared<Address>("Gotham", "Bananowa", "68");
        client1 = make_shared<Client>("Name", "Surname", "01234", Passport, address1);
        client2 = make_shared<Client>("Name", "Surname", "01234", Passport, address1);
        client3 = make_shared<Client>("Name", "Surname", "01234", DowodOsobisty, address2);
        client4 = make_shared<Client>("Name", "Surname", "01234", Passport, address2);

        repository.add(client1);
        repository.add(client2);
        repository.add(client3);
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepository, TestSuiteRepositoryFixture)

    BOOST_AUTO_TEST_CASE(GetSizeTest) {
        BOOST_TEST(repository.size() == 3);
    }

    BOOST_AUTO_TEST_CASE(GetterPositionTest) {
        BOOST_TEST(repository.get(3) == nullptr);
        repository.add(client4);
        BOOST_TEST(repository.get(3) == client4);
        repository.remove(client4);
    }

    BOOST_AUTO_TEST_CASE(AddingAndRemovingTest) {
        BOOST_TEST_REQUIRE(repository.size() == 3);
        repository.add(nullptr);
        BOOST_TEST(repository.size() == 3);
        repository.add(client4);
        BOOST_TEST(repository.size() == 4);
        BOOST_TEST(repository.get(3) == client4);
        repository.remove(client4);
        BOOST_TEST(repository.size() == 3);
    }

    BOOST_AUTO_TEST_CASE(FindAllTest) {
        BOOST_TEST(repository.findAll().size() == 3);
    }

    BOOST_AUTO_TEST_CASE(FindByTest) {
    BOOST_TEST_REQUIRE(repository.size() == 3);
        ClientPredicate f;
        f.func = [](ClientPtr ptr) {
            return ptr->getIdType() == Passport;
        };
        std::vector<ClientPtr> test = repository.findBy(f);
        BOOST_TEST(test.size() == 2);
        BOOST_TEST(test[0]->getIdType() == Passport);
    }

BOOST_AUTO_TEST_SUITE_END()