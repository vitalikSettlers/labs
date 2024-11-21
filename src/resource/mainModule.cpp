#include <iostream>
#include <limits> // Для std::numeric_limits
// Подключаем все пространства имен
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
		std::cout << "=====[МЕНЮ]=====\n";
		std::cout << "Выберите программу для запуска:\n";
		std::cout << "-1. Очистить консоль\n";
		std::cout << "1. Программа lab01\n";
		std::cout << "2. Программа lab02\n";
		std::cout << "3. Программа lab03\n";
		std::cout << "4. Программа lab04\n";
		std::cout << "5. Программа lab05\n";
		std::cout << "6. Программа lab06\n";
		std::cout << "71. Программа lab07_1\n";
		std::cout << "72. Программа lab07_2\n";
		std::cout << "0. Выход\n";
		std::cout << "Ваш выбор: ";
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
			std::cout << "Выход из программы.\n";
			return 0;
		default:
			std::cout << "Некорректный выбор. Повторите попытку.\n";
		}
	}
}