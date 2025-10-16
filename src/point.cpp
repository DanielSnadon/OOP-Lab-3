#include "../include/point.h"

// Класс-точка.

Point::Point(double x, double y) : x(x), y(y) {}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "Точка [ x: " << p.x << ", y: " << p.y << "]" << std::endl;
    return os;
}

