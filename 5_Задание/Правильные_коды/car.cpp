// car.cpp
// Кузнецов Александр
#include "car.h"
#include <iostream>
using namespace std;

// Конструктор: вызывает конструктор базового класса и инициализирует doors
Car::Car(const string& b, const Engine& e, int d) : Vehicle(b, e), doors(d) {}

// Метод запуска автомобиля
void Car::start() {
    cout << "Car started" << endl;
}

// Метод остановки автомобиля
void Car::stop() {
    cout << "Car stopped" << endl;
}

// Геттер: количество дверей
int Car::getDoors() const {
    return doors;
}

// Сеттер: устанавливает количество дверей
void Car::setDoors(int value) {
    doors = value;
}

// Переопределённый метод расчёта расхода топлива для автомобиля
// Зависит только от мощности двигателя
double Car::calculateConsumption() {
    return engine.getHorsepower() * 0.5;
}