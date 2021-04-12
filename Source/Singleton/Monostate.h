//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_MONOSTATE_H
#define DESIGNPATTERNS_MONOSTATE_H

// Do not use it, just for showing
class Printer {
    static int id;
public:
    int get_id() const { return id; }

    void set_id(int id) { this->id = id; }
};

int Printer::id = 0;

#endif //DESIGNPATTERNS_MONOSTATE_H
