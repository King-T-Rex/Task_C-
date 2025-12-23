// main.cpp
// Кузнецов Александр
#include <iostream>     // Подключение библиотеки для ввода и вывода данных
#include <string>       // Подлкючение библиотеки для работы со строками

using namespace std;    // Чтобы не писать std::cout, std::string и т.д.

// Геттер (getter) — это метод, который возвращает значение приватного (или защищённого) поля объекта.
// Сеттер (setter) — это метод, который устанавливает новое значение приватного поля, часто с проверкой корректности (предусловиями).
// Полиморфизм — это способность объектов разных типов реагировать на один и тот же вызов по-разному.
//  1. Статический — через перегрузку функций и шаблоны (выбор реализации происходит на этапе компиляции).
//  2. Динамический — через виртуальные функции и наследование (выбор реализации происходит во время выполнения, на основе фактического типа объекта).

// Класс Engine описывает двигатель
class Engine {
    private:
        // Мощность двигателя в лошадиных силах
        int horsepower;
        // Тип двигателя
        string type;

    public:
        // Конструктор класса Engine
        // Вызывается при создании объекта Engine
        Engine(int hp = 0, string t = ""){
            // Сохраняет переданную мощность
            horsepower = hp;
            // Сохраняет тип двигателя
            type = t;
        }

        // Метод возращает мощность двигателя
        int getHorsepower() const {
            return horsepower;
        }

        // Метод устанавливает мощность двигателя
        void setHorsepower(int value) {
            horsepower = value;
        }

        // Метод возращает тип двигателя
        string getType() const {
            return type;
        }

        // Метод устанавливает тип двигателя
        void setType(string value) {
            type = value;
        }
};

// Класс Driver описывает водителя
class Driver {
    private:
        // Имя водителя
        string name;

    public:
        // Конструктор класса Driver
        // Вызывается при создании объекта Driver
        Driver(string n = "") {
            // Сохраняет имя водителя
            name = n;
        }

        // Метод возращает имя водителя
        string getName() const {
            return name;
        }

        // Метод устанавливает имя водителя
        void setName(string value) {
            name = value;
        }
};

// Базовый класс Vehicle (транспортное средство)
class Vehicle {
    // protected означает, что какие-то поля и методы доступны только внутри самого класса и его потомков (производных классов), но недоступны извне, как обычные пользователи программы.
    protected:
        // Марка транспортного средства
        string brand;
        // Указатель на водителя (агрегация)
        // Водитель может существовать отдельно от машины
        Driver* driver;
        // Двигатель является частью машины (композиция)
        Engine engine;

    public:
        // Конструктор класса Vehicle
        Vehicle(string b, Engine e): engine(e) {
            // Сохраняет марку
            brand = b;
            // Изначально водитель не назначен
            driver = nullptr;
        }

        // Метод возращает марку транспортного средства
        string getBrand() const {
            return brand;
        }

        // Метод устанавливает марку транспортного средства
        void setBrand(string value){
            brand = value;
        }

        // Метод возращает указатель на водителя
        Driver* getDriver() const {
            return driver;
        }
        // Метод назначает водителя
        void setDriver(Driver* d) {
            driver = d;
        }

        // Метод возращает двигатель
        Engine getEngine() const {
            return engine;
        }

        // Метод устанавливает двигатель
        void setEngine(Engine e) {
            engine = e;
        }

        // Метод расчёта расхода топлива
        // Виртуальный метод, чтобы переопределять в наследниках
        virtual double calculateConsumption() {
            return 0.0;
        }
};

// Класс наследуется от Vehicle
class Car: public Vehicle {
    private:
        // Количество дверей у автомобиля
        int doors;

    public:
        // Конструктор класса Car
        // : Vehicle(b, e) - вызывает конструктор базового класса Vehicle
        Car(string b, Engine e, int d): Vehicle(b, e){
            // Сохраняет количество дверей
            doors = d;
        }

        // Метод запуска автомобиля
        void start(){
            cout << "Car started" << endl;
        }

        // Метод остановки автомобиля
        void stop(){
            cout << "Car stopped" << endl;
        }

        // Метод возращает количество дверей
        int getDoors() const {
            return doors;
        }

        // Метод устанавливает количество дверей
        void setDoors(int value){
            doors = value;
        }

        // Переопределение метода расчёта расхода топлива
        // override – спецификатор для переопределяемого виртуального (или абстрактного) метода в производном классе.
        double calculateConsumption() override {
            // Расчёт для автомобиля
            return engine.getHorsepower() * 0.5;
        }
};

// Класс Truck наследуется от Vehicle
class Truck: public Vehicle{
    private:
        // Грузоподъёмность грузовика
        double capacity;

    public:
        // Конструктор класса Truck
        // : Vehicle(b, e) - вызывает конструктор базового класса Vehicle
        Truck(string b, Engine e, double c): Vehicle(b, e) {
            // Сохраняет грузоподъёмность
            capacity = c;
        }

        // Метод запуска грузовика
        void start(){
            cout << "Truck started" << endl;
        }

        // Метод остановки грузовика
        void stop(){
            cout << "Truck stopped" << endl;
        }

        // Метод возращает грузоподъёмность
        double getCapacity() const {
            return capacity;
        }

        // Метод устанавливает грузоподъёмность
        void setCapacity(double value){
            capacity = value;
        }

        // Переопределение метода расчета расхода топлива
        double calculateConsumption() override {
            // Расход зависит от мощности двигателя и грузоподъёмности
            return engine.getHorsepower() * 0.1 + capacity * 0.02;
        }
};

int main(){

    // Создание двигателя для Car
    Engine engine1(150, "Petrol");
    // Создание двигатель для Truck
    Engine engine2(420, "Diesel");
    
    // Создание объекта водителя
    Driver driver("Aleksandr Kuznetsov");

    // Создание объекта автомобиля
    Car car("Toyota", engine1, 4);
    // Создание объекта грузовика
    Truck truck("MAN", engine2, 12.0);

    // Назначение водителя автомобилю на ссылку
    car.setDriver(&driver);
    // Назчанение водителя грузовику на ссылку
    truck.setDriver(&driver);

    // Запуск автомобиль
    car.start();
    // Вывод расход топлива автомоболя
    cout << "Car consumption: " << car.calculateConsumption() << endl;
    // Остановка автомобиль
    car.stop();

    // Запуск грузовик
    truck.start();
    // Вывод расход топлива грузовика
    cout << "Truck consumption: " << truck.calculateConsumption() << endl;
    // Остановка грузовик
    truck.stop();

    // Указатели базового класса Vegicle
    Vehicle* v1 = &car;
    Vehicle* v2 = &truck;

    // Вызов одного и того же метода, но выполняются разные версии метода
    cout << "Car consumption: " << v1->calculateConsumption() << endl;
    cout << "Truck consumption: " << v2->calculateConsumption() << endl;
    
    // Завершение программы
    return 0;

}