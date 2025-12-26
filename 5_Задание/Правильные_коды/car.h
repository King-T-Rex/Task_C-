// car.h
// Кузнецов Александр
#ifndef car_h
#define car_h

#include "vehicle.h"

// Класс Car — наследник Vehicle (автомобиль)
// Добавляет специфичное поле: количество дверей
class Car : public Vehicle {
private:
    int doors;  // Количество дверей

public:
    // Конструктор: передаёт параметры базовому классу и устанавливает doors
    Car(const std::string& b, const Engine& e, int d);

    // Методы управления автомобилем
    void start();  // Запуск
    void stop();   // Остановка

    // Геттер и сеттер для количества дверей
    int getDoors() const;
    void setDoors(int value);

    // Переопределение виртуального метода расчёта расхода
    double calculateConsumption() override;
};

#endif // car_h