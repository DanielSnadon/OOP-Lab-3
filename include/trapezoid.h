#ifndef TRAPEZOID_H
#define TRAPEZOID_H

// Дочерний-Класс-Трапеция.

#include "figure.h"
#include "point.h"

class Trapezoid : public Figure {
    public:
        double area() const override;

        bool operator==(const Figure& otherFig) const override;

        void print(std::ostream& os) const override;
        void read(std::istream& is) override;
};

#endif