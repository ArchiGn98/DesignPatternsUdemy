//
// Created by artig on 24.01.2019.
//

#ifndef DESIGNPATTERNS_HOTDRINKFACTORY_H
#define DESIGNPATTERNS_HOTDRINKFACTORY_H

#include "HotDrink.h"


struct HotDrinkFactory{
    virtual unique_ptr<HotDrink> make() = 0;
};

struct TeaFactory : HotDrinkFactory{
    unique_ptr<HotDrink> make() override {
        return make_unique<Tea>();
    }
};

struct CofeeFactory : HotDrinkFactory{
    unique_ptr<HotDrink> make() override {
        return make_unique<Cofee>();
    }
};

#endif //DESIGNPATTERNS_HOTDRINKFACTORY_H
