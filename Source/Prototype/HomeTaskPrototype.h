//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_HOMETASK_PROTOTYPE_H
#define DESIGNPATTERNS_HOMETASK_PROTOTYPE_H

#include <iostream>
using namespace std;
struct PointFromTask
{
    int x{ 0 }, y{ 0 };

    PointFromTask(){}

    PointFromTask(const int x, const int y) : x{x}, y{y} {}

    friend ostream &operator<<(ostream &os, const PointFromTask &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

struct Line
{
    PointFromTask *start, *end;

    Line(PointFromTask* const start, PointFromTask* const end)
            : start(start), end(end)
    {
    }

    ~Line()
    {
        delete start;
        delete end;
    }

    Line deep_copy() const
    {
        // TODO
        Line result{new PointFromTask{start->x, start->y}, new PointFromTask{end->x, end->y}};
        return result;
    }

    friend ostream &operator<<(ostream &os, const Line &line) {
        os << "start: " << *line.start << " end: " << *line.end;
        return os;
    }
};

#endif //DESIGNPATTERNS_HOMETASK_PROTOTYPE_H
