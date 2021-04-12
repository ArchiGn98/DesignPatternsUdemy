//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_DEPENDENCYINVERSION_H
#define DESIGNPATTERNS_DEPENDENCYINVERSION_H

#include <string>
#include <vector>
#include <iostream>
#include <tuple>
using namespace std;

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Human
{
    string name;
};

struct RelationshipBrowser
{
    virtual vector<Human> find_all_children_of(const string &name) = 0;
};

// low-level
struct Relationships : RelationshipBrowser
{ 
    vector<tuple<Human, Relationship, Human>> relations;

    void add_parent_and_child(const Human &parent, const Human &child)
    {
        relations.push_back(tuple<Human, Relationship, Human>{child, Relationship::child, parent});
        relations.push_back(tuple<Human, Relationship, Human>{parent, Relationship::parent, child});
    }
    vector<Human> find_all_children_of(const string &name) override
    {
        vector<Human> result;
        for(auto& tuple : relations)
        {
            if(get<0>(tuple).name == name && get<1>(tuple) == Relationship::parent)
            {
                result.push_back(get<2>(tuple));
            }
        }
        return result;
    }
};

// high-level
struct Research
{ 
    RelationshipBrowser& browser;

    Research(RelationshipBrowser& browser) : browser{ browser } { }

    std::vector<std::string> MakeResearch(Human& human)
    {
        std::vector<std::string> outResult;
        for (auto child : browser.find_all_children_of(human.name))
        {
            outResult.push_back(child.name);
        }
        return outResult;
    }
};

#endif //DESIGNPATTERNS_DEPENDENCYINVERSION_H
