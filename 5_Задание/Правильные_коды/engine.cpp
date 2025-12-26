// engine.cpp
// Кузнецов Александр
#include "engine.h"
using namespace std;  // Чтобы не писать std:: перед string, cout и т.д.

// Реализация конструктора класса Engine
// Инициализирует поля horsepower и type переданными значениями
Engine::Engine(int hp, const string& t) : horsepower(hp), type(t) {}

// Геттер: возвращает мощность двигателя
int Engine::getHorsepower() const {
    return horsepower;
}

// Сеттер: устанавливает новую мощность
void Engine::setHorsepower(int value) {
    horsepower = value;
}

// Геттер: возвращает тип двигателя
string Engine::getType() const {
    return type;
}

// Сеттер: устанавливает тип двигателя
void Engine::setType(const string& value) {
    type = value;
}