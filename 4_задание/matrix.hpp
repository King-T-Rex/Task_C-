// Автор: Кузнецов Александр
// matrix.hpp

/*
Класс Matrix — прямоугольная матрица вещественных чисел.

Назначение:
  Представление матриц и выполнение линейных операций:
  сложение, умножение, транспонирование, обратная матрица и др.

Принципы использования:
  - Создавайте через Matrix(rows, cols)
  - Доступ к элементам: A.at(i, j)
  - Все операции выбрасывают исключения при ошибках

Пример:
  Matrix A(2, 2);
  A.at(0,0) = 1; A.at(0,1) = 2;
  A.at(1,0) = 3; A.at(1,1) = 4;
  Matrix B = A.transpose();
*/

#ifndef matrix_hpp      // Защита от двойного подключения заголовочного файла.
#define matrix_hpp      // Если этот файл уже подключали — он не подключится повторно.

#include <vector>       // Cтандартный динамический массив
#include <cstddef>      // size_t — тип для хранения размеров и индексов
#include <functional>   // function — нужен для передачи функций как параметров

using namespace std;

// Класс Matrix — это описание матрицы
// Класс — это шаблон, по которому создаются объекты
class Matrix {
private:
    // Количество строк матрицы
    size_t rows;

    // Количество столбцов матрицы
    size_t cols;

    // Вектор, в котором хранятся все элементы матрицы подряд
    // Матрица хранится в одной линии памяти
    vector<double> data;

    // Вспомогательная функция
    // Переводит номер строки и столбца в индекс вектора
    size_t index(size_t r, size_t c) const;

public:
    // Конструктор класса
    // Создаёт матрицу размером rows x cols
    // Все элементы автоматически становятся равны 0
    Matrix(size_t rows, size_t cols);

    // Конструктор квадратной матрицы n x n
    explicit Matrix(size_t n);

    // Функция доступа к элементу матрицы
    // Возвращает ссылку, чтобы можно было менять значение
    double& at(size_t r, size_t c);

    // Та же функция, но для константных объектов
    const double& at(size_t r, size_t c) const;

    // Заполнение всей матрицы одним значением
    void fill(double value);

    // Заполнение матрицы случайными числами
    void fillRandom(double min, double max);

    // Получить количество строк
    size_t rowCount() const;

    // Получить количество столбцов
    size_t colCount() const;

    // Оператор сложения матриц
    Matrix operator+(const Matrix& other) const;

    // Оператор вычитания матриц
    Matrix operator-(const Matrix& other) const;

    // Оператор +=
    Matrix& operator+=(const Matrix& other);

    // Оператор -=
    Matrix& operator-=(const Matrix& other);

    // Умножение матрицы на число
    Matrix operator*(double scalar) const;

    // Оператор *= для умножения на число
    Matrix& operator*=(double scalar);

    // Умножение матрицы на матрицу
    Matrix operator*(const Matrix& other) const;

    // Транспонирование матрицы
    Matrix transpose() const;

    // Статическая функция создания диагональной матрицы
    static Matrix diagonal(const vector<double>& diag);

    // Вычисление определителя (только для квадратных матриц)
    double determinant() const;

    // Вычисление обратной матрицы
    Matrix inverse() const;

    // Получение строки матрицы
    vector<double> row(size_t r) const;

    // Применение функции ко всем элементам матрицы
    void apply(const function<double(double)>& func);
};

#endif
