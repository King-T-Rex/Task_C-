// vehicle.h
// Кузнецов Александр
#ifndef vehicle_h
#define vehicle_h

#include <string>
#include "engine.h"
#include "driver.h"

using namespace std;

// Базовый класс Vehicle (транспортное средство)
// Использует:
//   - композицию для Engine (двигатель — часть машины),
//   - агрегацию для Driver* (водитель — внешний объект)
class Vehicle {
protected:
    string brand;   // Марка транспортного средства
    Driver* driver;      // Указатель на водителя (агрегация)
    Engine engine;       // Двигатель (композиция)

public:
    // Конструктор класса Vehicle
    // b — марка, e — двигатель (передаётся по значению, копируется внутрь)
    Vehicle(const std::string& b, const Engine& e);

    // Геттер и сеттер для марки
    string getBrand() const;
    void setBrand(const std::string& value);

    // Геттер и сеттер для водителя
    Driver* getDriver() const;
    void setDriver(Driver* d);

    // Геттер и сеттер для двигателя
    Engine getEngine() const;
    void setEngine(const Engine& e);

    // Виртуальный метод для расчёта расхода топлива
    // Может быть переопределён в дочерних классах (динамический полиморфизм)
    virtual double calculateConsumption();

    // Виртуальный деструктор — хорошая практика при наследовании
    virtual ~Vehicle() = default;
};

#endif // vehicle_h