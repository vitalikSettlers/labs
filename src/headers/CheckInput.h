#pragma once
#include <cstdlib>

// Класс для проверки корректности ввода
class CheckInput {
public:
    // Проверка корректности целого числа
    static bool checkInt(const char* str, int& value);

    // Проверка корректности числа с плавающей точкой
    static bool checkDouble(const char* str, double& value);
};