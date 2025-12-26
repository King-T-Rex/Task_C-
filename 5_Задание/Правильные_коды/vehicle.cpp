// vehicle.h
// Кузнецов Александр
#include "vehicle.h"
using namespace std;

// Конструктор: инициализирует марку и двигатель, водитель — nullptr
Vehicle::Vehicle(const string& b, const Engine& e) : brand(b), engine(e), driver(nullptr) {}

// Геттер марки
string Vehicle::getBrand() const {
    return brand;
}

// Сеттер марки
void Vehicle::setBrand(const string& value) {
    brand = value;
}

// Геттер водителя
Driver* Vehicle::getDriver() const {
    return driver;
}

// Сеттер водителя (принимает указатель на существующий объект)
void Vehicle::setDriver(Driver* d) {
    driver = d;
}

// Геттер двигателя (возвращает копию)
Engine Vehicle::getEngine() const {
    return engine;
}

// Сеттер двигателя
void Vehicle::setEngine(const Engine& e) {
    engine = e;
}

// Базовая реализация расчёта расхода — возвращает 0
// Должна быть переопределена в наследниках
double Vehicle::calculateConsumption() {
    return 0.0;
}