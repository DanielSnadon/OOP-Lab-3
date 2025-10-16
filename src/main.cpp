#include <iostream>
#include "spisok.h"
#include "square.h"

int main() {
    std::cout << "Тестируем Spisok..." << std::endl;
    
    Spisok spisok(5);
    
    Square* square = new Square();
    std::cout << "Введите 4 точки квадрата: ";
    std::cin >> *square;
    
    spisok.addFigure(square);

    Rectangle* rect = new Rectangle();
    std::cout << "Введите 4 точки прямоугольника: ";
    std::cin >> *rect;
    
    spisok.addFigure(rect);

    Trapezoid* trap = new Trapezoid();
    std::cout << "Введите 4 точки трапеции: ";
    std::cin >> *trap;
    
    spisok.addFigure(trap);
    
    spisok.allPrint();
    std::cout << "Общая площадь: " << spisok.allArea() << std::endl;
    
    spisok.remove(2);

    spisok.allPrint();
    std::cout << "Общая площадь: " << spisok.allArea() << std::endl;

    return 0;
}