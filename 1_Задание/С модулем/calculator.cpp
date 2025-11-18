//Автор: Кузнецов Александр Евгеньевич

// calculator.cpp
#include "calculator.h" // Подключает заголовочный файл с объявлениями
#include <cmath>        // Для математических функций: sqrt, pow, atan, exp, fabs
#include <stdexcept>    // Для исключений, например runtime_error

using namespace std; //Для упрощения записи

// Функция для вычисления a
double calculate_a(double x, double y){

    // Вычисление числителя: sqrt|x-1| - 3sqrt|y|
    double numerator = sqrt(fabs(x - 1)) - 3 * pow(fabs(y), 1.0/3.0);

    // Вычисление знаменателя: 1 + x^2/2 + y^2/4
    double denominator = 1 + (x * x) / 2 + (y * y) / 4;

    // Вычисляет a = числитель / знаменатель
    return numerator / denominator;
}

// Функция для вычисления b
double calculate_b(double x, double z){
    
    // Проверка на переполнение экспоненты
    if (-(x + 3) > 700) { // Приблизительный предел для exp
        throw runtime_error("Переполнение при вычислении экспоненты в b");
    }
    // atan(z) - арктангенс z
    // exp(-(x+3)) - экспонента в степени -(x+3)
    
    return x * (atan(z) + exp(-(x + 3)));; //Возвращает структуру с результатами
}

// Реализация функции ResAB с использованием отдельных функций
//Result ResAB это функция которая принимает три аргумента типа double и возвращает структуру Result
Calc::Result Calc::ResAB(double x, double y, double z) 
{
    Result result; //Создает структуру для хранения результатов
    
    // Вычисление a и b с помощью отдельных функций с обработкой исключений
    try {
        result.a = calculate_a(x, y);
        result.b = calculate_b(x, z);
    } catch (const exception& e) {
        // В случае ошибки выбрасываем исключение дальше
        throw;
    }
    
    return result; //Возвращает структуру с результатами
}

// Альтернативная реализация с использованием ссылок
void Calc::ResAB(double x, double y, double z, double& a, double& b) 
{
    a = calculate_a(x, y);
    b = calculate_b(x, z);
}

// Альтернативная реализация с использованием указателей
void Calc::ResAB(double x, double y, double z, double* a, double* b) 
{
    if (a != nullptr && b != nullptr) {
        *a = calculate_a(x, y);
        *b = calculate_b(x, z);
    }
}