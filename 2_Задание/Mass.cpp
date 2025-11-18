// Mass.cpp - реализация функций для работы с массивами

//Автор: Кузнецов Александр Евгеньевич

#include "Mass.h"      // Наш заголовочный файл
#include <iomanip>     // Для манипуляторов вывода: setprecision, setw
#include <iostream>    // Для потоков ввода-вывода
#include <cstdlib>     // Для rand(), srand()
#include <ctime>       // Для time()
#include <fstream>     // Для файлового ввода/вывода: ifstream, ofstream
#include <stdexcept>   // Для стандартных исключений: runtime_error

using namespace std;   //Для упрощения записи

// Реализация функций пространства имен Mass
namespace Mass 
{
// Функция заполнения массива случайными числами
void fillRandom(double* arr, int n, double min, double max)
{
    // Цикл по всем элементам массива
    for (int i = 0; i < n; ++i) 
    {
        /*
        Генерация случайного числа в диапазоне [min, max]:
        1. rand() - генерирует целое число от 0 до RAND_MAX
        2. static_cast<double>(rand()) - преобразует в double
        3. / (RAND_MAX + 1.0) - нормализует в диапазон [0, 1)
        4. (max - min) * ... - масштабирует в [0, max-min)
        5. min + ... - сдвигает в [min, max)
        */
        double randomValue = min + (max - min) * (static_cast<double>(rand()) / (RAND_MAX + 1.0));
        arr[i] = randomValue; // Запись значения в массив
    }
}

// Функция вывода массива на экран
void printArray(const double* arr, int n) 
{
    // Цикл по всем элементам массива
    for (int i = 0; i < n; ++i) 
    {
        /*
        Форматирование вывода:
        setw(10) - ширина поля 10 символов
        fixed - фиксированная точка (не экспоненциальная запись)
        setprecision(2) - 2 знака после запятой
        */
        cout << setw(10) << fixed << setprecision(2) << arr[i];
        
        // Перенос строки:
        // Каждые 10 элементов или после последнего элемента
        if ((i + 1) % 10 == 0 || i == n - 1) 
        {
            cout << endl; // Перевод строки
        }
    }
}

// Функция вычисления суммы a1/0! + a2/1! + ... + an/(n-1)!
double SumFactorialDiv(const double* arr, int n)
{ 
    if (n <= 0) return 0.0; // Если массив пустой, возвращаем 0

    double sum = 0.0; // Инициализация аккумулятора
    double factorial = 1.0; // Инициализация факториала: 0! = 1
    
    // Цикл по всем элементам массива
    for (int i = 0; i < n; ++i) 
    {
        // Деление текущего элемента на факториал его индекса (i-1)! = i!
        // Для первого элемента (i=0) делим на 0! = 1
        sum += arr[i] / factorial;
        
        // Вычисление следующего факториала для следующей итерации
        // (i+1)! = i! * (i+1)
        // Если i не последний, чтобы избежать лишнего умножения
        if (i < n - 1) {
            factorial *= (i + 1);
        }
    }
    
    return sum; // Возврат результата
}

// Функция ручного ввода массива
void inputArray(double* arr, int n)
{
    cout << "Введите " << n << " чисел через пробел или Enter:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i]; // Чтение каждого элемента
    }
}

} // Конец namespace Mass

// Реализация функций пространства имен fileSL
namespace fileSL 
{
// Функция сохранения массива в текстовый файл
void saveFileText(const double* arr, int n, const char* filename)
{
    // Создание объекта для записи в файл
    ofstream file(filename);
    
    // Проверка успешности открытия файла
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << filename << " для записи.\n";
        return;
    }
    
    file << n << '\n'; // Запись размера массива (первая строка)
    
    // Запись элементов массива
    for (int i = 0; i < n; ++i) {
        file << arr[i] << '\n'; // Каждый элемент на новой строке
    }
    
    file.close(); // Закрытие файла
    cout << "Массив сохранён в текстовый файл '" << filename << "'.\n";
}

// Функция загрузки массива из текстового файла
double* loadFileText(int& n, const char* filename)
{
    // Создание объекта для чтения из файла
    ifstream file(filename);
    
    // Проверка успешности открытия файла
    if (!file.is_open()) 
    {
        throw runtime_error("Ошибка: не удалось открыть файл " + string(filename) + " для чтения.");
    }

    file >> n; // Чтение размера массива
    
    // Проверка корректности размера
    if (n <= 0) 
    {
        throw runtime_error("Ошибка: некорректный размер массива в файле.\n");
    }

    // Выделение памяти под массив
    double* arr = new double[n];
    
    // Чтение элементов массива
    for (int i = 0; i < n; ++i) 
    {
        if (!(file >> arr[i])) 
        {          
            delete[] arr;  // Освобождение памяти при ошибке
            throw runtime_error("Ошибка: не удалось прочитать все элементы массива.\n");
        }
    }
    
    file.close(); // Закрытие файла
    return arr; // Возврат указателя на массив
}

// Функция сохранения массива в бинарный файл
void saveFileBin(const double* arr, int n, const char* filename)
{
    /*
    ios::binary - открывает файл в бинарном режиме
    Отличие от текстового:
    - Нет преобразования переводов строк
    - Данные записываются как есть (байты)
    */
    ofstream file(filename, ios::binary); 
    
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть бинарный файл " << filename << " для записи.\n";
        return;
    }
    
    /*
    Запись в бинарном формате:
    reinterpret_cast<const char*> - преобразование типа указателя
    &n - адрес переменной размера
    sizeof(n) - количество байт для записи
    */
    file.write(reinterpret_cast<const char*>(&n), sizeof(n));
    
    // Запись всего массива сразу
    file.write(reinterpret_cast<const char*>(arr), n * sizeof(double));
    
    file.close();
    cout << "Массив сохранён в бинарный файл '" << filename << "'.\n";
}

// Функция загрузки массива из бинарного файла
double* loadFileBin(int& n, const char* filename)
{
    // Открытие файла в бинарном режиме для чтения
    ifstream file(filename, ios::binary);
    
    if (!file.is_open()) 
    {
        throw runtime_error("Ошибка: не удалось открыть бинарный файл " + string(filename));
    }

    // Чтение размера массива
    file.read(reinterpret_cast<char*>(&n), sizeof(n));
    
    if (n <= 0) {
        throw runtime_error("Ошибка: некорректный размер массива в бинарном файле.\n");
    }

    // Выделение памяти под массив
    double* arr = new double[n];
    
    // Чтение всего массива сразу
    file.read(reinterpret_cast<char*>(arr), n * sizeof(double));
    
    // Проверка успешности чтения
    if (!file) 
    {
        delete[] arr; // Освобождение памяти при ошибке
        throw runtime_error("Ошибка: не удалось прочитать данные из бинарного файла.\n");
    }
    
    file.close();
    return arr; // Возврат указателя на массив
}

} // Конец namespace fileSL