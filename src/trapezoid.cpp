#include "../include/trapezoid.h"
#include <cmath>

// Дочерний-Класс-Трапеция.

// Конструктор

Trapezoid::Trapezoid() {
    amountOfPoints = 4;
    points = new Point[4]();
}

// Area
double Trapezoid::area() const {
    double a = std::sqrt(std::pow((points[1].x - points[0].x), 2)
     + std::pow((points[1].y - points[0].y), 2));
    double b = std::sqrt(std::pow((points[2].x - points[3].x), 2)
     + std::pow((points[2].y - points[3].y), 2));

    double h = std::abs(points[0].y - points[2].y);
    
    return (a + b) * h / 2.0;
}

// Операция сравнения
bool Trapezoid::operator==(const Figure& otherFig) const {
    if (otherFig.getAmountOfPoints() != amountOfPoints) {
        return false;
    }

    Point* oP = otherFig.getPoints();

    double a = std::sqrt(std::pow((points[1].x - points[0].x), 2)
     + std::pow((points[1].y - points[0].y), 2));
    double b = std::sqrt(std::pow((points[2].x - points[1].x), 2)
     + std::pow((points[2].y - points[1].y), 2));

    double h = std::abs(points[0].y - points[2].y);

    double oa = std::sqrt(std::pow((oP[1].x - oP[0].x), 2)
     + std::pow((oP[1].y - oP[0].y), 2));
     double ob = std::sqrt(std::pow((oP[2].x - oP[1].x), 2)
     + std::pow((oP[2].y - oP[1].y), 2));
    
    double oh = std::abs(points[0].y - points[2].y);

    return (area() == otherFig.area()) && (a == oa) && (b == ob) && (h == oh);
}

// Print/Read
void Trapezoid::print(std::ostream& os) const {
    os << "Трапеция [";
    for (unsigned int i = 0; i < 4; i++) {
        os << " (" << points[i].x << ", " << points[i].y << ")";
    }
    os << " ]";
}

void Trapezoid::read(std::istream& is) {
    delete[] points;

    amountOfPoints = 4;
    points = new Point[4];

    for (unsigned int i = 0; i < amountOfPoints; i++) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Неверный ввод для трапеции");
        }
        points[i] = Point(x, y);
    }
}