// Автор: Кузнецов Александр
// main.cpp

#include "matrix.hpp"   // Подключаем наш класс Matrix, чтобы можно было им пользоваться.
#include <iostream>     // Нужно для вывода текста в консоль (cout).
#include <cassert>      // Нужно для assert — проверки условий в тестах.

// Подключаем Windows-заголовки, чтобы настроить кодировку консоли.
// WIN32_LEAN_AND_MEAN и NOMINMAX — чтобы не тащить лишнее.
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

using namespace std;    // Чтобы не писать std:: перед каждым cout, vector и т.п.

// Функция для автоматической проверки, что класс работает правильно.
void runTests() {

    // Тест 1 - Конструктор и доступ к элементам
    // Создаём матрицу 2×2, заполненную нулями.
    Matrix A(2, 2);
    A.at(0,0) = 2;
    A.at(0,1) = 1;
    A.at(1,0) = 5;
    A.at(1,1) = 3;

    // Заполняем матрицу вручную.
    // Проверяем, что значения сохранились правильно.
    assert(A.at(0,0) == 2);
    assert(A.at(1,1) == 3);


    // Тест 2 - Сложение матриц
    // Создаём диагональную матрицу:
    Matrix B = Matrix::diagonal({1, 2});
    Matrix C = A + B;   // Складываем две матрицы.

    // Проверяем результат.
    assert(C.at(0,0) == 3);
    assert(C.at(1,1) == 5);


    // Тест 3 - Умножение на число
    Matrix D = A * 2.0; // Каждый элемент A умножается на 2.

    // Проверяем результат.
    assert(D.at(0,0) == 4);
    assert(D.at(1,1) == 6);


    // Тест 4 - Транспонирование
    // Меняем строки и столбцы местами.
    Matrix AT = A.transpose();

    // Проверяем результат.
    assert(AT.at(0,1) == 5);
    assert(AT.at(1,0) == 1);


    // Тест 5 - Определитель
    // Вычисляем определитель матрицы 2×2.
    double det = A.determinant();
    // Проверяем результат.
    assert(det == 1.0);


    // Тест 6 - Обратная матрица
    // Находим обратную матрицу.
    Matrix Ainv = A.inverse();

    // Проверяем результат.
    assert(Ainv.at(0,0) == 3.0);
    assert(Ainv.at(1,1) == 2.0);


    // Тест 7 - Проверка исключения
    bool caught = false;    // Флаг — было ли поймано исключение.
    // Пытаемся взять определитель неквадратной матрицы.
    try {
        Matrix bad(2, 3);
        bad.determinant();
    }
    // Если исключение поймано — всё правильно.
    catch (const logic_error&) {
        caught = true;
    }
    // Проверяем, что исключение действительно было.
    assert(caught);


    // Tест 8 - Проверка решения СЛАУ A * x = b
    Matrix b(2, 1);                 // Вектор-столбец.
    b.at(0, 0) = 5;
    b.at(1, 0) = 11;
    Matrix x = A.inverse() * b;     // Решаем уравнение.

    // Проверяем результат.
    assert(abs(x.at(0, 0) - 4.0) < 1e-9);
    assert(abs(x.at(1, 0) + 3.0) < 1e-9);

    
    // Сообщение об успехе.
    cout << "\n";
    cout << "Все тесты пройдены!" << endl;
}

// Наглядная демонстрация
void runDemo() {

    cout << "\nДемонстрация работы класса Matrix \n";

    Matrix A(2, 2);
    A.at(0,0) = 2;
    A.at(0,1) = 1;
    A.at(1,0) = 5;
    A.at(1,1) = 3;

    cout << "Матрица A создана\n";

    double det = A.determinant();
    cout << "Определитель A = " << det << endl;

    Matrix Ainv = A.inverse();
    cout << "Обратная матрица найдена\n";

    // Решение систему A * x = b
    Matrix b = Matrix::diagonal({5, 11});
    Matrix x = Ainv * b;

    cout << "Решение системы A * x = b:\n";
    cout << "x1 = " << x.at(0,0) << endl;
    cout << "x2 = " << x.at(1,1) << endl;
    cout << "\n";
}


int main() {

    // Настраиваем консоль на русский язык
    setlocale(LC_ALL, ".UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Запуск всех тестов
    runTests();

    // Запуск работу класса
    runDemo();

    // Завершение программы
    return 0;
}
