//
// Created by artig on 26.01.2019.
//

#ifndef DESIGNPATTERNS_BRIDGE_H
#define DESIGNPATTERNS_BRIDGE_H

#include <iostream>

using namespace std;

struct Renderer {
    virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRenderer : Renderer {
    void render_circle(float x, float y, float radius) override {
        cout << "Rasterizing a circle of radius " << radius << endl;
    }
};

struct RasterRenderer : Renderer {
    void render_circle(float x, float y, float radius) override {
        cout << "Drawing a vector circle of radius " << radius << endl;
    }
};

struct Shape {
protected:
    Renderer &renderer;

    Shape(Renderer &renderer) : renderer(renderer) {}

public:
    virtual void draw() = 0;

    virtual void resize(float factor) = 0;
};

struct Circle : public Shape {
    float x, y, radius;

    Circle(Renderer &renderer, float x, float y, float radius) : Shape(renderer), x(x), y(y), radius(radius) {}

    void draw() override {
        renderer.render_circle(x, y, radius);
    }

    void resize(float factor) override {
        radius *= factor;
    }
};

#endif //DESIGNPATTERNS_BRIDGE_H
