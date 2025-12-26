// driver.cpp
// Кузнецов Александр
#include "driver.h"
using namespace std;

// Конструктор: сохраняет имя водителя
Driver::Driver(const string& n) : name(n) {}

// Геттер: возвращает имя
string Driver::getName() const {
    return name;
}

// Сеттер: устанавливает имя
void Driver::setName(const string& value) {
    name = value;
}