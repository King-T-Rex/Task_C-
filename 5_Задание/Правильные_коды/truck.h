// truck.h
// Кузнецов Александр
#ifndef truck_h
#define truck_h

#include "vehicle.h"

// Класс Truck — наследник Vehicle (грузовик)
// Добавляет поле грузоподъёмности
class Truck : public Vehicle {
private:
    double capacity;  // Грузоподъёмность в тоннах

public:
    // Конструктор: передаёт параметры базовому классу и устанавливает capacity
    Truck(const std::string& b, const Engine& e, double c);

    // Методы управления грузовиком
    void start();
    void stop();

    // Геттер и сеттер для грузоподъёмности
    double getCapacity() const;
    void setCapacity(double value);

    // Переопределение расчёта расхода топлива
    double calculateConsumption() override;
};

#endif // truck_h