#ifndef SPISOK_H
#define SPISOK_H

// Класс-Список.

#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

class Spisok {
    public:
        Spisok(unsigned int spisokSize = 10);
        ~Spisok();


        double allArea() const;
        void allPrint() const;

        void addFigure(Figure* fig);
        void remove(unsigned int index);

        unsigned int getSize() const;
        unsigned int getMaxSize() const;
    private:
        unsigned int amountOfFigures;
        unsigned int maxAmount;
        Figure** figures;
};

#endif