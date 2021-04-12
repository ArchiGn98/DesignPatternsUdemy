//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_SINGLERESPONSIBILITY_H
#define DESIGNPATTERNS_SINGLERESPONSIBILITY_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// take care about title and entries
class Journal
{
private:
    int EntriesCount;
    string Title;
    vector<string> Entries;
    friend class PersistenceManager;
public:
    Journal(const string & Title) : Title{ Title }, EntriesCount{ 1 }
    {
    }

    void addEntry(const string &Entry)
    {
        Entries.push_back(to_string(EntriesCount++)+": "+ Entry);
    }

    string getTitle() const
    {
        return Title;
    }

    vector<string> getEntries() const
    {
        return Entries;
    }
};

// take care about saving
class PersistenceManager
{
public:
    void save(const Journal &journal, const string &filename)
    {
        ofstream ofs(filename);
        for(const auto &e : journal.Entries){
            ofs << e << endl;
        }
        cout << "saved" << endl;
    }
};

#endif //DESIGNPATTERNS_SINGLERESPONSIBILITY_H
