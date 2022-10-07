//
// Created by student on 31.05.2021.
//

#include "managers/ClientManager.h"

using namespace std;

ClientPtr ClientManager::registerClient(const std::string &firstName, const std::string &lastName, const std::string &id,
                              IDType idType, const AddressPtr &address) try {
    if(getClient(id, idType) == nullptr) {
        ClientPtr ret = make_shared<Client>(firstName, lastName, id, idType, address);
        repository.add(ret);
        return ret;
    } else {
        return getClient(id, idType);
    }
}
catch(const ClientException &exception) {
    throw exception;
}

void ClientManager::unregisterClient(ClientPtr client) {
    ClientPredicate f;
    f.func = [client](ClientPtr ptr) {
        return ptr == client;
    };
    if(!repository.findBy(f).empty())
        repository.findBy(f)[0]->setArchive(true);
}

ClientPtr ClientManager::getClient(std::string id, IDType idtype) {
    ClientPredicate getByID;
    getByID.func = [id, idtype](ClientPtr ptr) {
        return (ptr->getIdType() == idtype) && (ptr->getId() == id);
    };
    if(repository.findBy(getByID).empty()) {
        return nullptr;
    } else {
        return repository.findBy(getByID)[0];
    }
}

std::vector<ClientPtr> ClientManager::findClients(ClientPredicate predicate) {
    ClientPredicate f;
    f.func = [predicate](ClientPtr ptr) {
        return (predicate.func(ptr) && !ptr->isArchive());
    };
    return repository.findBy(f);
}

std::vector<ClientPtr> ClientManager::getAllClients() {
    ClientPredicate f;
    f.func = [](ClientPtr ptr) {
        return !ptr->isArchive();
    };
    return repository.findBy(f);
}
