//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_SINGLETON_H
#define DESIGNPATTERNS_SINGLETON_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Database {
public:
    virtual int get_population(const string &city) = 0;
};

class SingletonDatabase : public Database {
    SingletonDatabase() {
        cout << "Initializing database" << endl;
        ifstream ifs("capitals.txt");
        string s, s2;
        while (getline(ifs, s)) {
            getline(ifs, s2);
            int pop = stoi(s2);
            capitals[s] = pop;
        }
    }

    map<string, int> capitals;
public:
    SingletonDatabase(SingletonDatabase const &) = delete;

    void operator=(SingletonDatabase const &) = delete;

    static SingletonDatabase &get() {
        static SingletonDatabase db;
        return db;
    }

    int get_population(const string &city) override {
        return capitals[city];
    }
};

class DummyDatabase : public Database {
    map<string, int> capitals;
public:
    DummyDatabase() {
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
        capitals["gamma"] = 3;
    }

    int get_population(const string &name) override {
        return capitals[name];
    }
};

struct SingletonRecordFinder {
    int total_population(vector<string> &names) {
        int result{0};
        for (const auto &name : names)
            result += SingletonDatabase::get().get_population(name);
        return result;
    }
};

struct ConfigurableRecordFinder {
    Database &db;

    ConfigurableRecordFinder(Database &db) : db(db) {}

    int total_population(const vector<string> &names) {
        int result{0};
        for (const auto &name : names)
            result += db.get_population(name);
        return result;
    }
};

#endif //DESIGNPATTERNS_SINGLETON_H
