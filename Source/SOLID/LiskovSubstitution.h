//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_LISKOVSUBSTITUTION_H
#define DESIGNPATTERNS_LISKOVSUBSTITUTION_H

#include <iostream>
using namespace std;

class Rectangle
{
protected:
    int width, height;
public:
    Rectangle(int width, int height) : width{width}, height{height}{}

    int getHeight() const { return height; }

    virtual void setHeight(int value) { height = value; }

    int getWidth() const { return width; }

    virtual void setWidth(int value) { width = value; }

    inline int area(){ return width*height; }
};

class Square : public Rectangle
{
public:
    Square(int size) : Rectangle(size,size){}

    void setWidth(int value) override { width = height = value; }

    void setHeight(int value) override { width = height = value; }
};

#endif //DESIGNPATTERNS_LISKOVSUBSTITUTION_H
