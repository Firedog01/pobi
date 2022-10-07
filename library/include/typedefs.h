

#ifndef PROJECT_TYPEDEFS_H
#define PROJECT_TYPEDEFS_H

#include <memory>
#include <string>
#include <functional>

class Address;
class Client;
class Rent;
class Equipment;
class LogicContainer;

typedef std::shared_ptr<Address>    AddressPtr;
typedef std::shared_ptr<Client>     ClientPtr;
typedef std::shared_ptr<Rent>       RentPtr;
typedef std::shared_ptr<Equipment>  EquipmentPtr;
typedef std::shared_ptr<std::string>StringPtr;

template<typename T>
struct Predicate {                           //ponieważ nie można utwożyć predykatu który jest templatem to jest obejście
    std::function<bool(T)> func;
};
//sposób korzystania:
/* tworzenie klasy predykatu Rent:
 *      Predicate<RentPtr> RentPredicate;
 * definiowanie predykatu zwracającego wszystkie elementy
 *      RentPredicate pred;
 *      pred.func = [](RentPtr ptr) {
 *          return true;
 *      };
 *      repository.findBy(pred);    <-istotne jest, żeby przekazać cały obiekt zamiast samej funkcji
 */

typedef Predicate<RentPtr> RentPredicate;
typedef Predicate<EquipmentPtr> EquipmentPredicate;
typedef Predicate<ClientPtr> ClientPredicate;

typedef std::shared_ptr<LogicContainer>     LogicContainerPtr;

typedef std::logic_error ClientException;
typedef std::logic_error RentException;
typedef std::logic_error EquipmentException;

#endif //PROJECT_TYPEDEFS_H