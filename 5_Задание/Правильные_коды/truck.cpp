// truck.cpp
// Кузнецов Александр
#include "truck.h"
#include <iostream>
using namespace std;

// Конструктор: инициализирует базовый класс и capacity
Truck::Truck(const string& b, const Engine& e, double c) : Vehicle(b, e), capacity(c) {}

// Запуск грузовика
void Truck::start() {
    cout << "Truck started" << endl;
}

// Остановка грузовика
void Truck::stop() {
    cout << "Truck stopped" << endl;
}

// Геттер: грузоподъёмность
double Truck::getCapacity() const {
    return capacity;
}

// Сеттер: устанавливает грузоподъёмность
void Truck::setCapacity(double value) {
    capacity = value;
}

// Расход топлива зависит от мощности и грузоподъёмности
double Truck::calculateConsumption() {
    return engine.getHorsepower() * 0.1 + capacity * 0.02;
}