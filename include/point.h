#ifndef POINT_H
#define POINT_H

// Класс-точка.

#include <iostream>

class Point {
    public:
    
        double x, y;

        Point() = default;
        Point(double x, double y);

        bool operator==(const Point& otherPoint) const;

        friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

#endif