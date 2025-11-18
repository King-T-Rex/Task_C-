// VectorModule.h - заголовочный файл для работы с векторами

//Автор: Кузнецов Александр Евгеньевич

#ifndef VECTORMODULE_H // Защита от повторного включения
#define VECTORMODULE_H

#include <vector>   // Для контейнера std::vector
#include <iostream> // Для потоков ввода-вывода

using namespace std;

// Пространство имен для работы с векторами
namespace VecMath 
{
    // Функция заполнения вектора случайными числами
    // Заполняет вектор случайными числами в заданном диапазоне
    // vector<double>& vec - ссылка на вектор для заполнения
    // double min - минимальное значение (по умолчанию -10.0)
    // double max - максимальное значение (по умолчанию 10.0)
    void fillRandom(vector<double>& vec, double min = -10.0, double max = 10.0);

    // Функция ввода вектора с клавиатуры
    // vector<double>& - ссылка на вектор для заполнения
    void inputArray(vector<double>& vec);

    // Функция вывода вектора на экран
    // Вывод вектора на экран по 10 элементов в строке
    // vector<double>& - константная ссылка на вектор для вывода
    void printArray(const vector<double>& vec);

    // Функция вычисления суммы a1/0! + a2/1! + ... + an/(n-1!) для вектора
    // vector<double>& - константная ссылка на вектор
    double sumFactorialDiv(const vector<double>& vec);

} // Конец namespace VecMath

#endif // VECTORMODULE_H