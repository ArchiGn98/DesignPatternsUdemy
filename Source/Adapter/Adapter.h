//
// Created by artig on 26.01.2019.
//

#ifndef DESIGNPATTERNS_ADAPTER_H
#define DESIGNPATTERNS_ADAPTER_H

struct Square2 {
    int side{0};


    explicit Square2(const int side)
            : side(side) {
    }
};

struct Rectangle2 {
    virtual int width() const = 0;

    virtual int height() const = 0;

    int area() const {
        return width() * height();
    }
};

struct SquareToRectangleAdapter : Rectangle2 {
    SquareToRectangleAdapter(const Square2 &square) {
        // todo
        w = h = square.side;
    }

    // todo
    int w, h;

    int width() const override {
        return this->w;
    }

    int height() const override {
        return this->h;
    }
};


#endif //DESIGNPATTERNS_ADAPTER_H
