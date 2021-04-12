//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_SINGLETONDI_H
#define DESIGNPATTERNS_SINGLETONDI_H


#include <string>
#include <memory>

using namespace std;

struct IFoo {
    virtual string name() = 0;
};

struct Foo : IFoo {
    static int id;

    Foo() { ++id; }

    string name() override {
        return "foo"s + to_string(id);
    }
};

int Foo::id = 0;

struct Bar {
    shared_ptr<IFoo> foo;
};


#endif //DESIGNPATTERNS_SINGLETONDI_H
