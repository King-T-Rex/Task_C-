// driver.h
// Кузнецов Александр
#ifndef driver_h
#define driver_h

#include <string>  // Для работы со строками

// Класс Driver описывает водителя.
// Используется в агрегации (водитель может существовать отдельно от машины).
class Driver {
private:
    std::string name;  // Имя водителя

public:
    // Конструктор класса Driver
    // n — имя водителя; по умолчанию — пустая строка
    Driver(const std::string& n = "");

    // Геттер: возвращает имя водителя
    std::string getName() const;

    // Сеттер: устанавливает имя водителя
    void setName(const std::string& value);
};

#endif // driver_h