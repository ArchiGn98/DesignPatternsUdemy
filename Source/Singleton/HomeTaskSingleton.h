//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_HOMETASK_SINGLETON_H
#define DESIGNPATTERNS_HOMETASK_SINGLETON_H

#include <functional>

using namespace std;

struct SingletonTester {
    template<typename T>
    bool is_singleton(function<T * ()> factory) {
        // TODO
        auto temp1 = factory();
        auto temp2 = factory();
        if (temp1 == temp2) {
            return true;
        }
        return false;
    }
};

#endif //DESIGNPATTERNS_HOMETASK_SINGLETON_H
