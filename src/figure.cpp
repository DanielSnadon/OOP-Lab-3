#include "../include/figure.h"

// Родительский-Класс-Фигура

// Конструктор

Figure::Figure(unsigned int pointsAmount) : amountOfPoints(pointsAmount) {
    amountOfPoints = 0;
    points = new Point[amountOfPoints];
}

// Деструктор
Figure::~Figure() {
    delete[] points;
    amountOfPoints = 0;
}

// Center
Point Figure::center() const {
    double cX = 0, cY = 0;
    for (unsigned int i = 0; i < amountOfPoints; i++) {
        cX += points[i].x;
        cY += points[i].y;
    }
    cX /= amountOfPoints;
    cY /= amountOfPoints;
    return Point(cX, cY);
}

// Операция копирования
Figure& Figure::operator=(const Figure& otherFig) {
    if (this != &otherFig) {
        delete[] points;
        amountOfPoints = otherFig.amountOfPoints;
        if (otherFig.points && otherFig.amountOfPoints > 0) {
            points = new Point[amountOfPoints];
            for (unsigned int i = 0; i < amountOfPoints; i++) {
                points[i] = otherFig.points[i];
            }
        }
    }

    return *this;
}

// Операция перемещения
Figure& Figure::operator=(Figure &&otherFig) {
    if (this != &otherFig) {
        delete[] points;

        amountOfPoints = otherFig.amountOfPoints;
        points = otherFig.points;

        otherFig.amountOfPoints = 0;
        otherFig.points = nullptr;
    }
    
    return *this;
}

unsigned int Figure::getAmountOfPoints() const {
    return amountOfPoints;
}

Point* Figure::getPoints() const {
    return points;
}

// << / >>
std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}