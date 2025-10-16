#include "../include/spisok.h"

// Класс-Список.
Spisok::Spisok(unsigned int spisokSize) : amountOfFigures(0), maxAmount(spisokSize) {
    figures = new Figure*[maxAmount];
    for (unsigned int i = 0; i < maxAmount; i++) {
        figures[i] = nullptr;
    }
}

Spisok::~Spisok() {
    delete[] figures;
}

void Spisok::remove(unsigned int index) {
    if (index < amountOfFigures) {
        for (unsigned int i = index; i < amountOfFigures - 1; i++) {
            figures[i] = figures[i + 1];
        }
        
        figures[--amountOfFigures] = nullptr;
    }
}

void Spisok::addFigure(Figure* fig) {
    if (amountOfFigures < maxAmount) {
        figures[amountOfFigures++] = fig;
    } else {
        throw std::overflow_error("Массив фигур перполнен!");
    }
}

void Spisok::allPrint() const {
    std::cout << "----------Фигуры----------" << std::endl;
    for (unsigned int i = 0; i < amountOfFigures; i++) {
        std::cout << "Фигура " << i << ": " << *figures[i] << std::endl;
        
        Point center = figures[i]->center();
        std::cout << "Центр: (" << center.x << ", " << center.y << ")" << std::endl;
        
        double area = figures[i]->area();
        std::cout << "Площадь: " << area << std::endl;
        
        std::cout << "--------------------------" << std::endl;
    }
}

double Spisok::allArea() const {
    double otv = 0.0;
    for (unsigned int i = 0; i < amountOfFigures; i++) {
        otv += static_cast<double>(*figures[i]);
    }
    return otv;
}

unsigned int Spisok::getSize() const {
    return amountOfFigures;
}

unsigned int Spisok::getMaxSize() const {
    return maxAmount;
}
