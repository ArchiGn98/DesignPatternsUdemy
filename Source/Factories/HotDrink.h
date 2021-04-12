//
// Created by artig on 24.01.2019.
//

#ifndef DESIGNPATTERNS_HOTDRINK_H
#define DESIGNPATTERNS_HOTDRINK_H

#include <iostream>
#include <memory>
using namespace std;

struct HotDrink{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink{
    void prepare(int volume) override {
        cout << "Take tea bag, boil water, pour " << volume
        << "ml, add some lemon" << endl;
    }
};

struct Cofee : HotDrink{
    void prepare(int volume) override {
        cout << "Grind some beans, boil water, pour " << volume
        << " ml" << endl;
    }
};

#endif //DESIGNPATTERNS_HOTDRINK_H
