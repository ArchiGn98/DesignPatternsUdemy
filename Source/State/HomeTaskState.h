//
// Created by artig on 26.01.2019.
//

#ifndef DESIGNPATTERNS_HOMETASKSTATE_H
#define DESIGNPATTERNS_HOMETASKSTATE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

enum class StateComb {
    LOCKED,
    OPEN,
    ERROR
};

inline ostream &operator<<(ostream &os, const StateComb &state) {
    switch (state) {
        case StateComb::LOCKED:
            os << "Locked";
            break;
        case StateComb::OPEN:
            os << "Open";
            break;
        case StateComb::ERROR:
            os << "Error";
            break;
        default:
            break;
    }
    return os;
}

class CombinationLock {
    vector<int> combination;
    StateComb currentState;
public:
    string status;

    explicit CombinationLock(const vector<int> &combination) : combination(combination) {
        status = "";
        currentState = StateComb::LOCKED;
    }

    void close() {
        currentState = StateComb::LOCKED;
        status = "";
        cout << "Lock is closed..." << endl;
    }

    void enter_digit(int digit) {
        // TODO
        if (status.length() <= combination.size()) {
            status += to_string(digit);
            if (status.length() == combination.size()) {
                string real_comb{};
                for (const auto d : combination) {
                    real_comb += to_string(d);
                }
                if (status == real_comb) {
                    currentState = StateComb::OPEN;
                } else {
                    currentState = StateComb::ERROR;
                }
            }

        }
        cout << currentState << endl;
    }
};

#endif //DESIGNPATTERNS_HOMETASKSTATE_H
