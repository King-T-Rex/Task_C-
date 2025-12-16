// Автор: Кузнецов Александр
// matrix.cpp

#include "matrix.hpp"   // Подключаем заголовочный файл с описанием класса
#include <stdexcept>    // Для генерации исключений
#include <random>       // Для случайных чисел
#include <cmath>        // Для математических функций

using namespace std;

// Функция переводит координаты (строка, столбец)
// в индекс одномерного массива
size_t Matrix::index(size_t r, size_t c) const {
    // Формула хранения матрицы в одну линию
    return r * cols + c;
}

// Конструктор матрицы rows x cols
Matrix::Matrix(size_t rows, size_t cols)
    : rows(rows), cols(cols), data(rows * cols, 0.0)
// data(rows * cols, 0.0) — создаём вектор нужного размера и заполняем нулями
{}

// Конструктор квадратной матрицы
Matrix::Matrix(size_t n)
    : rows(n), cols(n), data(n * n, 0.0)
{}

// Доступ к элементу матрицы
double& Matrix::at(size_t r, size_t c) {
    // Проверяем выход за границы
    if (r >= rows || c >= cols) {
        throw out_of_range("Ошибка: выход за границы матрицы");
    }
    return data[index(r, c)];
}

// Константная версия функции доступа
const double& Matrix::at(size_t r, size_t c) const {
    if (r >= rows || c >= cols) {
        throw out_of_range("Ошибка: выход за границы матрицы");
    }
    return data[index(r, c)];
}

// Заполнение всей матрицы одним значением
void Matrix::fill(double value) {
    // Проходим по всем элементам
    for (double& x : data) {
        x = value;
    }
}

// Заполнение случайными числами
void Matrix::fillRandom(double min, double max) {
    random_device rd;   // источник случайности
    mt19937 gen(rd());  // генератор
    uniform_real_distribution<double> dist(min, max);

    for (double& x : data) {
        x = dist(gen);
    }
}

// Получение количества строк
size_t Matrix::rowCount() const {
    return rows;
}

// Получение количества столбцов
size_t Matrix::colCount() const {
    return cols;
}

// Сложение матриц
Matrix Matrix::operator+(const Matrix& other) const {
    // Проверяем размеры
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("Матрицы разных размеров");
    }

    Matrix result(rows, cols);

    // Складываем элементы
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// Вычитание матриц
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("Матрицы разных размеров");
    }

    Matrix result(rows, cols);
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

// +=
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

// -=
Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}

// Умножение на число
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] * scalar;
    }
    return result;
}

// *=
Matrix& Matrix::operator*=(double scalar) {
    for (double& x : data) {
        x *= scalar;
    }
    return *this;
}

// Умножение матрицы на матрицу
Matrix Matrix::operator*(const Matrix& other) const {
    // Проверяем совместимость размеров
    if (cols != other.rows) {
        throw invalid_argument("Нельзя умножить матрицы");
    }

    Matrix result(rows, other.cols);

    // Классический алгоритм умножения
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result.at(i, j) += at(i, k) * other.at(k, j);
            }
        }
    }
    return result;
}

// Транспонирование
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.at(j, i) = at(i, j);
        }
    }
    return result;
}

// Создание диагональной матрицы
Matrix Matrix::diagonal(const vector<double>& diag) {
    size_t n = diag.size();
    Matrix result(n);

    for (size_t i = 0; i < n; ++i) {
        result.at(i, i) = diag[i];
    }
    return result;
}

// Определитель (2x2)
double Matrix::determinant() const {
    if (rows != cols) {
        throw logic_error("Матрица не квадратная");
    }

    if (rows == 2) {
        return at(0,0)*at(1,1) - at(0,1)*at(1,0);
    }

    throw logic_error("Определитель реализован только для 2x2");
}

// Обратная матрица (2x2)
Matrix Matrix::inverse() const {
    double det = determinant();

    if (abs(det) < 1e-9) {
        throw logic_error("Определитель равен нулю");
    }

    Matrix result(2);
    result.at(0,0) =  at(1,1) / det;
    result.at(0,1) = -at(0,1) / det;
    result.at(1,0) = -at(1,0) / det;
    result.at(1,1) =  at(0,0) / det;

    return result;
}

// Получение строки матрицы
vector<double> Matrix::row(size_t r) const {
    if (r >= rows) {
        throw out_of_range("Неверный номер строки");
    }

    vector<double> result(cols);
    for (size_t j = 0; j < cols; ++j) {
        result[j] = at(r, j);
    }
    return result;
}

// Применение функции ко всем элементам
void Matrix::apply(const function<double(double)>& func) {
    for (double& x : data) {
        x = func(x);
    }
}
