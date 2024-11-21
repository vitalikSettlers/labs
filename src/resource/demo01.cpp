#include "lab01.h"
namespace lab01 {
	void runDemo() {
		setlocale(LC_ALL, "Rus");

		int iSize1{ 0 }; int iSize2{ 0 };
		std::cout << "Введите размер первого вектора: "; std::cin >> iSize1;
		std::cout << "Введите размер второго вектора: "; std::cin >> iSize2;

		// Проверка на одинаковый размер векторов
		if (iSize1 != iSize2) {
			std::cerr << "Размеры векторов должны быть одинаковыми для выполнения операций." << "\n";
			exit(1);
		}

		// Создание экземпляров класса VECTOR
		VECTOR v1(iSize1);
		VECTOR v2(iSize2);
		std::cout << "#Вывод двух нулевых векторов" << '\n';
		v1.Print();
		v2.Print();

		// Заполняем первый вектор
		std::cout << "Введите элементы первого вектора: \n";
		for (int i = 0; i < iSize1; i++) {
			float value;
			std::cout << "a(" << i << ") = ";
			std::cin >> value;
			v1.SetValue(i, value);
		}

		// Заполняем второй вектор
		std::cout << "Введите элементы второго вектора: \n";
		for (int i = 0; i < iSize2; i++) {
			float value;
			std::cout << "a(" << i << ") = ";
			std::cin >> value;
			v2.SetValue(i, value);
		}

		// Производим действия
		std::cout << "#Производим действия: " << '\n';

		// Умножаем вектор v1 на скалярное значение 2
		std::cout << "#Результат умножения первого вектора: " << '\n';
		v1 = v1.Cmul(2.f);  // Сохраняем результат умножения
		v1.Print();

		// Вычитаем v2 из v1
		std::cout << "#Результат вычитания второго вектора из первого: " << '\n';
		v1 = v1.Sub(v2);    // Сохраняем результат вычитания
		v1.Print();

		// Вызов конструктора копирования
		VECTOR v3{ v2 };
		v3.Print();
	}
}
