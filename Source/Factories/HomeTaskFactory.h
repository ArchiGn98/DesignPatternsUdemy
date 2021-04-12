//
// Created by artig on 24.01.2019.
//

#ifndef DESIGNPATTERNS_HOMETASKFACTORY_H
#define DESIGNPATTERNS_HOMETASKFACTORY_H

#include <string>
#include <ostream>

using namespace std;

struct Man
{
    int id;
    string name;

    Man(int id, const string &name) : id(id), name(name) {}

    friend ostream &operator<<(ostream &os, const Man &person) {
        os << "id: " << person.id << " name: " << person.name;
        return os;
    }
};

class ManFactory
{
public:
    static int id;
    Man create_person(const string& name)
    {
        return {id++, name};
    }

};

int ManFactory::id = 0;

#endif //DESIGNPATTERNS_HOMETASKFACTORY_H
