//
// Created by artig on 25.01.2019.
//

#ifndef DESIGNPATTERNS_PERSONFACTORY_H
#define DESIGNPATTERNS_PERSONFACTORY_H

#include <iostream>
#include <math.h>
using namespace std;

enum class PointType{
    cartesian,
    polar
};

class Point{
    Point(float x, float y) : x(x), y(y) {}
    float x,y;
    class PointFactory{ // inner factory
    public:
        static Point NewCartesian(float x, float y){
            return {x,y};
        }

        static Point NewPolar(float r, float theta){
            return {r*cos(theta), r*sin(theta)};
        }
    };
public:
    friend ostream &operator<<(ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
    static PointFactory factory;


};

/*struct PointFactory{ // factory
    static Point NewCartesian(float x, float y){
        return {x,y};
    }

    static Point NewPolar(float r, float theta){
        return {r*cos(theta), r*sin(theta)};
    }
};*/


//-------------------------------------------------- From book
// Button interface
struct Button { 
    virtual void render() = 0;
    virtual void onClick() = 0;
};

class WinButton : public Button {
public:
    void render() {
        cout << "Render windows button" << endl;
    }

    void onClick() {
        cout << "Click windows button" << endl;
    }
};

class LinuxButton : public Button {

public:
    void render() {
        cout << "Render linux button" << endl;
    }

    void onClick() {
        cout << "Click linux button" << endl;
    }
};

class HtmlButton : public Button {
public:
    void render() {
        cout << "Render html button" << endl;
    }

    void onClick() {
        cout << "Click html button" << endl;
    }
};

class Dialog {
protected:
    string m_title;
public:
    virtual void renderWindow(string title) {
        cout << "Initialize rendering..." << endl;
    };
    virtual Button* createButton() = 0;

    string get_title() {
        return m_title;
    }
};

class WinDialog : public Dialog {
    virtual void renderWindow(string title) {
        Dialog::renderWindow(title);
        cout << "Render Windows window" << endl;
        m_title = title + ".Win";
    }
    virtual Button* createButton() {
        cout << "Create Windows button" << endl;
        return new WinButton();
    }
};

class LinuxDialog : public Dialog {
    virtual void renderWindow(string title) {
        Dialog::renderWindow(title);
        cout << "Render Linux window" << endl;
        m_title = title + ".Linux";
    }
    virtual Button* createButton() {
        cout << "Create Linux button" << endl;
        return new LinuxButton();
    }
};

class HtmlDialog : public Dialog {
    virtual void renderWindow(string title) {
        Dialog::renderWindow(title);
        cout << "Render html window" << endl;
        m_title = title + ".Html";
    }
    virtual Button* createButton() {
        cout << "Create html button" << endl;
        return new HtmlButton();
    }
};

#endif //DESIGNPATTERNS_PERSONFACTORY_H
