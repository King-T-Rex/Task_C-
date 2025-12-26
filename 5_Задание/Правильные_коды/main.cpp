// main.cpp
// Кузнецов Александр
#include <iostream>     // Подключение библиотеки для ввода и вывода данных
#include "Car.h"
#include "Truck.h"
using namespace std;    // Чтобы не писать std::cout, std::string и т.д.

// Главная функция программы
int main() {
    // Создание два разных двигателя
    Engine engine1(150, "Petrol");   // Для автомобиля
    Engine engine2(420, "Diesel");   // Для грузовика

    // Создание водителя
    Driver driver("Aleksandr Kuznetsov");

    // Создание автомобиля и грузовика
    Car car("Toyota", engine1, 4);
    Truck truck("MAN", engine2, 12.0);

    // Назначение одного и того же водителя обоим транспортным средствам (агрегация)
    car.setDriver(&driver);
    truck.setDriver(&driver);

    // Управление автомобилем
    car.start();
    cout << "Car consumption: " << car.calculateConsumption() << endl;
    car.stop();

    // Управление грузовиком
    truck.start();
    cout << "Truck consumption: " << truck.calculateConsumption() << endl;
    truck.stop();

    // Демонстрация полиморфизма: указатели на базовый класс
    Vehicle* v1 = &car;
    Vehicle* v2 = &truck;

    // Вызов виртуальных методов через базовые указатели
    cout << "Polymorphic calls:" << endl;
    cout << "v1 consumption: " << v1->calculateConsumption() << endl;
    cout << "v2 consumption: " << v2->calculateConsumption() << endl;

    // Использование dynamic_cast
    // Пытаемся привести v1 (на самом деле Car) к Car*
    Car* maybeCar = dynamic_cast<Car*>(v1);
    if (maybeCar) {
        // Приведение успешно — можем вызывать методы Car
        cout << "Dynamic cast succeeded: this is a Car with " << maybeCar->getDoors() << " doors." << endl;
    }
    else
    {
        cout << "v1 is not a Car." << endl;
    }

    // Пытаемся привести v1 к Truck*
    Truck* maybeTruck = dynamic_cast<Truck*>(v1);
    if (!maybeTruck) {
        cout << "v1 is not a Truck." << endl;
    }
    else
    {
        cout << "Dynamic cast succeeded: this is a Truck with capacity " << maybeTruck->getCapacity() << " tons." << endl;
    }

    return 0;  // Успешное завершение программы
}