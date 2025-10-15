#include "../include/rectangle.h"
#include <cmath>

// Дочерний-Класс-Прямоугольник.

// Area
double Rectangle::area() const {
    double a = std::sqrt(std::pow((points[1].x - points[0].x), 2)
     + std::pow((points[1].y - points[0].y), 2));
    double b = std::sqrt(std::pow((points[2].x - points[1].x), 2)
     + std::pow((points[2].y - points[1].y), 2));

    return a * b;
}

// Операция сравнения
bool Rectangle::operator==(const Figure& otherFig) const {
    if (otherFig.getAmountOfPoints() != amountOfPoints) {
        return false;
    }
    Point* oP = otherFig.getPoints();

    double a = std::sqrt(std::pow((points[1].x - points[0].x), 2)
     + std::pow((points[1].y - points[0].y), 2));
    double b = std::sqrt(std::pow((points[2].x - points[1].x), 2)
     + std::pow((points[2].y - points[1].y), 2));

    double oa = std::sqrt(std::pow((oP[1].x - oP[0].x), 2)
     + std::pow((oP[1].y - oP[0].y), 2));
     double ob = std::sqrt(std::pow((oP[2].x - oP[1].x), 2)
     + std::pow((oP[2].y - oP[1].y), 2));

    return (area() == otherFig.area()) && (oa + ob == a + b);
}

// Print/Read
void Rectangle::print(std::ostream& os) const {
    os << "Прямоугольник [";
    for (unsigned int i = 0; i < 4; i++) {
        os << " (" << points[i].x << ", " << points[i].y << ")";
    }
    os << " ]";
}

void Rectangle::read(std::istream& is) {
    delete[] points;

    amountOfPoints = 4;
    points = new Point[4];

    for (unsigned int i = 0; i < amountOfPoints; i++) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Неверный ввод для прямоугольника");
        }
        points[i] = Point(x, y);
    }
}