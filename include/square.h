#ifndef SQUARE_H
#define SQUARE_H

// Дочерний-Класс-Квадрат.

#include "figure.h"
#include "point.h"

class Square : public Figure {
    public:
        Square();
        
        double area() const override;

        bool operator==(const Figure& otherFig) const override;

        void print(std::ostream& os) const override;
        void read(std::istream& is) override;
};

#endif