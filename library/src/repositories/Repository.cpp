//
// Created by student on 31.05.2021.
//

#include "repositories/Repository.h"

using namespace std;

template<class T>
std::vector<T> Repository<T>::findAll() {
    Predicate<T> all;
    all.func = [](T ptr) {
        return true;
    };
    return findBy(all);
}

template<class T>
unsigned int Repository<T>::size() const {
    return repository.size();
}

template<class T>
std::string Repository<T>::report() const {
    std::string ret("Informacje o repozytorium:\n");
    for(int i = 0; i < repository.size(); i++) {
        ret += repository[i]->getInfo() + '\n';
    }
    return ret;
}

template<class T>
void Repository<T>::remove(T ptr) {
    if(ptr != nullptr) {
        for(int i = 0; i < repository.size(); i++) {
            if(repository[i] == ptr) {
                repository.erase(repository.begin() + i);
            }
        }
    }
}

template<class T>
void Repository<T>::add(T ptr) {
    if(ptr != nullptr) {
        repository.push_back(ptr);
    }
}

template<class T>
T Repository<T>::get(const unsigned int & id) const {
    if (id < repository.size()) {
        return repository[id];
    } else {
        return nullptr;
    }
}

template<typename T>
std::vector<T> Repository<T>::findBy(Predicate<T> predicate) {
    vector<T> found;
    for (unsigned int i = 0; i < repository.size(); i++) {
        T ptr = get(i);
        if (predicate.func(ptr)) {
            found.push_back(ptr);
        }
    }
    return found;
}
