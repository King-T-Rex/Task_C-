// main.cpp
// Автор: Кузнецов Александр

// Демонстрация работы с классом Square и автоматические тесты

#include "square.hpp"
#include <iostream>
#include <fstream>
#include <cassert>

// Для Windows: чтобы русский текст в консоли отображался правильно
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

using namespace std;

// Простой автоматический тест с помощью assert
// Если что-то пойдёт не так — программа аварийно завершится с сообщением
void runTests() {

    // Тест 1: проверяем, что конструктор и геттеры работают
    Square s(2.0, 1.0, 1.0);
    assert(s.getSide() == 2.0);
    assert(s.getX() == 1.0);
    assert(s.getY() == 1.0);


    // Тест 2: площадь и периметр
    assert(s.area() == 4.0);
    assert(s.perimeter() == 8.0);


    // Тест 3: перемещение центра
    s.move(3.0, 4.0);
    assert(s.getX() == 3.0);
    assert(s.getY() == 4.0);


    // Тест 4: сравнение квадратов
    Square s2(2.0, 3.0, 4.0);
    assert(s == s2);
    assert(!(s != s2));


    // Тест 5: проверка исключения при плохой стороне
    bool caught = false;
    try {
        Square bad(-1.0);  // должно вызвать исключение
    } catch (const invalid_argument&) {
        caught = true;  // всё правильно — исключение поймано
    }
    assert(caught);


    // Тест 6: запись в файл и чтение обратно
    {
        ofstream f("test_sq.txt");
        f << s2;
        f.close();
    }
    {
        ifstream f("test_sq.txt");
        double s_val, x_val, y_val;
        f >> s_val >> x_val >> y_val;
        Square loaded(s_val, x_val, y_val);
        assert(s2 == loaded);  // загруженный квадрат должен быть таким же
        f.close();
    }

    cout << "\n";
    cout << "Все тесты пройдены!\n";
}

// Основная программа: показывает, как использовать класс Square
int main() {
    // Настраиваем консоль на русский язык (UTF-8)
    setlocale(LC_ALL, ".UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "\nКласс 'Квадрат'\n";
    runTests();
    cout << "\n";


    // 1. Статический объект — живёт на стеке, удаляется автоматически
    // Конструктор вызывается один раз при создании
    Square s1(2.5, 1.0, -1.0);
    cout << "s1: " << s1 << "\n";


    // 2. Динамическое создание — в куче, нужно удалять вручную
    // Здесь вызывается конструктор при new, и деструктор — при delete
    Square* s2 = new Square(3.0);
    cout << "*s2: " << *s2 << "\n";
    delete s2;


    // 3. Массив из объектов (статический)
    // Для каждого элемента автоматически вызывается конструктор
    Square arr[2] = { Square(1.0), Square(2.0) };
    cout << "arr[0]: " << arr[0] << "\n";


    // 4. Динамический массив объектов
    // Память выделяется в куче, конструктор вызывается для каждого элемента
    Square* dyn = new Square[2]{ Square(4.0), Square(5.0, 1, 1) };
    cout << "dyn[1]: " << dyn[1] << "\n";
    delete[] dyn;  // удаляем весь массив — вызываются деструкторы всех элементов


    // 5. Массив указателей на объекты
    // Здесь сами объекты создаются через new, а массив хранит только адреса
    Square* ptrs[2] = { new Square(1.0), new Square(2.0) };
    cout << "*ptrs[0]: " << *ptrs[0] << "\n";
    // Каждый объект удаляется отдельно
    delete ptrs[0];
    delete ptrs[1];


    // 6. Работа с файлом: сохраняем и загружаем
    {
        ofstream f("square.txt");
        f << s1;  // сохраняем состояние объекта в файл
        f.close();
    }
    {
        ifstream f("square.txt");
        double s_val, x_val, y_val;
        f >> s_val >> x_val >> y_val;
        Square loaded(s_val, x_val, y_val);  // создаём новый квадрат из прочитанных данных — восстанавливаем объект
        cout << "Загружено: " << loaded << "\n";
        cout << "Равны? " << (s1 == loaded ? "да" : "нет") << "\n";
        f.close();  // обязательно закрываем файл после чтения
    }

    cout << "\nГотово\n";
    return 0;
}