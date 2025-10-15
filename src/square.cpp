#include "../include/square.h"
#include <cmath>

// Дочерний-Класс-Квадрат.

// Area
double Square::area() const {
    double a = std::sqrt(std::pow((points[1].x - points[0].x), 2)
     + std::pow((points[1].y - points[0].y), 2));
    return a * a;
}

// Операция сравнения
bool Square::operator==(const Figure& otherFig) const {
    if (otherFig.getAmountOfPoints() != amountOfPoints) {
        return false;
    }

    Point* oP = otherFig.getPoints();

    double ta = std::sqrt(std::pow((points[1].x - points[0].x), 2)
     + std::pow((points[1].y - points[0].y), 2));

     double oa = std::sqrt(std::pow((oP[1].x - oP[0].x), 2)
     + std::pow((oP[1].y - oP[0].y), 2));

    return (area() == otherFig.area() && ta - oa < 1e-12);
}

// Print/Read
void Square::print(std::ostream& os) const {
    os << "Квадрат [";
    for (unsigned int i = 0; i < 4; i++) {
        os << " (" << points[i].x << ", " << points[i].y << ")";
    }
    os << " ]";
}

void Square::read(std::istream& is) {
    delete[] points;

    amountOfPoints = 4;
    points = new Point[4];

    for (unsigned int i = 0; i < amountOfPoints; i++) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Неверный ввод для квадрата");
        }
        points[i] = Point(x, y);
    }
}