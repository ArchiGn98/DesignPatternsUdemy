//
// Created by artig on 26.01.2019.
//

#ifndef DESIGNPATTERNS_HOMETASK_BRIDGE_H
#define DESIGNPATTERNS_HOMETASK_BRIDGE_H

#include <string>

using namespace std;

struct RendererH {
    virtual string what_to_tender_as(string name) = 0;
};


struct PixelRenderer : RendererH {
    string what_to_tender_as(string name) override {
        return "Drawing " + name + " as pixels";
    }
};

struct LineRenderer : RendererH {
    string what_to_tender_as(string name) override {
        return "Drawing " + name + " as lines";
    }
};

struct ShapeH {
    string name;

    virtual void draw() = 0;

protected:
    RendererH &renderer;

    ShapeH(RendererH &renderer) : renderer{renderer} {}

};

struct TriangleH : ShapeH {
    TriangleH(RendererH &renderer) : ShapeH(renderer) {
        name = "Triangle";
    }

    void draw() override {
        cout << renderer.what_to_tender_as(name) << endl;
    }
};

struct SquareH : ShapeH {
    SquareH(RendererH &renderer) : ShapeH(renderer) {
        name = "Square";
    }

    void draw() override {
        cout << renderer.what_to_tender_as(name) << endl;
    }
};

// imagine e.g. VectorTriangle/RasterTriangle etc. here

#endif //DESIGNPATTERNS_HOMETASK_BRIDGE_H
