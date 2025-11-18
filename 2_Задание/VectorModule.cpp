// VectorModule.cpp - реализация функций для работы с векторами

//Автор: Кузнецов Александр Евгеньевич

#include "VectorModule.h" // Наш заголовочный файл
#include <vector>         // Для vector
#include <iostream>       // Для cout
#include <iomanip>        // Для форматирования вывода
#include <cstdlib>        // Для rand()

using namespace std;

// Реализация функций пространства имен VecMath
namespace VecMath  
{
// Функция заполнения вектора случайными числами
void fillRandom(vector<double>& vec, double min, double max)
{
    // Цикл по всем элементам вектора
    // vec.size() возвращает количество элементов
    for (size_t i = 0; i < vec.size(); ++i) {
        // Генерация случайного числа в диапазоне [0, 1)
        double r = static_cast<double>(rand()) / (RAND_MAX + 1.0);
        // Преобразование в диапазон [min, max]
        vec[i] = min + r * (max - min);
    }
}

// Функция ввода вектора с клавиатуры
void inputArray(vector<double>& vec)
{
    cout << "Введите " << vec.size() << " чисел:\n";
    // Цикл по всем элементам вектора
    for (size_t i = 0; i < vec.size(); ++i) {
        cin >> vec[i]; // Чтение каждого элемента
    }
}

// Функция вывода вектора на экран
void printArray(const vector<double>& vec)
{
    // Цикл по всем элементам вектора
    for (size_t i = 0; i < vec.size(); ++i) {
        // Форматированный вывод элемента
        cout << setw(10) << fixed << setprecision(2) << vec[i];
        
        // Перенос строки каждые 10 элементов или после последнего
        if ((i + 1) % 10 == 0 || i == vec.size() - 1) {
            cout << '\n'; // Перевод строки
        }
    }
}

// Функция вычисления суммы a1/0! + a2/1! + ... + an/(n-1!) для вектора
double sumFactorialDiv(const vector<double>& vec)
{
    if (vec.empty()) return 0.0; // Если вектор пустой, возвращаем 0

    double sum = 0.0; // Инициализация аккумулятора
    double factorial = 1.0; // Инициализация факториала: 0! = 1
    
    // Цикл по диапазону (range-based for loop):
    // Современный способ итерации по контейнеру
    for (size_t i = 0; i < vec.size(); ++i) {
        // Деление текущего элемента на факториал его индекса (i-1)! = i!
        // Для первого элемента (i=0) делим на 0! = 1
        sum += vec[i] / factorial;

        // Вычисление следующего факториала для следующей итерации
        // (i+1)! = i! * (i+1)
        // Делаем это только если i не последний, чтобы избежать лишнего умножения
        if (i < vec.size() - 1) {
            factorial *= (i + 1);
        }
    }
    
    return sum; // Возврат результата
}

} // Конец namespace VecMath