#include "../include/spisok.h"

// Класс-Список.
Spisok::Spisok() : maxAmount(amountOfFigures), amountOfFigures(0) {
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
        delete figures[index];
        
        for (unsigned int i = index; i < amountOfFigures - 1; i++) {
            figures[i] = figures[i + 1];
        }
        
        figures[--amountOfFigures] = nullptr;
    }
}

void Spisok::allPrint() const {
    std::cout << "----------Фигуры----------" << std::endl;
    for (unsigned int i = 0; i < amountOfFigures; i++) {
        std::cout << "Фигура " << i << std::endl;
        
        Point center = figures[i]->center();
        std::cout << "  Центр: (" << center.x << ", " << center.y << ")" << std::endl;
        
        double area = figures[i]->area();
        std::cout << "  Площадь: " << area << std::endl;
        
        std::cout << "--------------------------" << std::endl;
    }
}

double Spisok::allArea() const {
    double otv = 0.0;
    for (unsigned int i = 0; i < amountOfFigures; i++) {
        otv += figures[i]->area();
    }
    return otv;
}