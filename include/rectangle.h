#ifndef RECTANGLE_H
#define RECTANGLE_H

// Дочерний-Класс-Прямоугольник.

#include "figure.h"
#include "point.h"

class Rectangle : public Figure {
    public:
        double area() const override;

        bool operator==(const Figure& otherFig) const override;

        void print(std::ostream& os) const override;
        void read(std::istream& is) override;
};

#endif