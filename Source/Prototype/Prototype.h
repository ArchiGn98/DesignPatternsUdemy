//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_PROTOTYPE_H
#define DESIGNPATTERNS_PROTOTYPE_H

#include <string>
#include <iostream>
#include <memory>
using namespace std;

struct Address{
    string street, city;
    int suite;

    Address(const string &street, const string &city, int suite) : street(street), city(city), suite(suite) {}

    Address(Address &other) : street{other.street}, city{other.city}, suite{other.suite}{}

    friend ostream &operator<<(ostream &os, const Address &address) {
        os << "street: " << address.street << " city: " << address.city << " suite: " << address.suite;
        return os;
    }
};

struct Contact{
    string name;
    Address *address;

    Contact(const string &name, Address *address) : name(name), address(address) {}

    Contact (Contact &other) : name{other.name}, address{new Address{*other.address}}{}

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        os << "name: " << contact.name << " address: " << *contact.address;
        return os;
    }

};

struct EmploeeFactory{

    static unique_ptr<Contact> new_main_office_employee(const string &name, int suite){
        static Contact p{"", new Address{"123 East Dr", "London", 0}};
        return new_employee(name, suite, p);
    }


private:
    static unique_ptr<Contact> new_employee(const string &name, int suite, Contact prototype){
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};

#endif //DESIGNPATTERNS_PROTOTYPE_H
