//
// Created by artig on 26.01.2019.
//

#ifndef DESIGNPATTERNS_HANDMADESTATEMACHINE_H
#define DESIGNPATTERNS_HANDMADESTATEMACHINE_H

#include <iostream>

using namespace std;

enum class StatePhone {
    off_hook,
    connected,
    connecting,
    on_hold,
    on_hook
};

inline ostream &operator<<(ostream &os, const StatePhone &state) {
    switch (state) {
        case StatePhone::off_hook:
            os << "off the hook";
            break;
        case StatePhone::connecting:
            os << "connecting";
            break;
        case StatePhone::connected:
            os << "connected";
            break;
        case StatePhone::on_hold:
            os << "on hold";
            break;
        case StatePhone::on_hook:
            os << "on the hook";
            break;
        default:
            break;
    }
    return os;
}

enum class Trigger {
    call_dialed,
    hung_up,
    call_connected,
    placed_on_hold,
    taken_off_hold,
    left_message,
    stop_using_phone
};

inline ostream &operator<<(ostream &os, const Trigger &t) {
    switch (t) {
        case Trigger::call_dialed:
            os << "call dialed";
            break;
        case Trigger::hung_up:
            os << "hung up";
            break;
        case Trigger::call_connected:
            os << "call connected";
            break;
        case Trigger::placed_on_hold:
            os << "placed on hold";
            break;
        case Trigger::taken_off_hold:
            os << "taken off hold";
            break;
        case Trigger::left_message:
            os << "left message";
            break;
        case Trigger::stop_using_phone:
            os << "putting phone on hook";
            break;
        default:
            break;
    }
    return os;
}

#endif //DESIGNPATTERNS_HANDMADESTATEMACHINE_H
