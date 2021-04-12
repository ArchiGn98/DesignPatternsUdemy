//
// Created by artig on 26.01.2019.
//

#ifndef DESIGNPATTERNS_PERSONB_H
#define DESIGNPATTERNS_PERSONB_H

#include <string>
#include <iostream>

//Pimple Ideom
/*
 * Hide secret implementation from consumer
 * so that they don't need to recompile their code
 * if you make some changes in deep implementation
 */
class PersonB {
public:
    std::string name;

    class PersonImpl;

    PersonImpl *impl;

    PersonB();

    ~PersonB();

    void greet();
};

class PersonB::PersonImpl {
public:
    void greet(PersonB* p);

private:
    void secret_stuff();
};

void PersonB::PersonImpl::greet(PersonB* p) {
    std::cout << "hello my name is " << p->name << std::endl;
    secret_stuff();
}

void PersonB::PersonImpl::secret_stuff() {
    std::cout << "some secret implementation" << std::endl;
}

void PersonB::greet() {
    impl->greet(this);
}

PersonB::~PersonB() {
    delete impl;
}

PersonB::PersonB() : impl{ new PersonImpl } {}


#endif //DESIGNPATTERNS_PERSONB_H
