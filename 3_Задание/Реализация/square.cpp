// square.cpp
// Автор: Кузнецов Александр

// Реализация методов класса Square

#include "square.hpp"
#include <iomanip>   // для управления точностью вывода

using namespace std;

// Проверка: сторона должна быть строго больше нуля
// Если условие нарушено — выбрасывается исключение
void Square::validateSide(double s) const {
    if (s <= 0.0) {
        // Это ошибка использования: нельзя создать квадрат с нулевой или отрицательной стороной
        throw invalid_argument("Сторона квадрата должна быть положительной");
    }
}

// Конструктор: инициализирует поля квадрата
// Сначала проверяется сторона, потом сохраняются все значения
Square::Square(double side, double x, double y) {
    validateSide(side);  // если сторона плохая — программа вылетит здесь
    this->side = side;
    this->x = x;
    this->y = y;
}

// Изменение стороны: сначала проверка, потом присваивание
void Square::setSide(double side_new) {
    validateSide(side_new);
    side = side_new;
}

// Перемещение центра квадрата в новую точку
void Square::move(double new_x, double new_y) {
    x = new_x;
    y = new_y;
}

// Площадь квадрата = сторона * сторона
double Square::area() const {
    return side * side;
}

// Периметр квадрата = 4 * сторона
double Square::perimeter() const {
    return 4.0 * side;
}

// Сравнение двух квадратов
// Из-за особенностей double чисел нельзя сравнивать через ==
// Вместо этого сравниваем с малой погрешностью (EPS = 1e-9)
bool Square::operator==(const Square& other) const {
    const double EPS = 1e-9;
    return abs(side - other.side) < EPS &&
           abs(x - other.x) < EPS &&
           abs(y - other.y) < EPS;
}

// Оператор "не равно" — просто отрицание "равно"
bool Square::operator!=(const Square& other) const {
    return !(*this == other);
}

// Преобразует объект в строку: например, "2.5 1 -1"
string Square::toString() const {
    return to_string(side) + " " + to_string(x) + " " + to_string(y);
}

// Оператор вывода в поток (например, в cout или файл)
// Используем setprecision(17), чтобы сохранить все цифры double без потерь
ostream& operator<<(ostream& os, const Square& sq) {
    os << setprecision(17) << sq.getSide() << " "
       << setprecision(17) << sq.getX() << " "
       << setprecision(17) << sq.getY();
    return os;
}