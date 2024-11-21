#include <iostream>
#include <limits> // ��� std::numeric_limits
// ���������� ��� ������������ ����
#include "lab01.h"
#include "lab02.h"
#include "lab03.h"
#include "lab04.h"
#include "lab05.h"
#include "lab06.h"
#include "lab71.h"
#include "lab72.h"

int main() {
	setlocale(LC_ALL, "Rus");

	int choice{ 0 };
	while (true) {
		std::cout << "=====[����]=====\n";
		std::cout << "�������� ��������� ��� �������:\n";
		std::cout << "-1. �������� �������\n";
		std::cout << "1. ��������� lab01\n";
		std::cout << "2. ��������� lab02\n";
		std::cout << "3. ��������� lab03\n";
		std::cout << "4. ��������� lab04\n";
		std::cout << "5. ��������� lab05\n";
		std::cout << "6. ��������� lab06\n";
		std::cout << "71. ��������� lab07_1\n";
		std::cout << "72. ��������� lab07_2\n";
		std::cout << "0. �����\n";
		std::cout << "��� �����: ";
		std::cin >> choice;

		switch (choice) {
		case -1:
			system("cls");
			break;
		case 1:
			lab01::runDemo();
			break;
		case 2:
			lab02::runDemo();
			break;
		case 3:
			lab03::runDemo();
			break;
		case 4:
			lab04::runDemo();
			break;
		case 5:
			lab05::runDemo();
			break;
		case 6:
			lab06::runDemo();
			break;
		case 71:
			lab71::runDemo();
			break;
		case 72:
			lab72::runDemo();
			break;
		case 0:
			std::cout << "����� �� ���������.\n";
			return 0;
		default:
			std::cout << "������������ �����. ��������� �������.\n";
		}
	}
}