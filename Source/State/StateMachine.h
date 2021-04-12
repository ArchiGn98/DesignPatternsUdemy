//
// Created by artig on 26.01.2019.
//

#ifndef DESIGNPATTERNS_STATEMACHINE_H
#define DESIGNPATTERNS_STATEMACHINE_H

#include <iostream>

using namespace std;

class LightSwitch;

struct State {

    virtual void on(LightSwitch *lightSwitch) {
        cout << "Light is already on" << endl;
    }

    virtual void off(LightSwitch *lightSwitch) {
        cout << "Light is already off" << endl;
    }
};

struct OffState : State {
    OffState() {
        cout << "Light is turned off" << endl;
    }

    void on(LightSwitch *lightSwitch) override;
};

struct OnState : State {
    OnState() {
        cout << "Light is turned on" << endl;
    }

    void off(LightSwitch *lightSwitch) override;
};

class LightSwitch {
    State *state;
public:
    LightSwitch() {
        state = new OffState();
    }

    void set_state(State *state) {
        this->state = state;
    }

    void on() {
        state->on(this);
    }

    void off() {
        state->off(this);
    }

};


void OffState::on(LightSwitch *lightSwitch) {
    cout << "Switching light on..." << endl;
    lightSwitch->set_state(new OnState());
    delete this;
}

void OnState::off(LightSwitch *lightSwitch) {
    cout << "Switching light off..." << endl;
    lightSwitch->set_state(new OffState());
    delete this;
}

#endif //DESIGNPATTERNS_STATEMACHINE_H
