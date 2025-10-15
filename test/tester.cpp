#include <gtest/gtest.h>
#include "../include/point.h"
#include "../include/square.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"
#include "../include/spisok.h"
#include <sstream>

// Тесты для Point
TEST(PointTest, ConstructorAndEquality) {
    Point p1(1.0, 2.0);
    Point p2(1.0, 2.0);
    Point p3(3.0, 4.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PointTest, OutputOperator) {
    Point p(1.5, 2.5);
    std::stringstream ss;
    ss << p;
    
    EXPECT_TRUE(ss.str().find("1.5") != std::string::npos);
    EXPECT_TRUE(ss.str().find("2.5") != std::string::npos);
}

// Тесты для Square
TEST(SquareTest, AreaCalculation) {
    // Квадрат со стороной 2
    Square square;
    std::stringstream input("0 0 2 0 2 2 0 2");
    input >> square;
    
    EXPECT_NEAR(square.area(), 4.0, 1e-6);
}

TEST(SquareTest, CenterCalculation) {
    Square square;
    std::stringstream input("0 0 2 0 2 2 0 2");
    input >> square;
    
    Point center = square.center();
    EXPECT_NEAR(center.x, 1.0, 1e-6);
    EXPECT_NEAR(center.y, 1.0, 1e-6);
}

TEST(SquareTest, Equality) {
    Square sq1, sq2;
    std::stringstream input1("0 0 2 0 2 2 0 2");
    std::stringstream input2("0 0 2 0 2 2 0 2");
    
    input1 >> sq1;
    input2 >> sq2;
    
    EXPECT_TRUE(sq1 == sq2);
}

// Тесты для Rectangle
TEST(RectangleTest, AreaCalculation) {
    // Прямоугольник 2x3
    Rectangle rect;
    std::stringstream input("0 0 2 0 2 3 0 3");
    input >> rect;
    
    EXPECT_NEAR(rect.area(), 6.0, 1e-6);
}

// Тесты для Trapezoid
TEST(TrapezoidTest, AreaCalculation) {
    // Трапеция с основаниями 4 и 2, высотой 3
    Trapezoid trap;
    std::stringstream input("0 0 4 0 3 3 1 3");
    input >> trap;
    
    // Площадь = (4 + 2) * 3 / 2 = 9
    EXPECT_NEAR(trap.area(), 9.0, 1e-6);
}

// Тесты для Spisok
TEST(SpisokTest, AddAndRemove) {
    Spisok spisok;
    
    Square* square = new Square();
    std::stringstream input("0 0 1 0 1 1 0 1");
    input >> *square;
    
    spisok.addFigure(square);
    EXPECT_EQ(spisok.size(), 1);
    
    spisok.remove(0);
    EXPECT_EQ(spisok.size(), 0);
}

TEST(SpisokTest, TotalArea) {
    Spisok spisok;
    
    // Добавляем квадрат площадью 1
    Square* square = new Square();
    std::stringstream input1("0 0 1 0 1 1 0 1");
    input1 >> *square;
    spisok.addFigure(square);
    
    // Добавляем прямоугольник площадью 2
    Rectangle* rect = new Rectangle();
    std::stringstream input2("0 0 2 0 2 1 0 1");
    input2 >> *rect;
    spisok.addFigure(rect);
    
    EXPECT_NEAR(spisok.allArea(), 3.0, 1e-6);
}

TEST(SpisokTest, CopyConstructor) {
    Spisok spisok1;
    
    Square* square = new Square();
    std::stringstream input("0 0 1 0 1 1 0 1");
    input >> *square;
    spisok1.addFigure(square);
    
    Spisok spisok2(spisok1); // Копирование
    EXPECT_EQ(spisok2.size(), 1);
}

// Тест ввода/вывода
TEST(IOTest, SquareInputOutput) {
    Square square;
    std::stringstream input("0 0 1 0 1 1 0 1");
    std::stringstream output;
    
    input >> square;
    output << square;
    
    // Проверяем что вывод содержит координаты
    EXPECT_TRUE(output.str().find("0") != std::string::npos);
    EXPECT_TRUE(output.str().find("1") != std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}