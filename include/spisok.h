#ifndef SPISOK_H
#define SPISOK_H

// Класс-Список.

#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

class Spisok {
    public:
        Spisok();
        ~Spisok();

        double allArea() const;
        void allPrint() const;

        void remove(unsigned int index);

    private:
        unsigned int amountOfFigures;
        unsigned int maxAmount;
        Figure** figures;
};

#endif