#include "lab03.h"
#include "CheckInput.h"

#include <iostream>
namespace lab03 {
    // Функция для ввода данных
    void inputNumbers(int& iSize, double*& numbers) {
        // Очищаем оставшийся ввод, чтобы избежать повторных ошибок
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        char buffer[100];

        // Ввод количества элементов с проверкой
        for (;;) {
            printf("Enter element count: ");
            if (fgets(buffer, sizeof(buffer), stdin) != nullptr) {
                // Проверяем, корректен ли ввод, и больше ли введенное значение 1
                if (CheckInput::checkInt(buffer, iSize) && iSize > 1) {
                    break;
                }
            }
            printf("Invalid input. Enter a valid integer greater than 1.\n");
        }

        // Динамическое выделение памяти для массива
        numbers = new double[iSize];

        // Ввод каждого элемента массива с проверкой
        for (int i = 0; i < iSize; ++i) {
            for (;;) {
                printf("Enter element %d: ", i + 1);
                if (fgets(buffer, sizeof(buffer), stdin) != nullptr) {
                    if (CheckInput::checkDouble(buffer, numbers[i])) {
                        break; // Если ввод корректен, выходим из цикла
                    }
                }
                // Очищаем оставшийся ввод
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                printf("Invalid input. Enter a valid double.\n");
            }
        }
    }

    void runDemo() {
        int iSize{ 0 };
        double* numbers{ nullptr };

        // Вызываем функцию для ввода данных
        inputNumbers(iSize, numbers);

        // Передаем массив в конструктор
        Dispersion set(iSize, numbers);

        // Вычисляем дисперсию
        printf("Answer: %.6lf\n", set.calculateVariance());
    }
}
