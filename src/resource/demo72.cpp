#include "lab72.h"
#include <fstream>  // Для работы с файлами
namespace lab72 {
    void runDemo() {
        FormattedIO format;
        std::cout << "Input [int, float, char, float, int]: ";
        // Ввод данных
        std::cin >> format;

        // Открываем файл для записи
        std::ofstream file("output.txt");

        // Вывод данных в консоль
        std::cout << format;

        // Вывод данных в файл
        if (file.is_open()) {
            file << format;
            file.close();
            std::cout << "Result write to output.txt file" << std::endl;
        }
        else
            std::cerr << "Error when opening output.txt file" << std::endl;
    }
}