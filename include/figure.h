#ifndef FIGURE_H
#define FIGURE_H

// Родительский-Класс-Фигура

#include "point.h"

class Figure {
    public:
        ~Figure();

        virtual double area() const = 0;
        explicit operator double() const {
            return area();
        }

        unsigned int getAmountOfPoints() const;
        Point* getPoints() const;

        Point center() const;

        virtual bool operator==(const Figure& otherFig) const = 0;
        Figure& operator=(const Figure& otherFig);
        Figure& operator=(Figure &&otherFig);
        
        virtual void print(std::ostream& os) const = 0;
        virtual void read(std::istream& is) = 0;

        friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
        friend std::istream& operator>>(std::istream& is, Figure& fig);

    protected:
        unsigned int amountOfPoints;
        Point* points;
};

#endif