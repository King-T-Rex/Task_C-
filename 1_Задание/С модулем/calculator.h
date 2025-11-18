//Автор: Кузнецов Александр Евгеньевич

// calculator.h
#ifndef CALCULATOR_H //Проверка, был ли уже определен макрос CALCULATOR_H. Если да, то он пропускает определение, если нет, то выполняет код внутри #ifndef и #endif
#define CALCULATOR_H //Если не определен, то он его определяет и выполняет код внутри #define

// Пространство имен для функций вычисления
namespace Calc
{
    //Структура для возврата двух значений a и b
    struct Result 
    {
        //double - тип данных с дробной точностью
        double a; //Переменная a типа double
        double b; //Переменная b типа double
    };

    // Объявление функции вычисления a и b
    // Принимает три параметра: x, y, z
    // Возвращает структуру Result с вычисленными значениями
    Result ResAB(double x, double y, double z);

    // Альтернативные объявления с использованием ссылок и указателей
    void ResAB(double x, double y, double z, double& a, double& b);
    void ResAB(double x, double y, double z, double* a, double* b);
}
// namespace Calc конец пространства имен

#endif // Конец условия CALCULATOR_H