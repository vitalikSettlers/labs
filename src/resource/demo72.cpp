#include "lab72.h"
#include <fstream>  // ��� ������ � �������
namespace lab72 {
    void runDemo() {
        FormattedIO format;
        std::cout << "Input [int, float, char, float, int]: ";
        // ���� ������
        std::cin >> format;

        // ��������� ���� ��� ������
        std::ofstream file("output.txt");

        // ����� ������ � �������
        std::cout << format;

        // ����� ������ � ����
        if (file.is_open()) {
            file << format;
            file.close();
            std::cout << "Result write to output.txt file" << std::endl;
        }
        else
            std::cerr << "Error when opening output.txt file" << std::endl;
    }
}