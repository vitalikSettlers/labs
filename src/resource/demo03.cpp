#include "lab03.h"
#include "CheckInput.h"

#include <iostream>
namespace lab03 {
    // ������� ��� ����� ������
    void inputNumbers(int& iSize, double*& numbers) {
        // ������� ���������� ����, ����� �������� ��������� ������
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        char buffer[100];

        // ���� ���������� ��������� � ���������
        for (;;) {
            printf("Enter element count: ");
            if (fgets(buffer, sizeof(buffer), stdin) != nullptr) {
                // ���������, ��������� �� ����, � ������ �� ��������� �������� 1
                if (CheckInput::checkInt(buffer, iSize) && iSize > 1) {
                    break;
                }
            }
            printf("Invalid input. Enter a valid integer greater than 1.\n");
        }

        // ������������ ��������� ������ ��� �������
        numbers = new double[iSize];

        // ���� ������� �������� ������� � ���������
        for (int i = 0; i < iSize; ++i) {
            for (;;) {
                printf("Enter element %d: ", i + 1);
                if (fgets(buffer, sizeof(buffer), stdin) != nullptr) {
                    if (CheckInput::checkDouble(buffer, numbers[i])) {
                        break; // ���� ���� ���������, ������� �� �����
                    }
                }
                // ������� ���������� ����
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                printf("Invalid input. Enter a valid double.\n");
            }
        }
    }

    void runDemo() {
        int iSize{ 0 };
        double* numbers{ nullptr };

        // �������� ������� ��� ����� ������
        inputNumbers(iSize, numbers);

        // �������� ������ � �����������
        Dispersion set(iSize, numbers);

        // ��������� ���������
        printf("Answer: %.6lf\n", set.calculateVariance());
    }
}
