#include "lab71.h"
namespace lab71 {
	void runDemo() {
		setlocale(LC_ALL, "Rus");

		int iSize1{ 0 }, iSize2{ 0 };
		std::cout << "Введите размер первого вектора: ";
		std::cin >> iSize1;
		std::cout << "Введите размер второго вектора: ";
		std::cin >> iSize2;

		VECTOR v1(iSize1);
		VECTOR v2(iSize2);

		std::cin >> v1;
		std::cin >> v2;

		std::cout << "Первый вектор:\n" << v1 << std::endl;
		std::cout << "Второй вектор:\n" << v2 << std::endl;

		// Производим действия
		std::cout << "#Производим действия: " << '\n';

		// Умножаем вектор v1 на скалярное значение 2
		std::cout << "#Результат умножения первого вектора: " << '\n';
		VECTOR result = v1.Cmul(2.f); // Результат умножения сохраняется в новый вектор
		result.Print();

		// Производим вычитание v2 из v1
		std::cout << "#Результат вычитания второго вектора из первого: " << '\n';
		VECTOR result2 = v1.Sub(v2); // Сохраняем результат вычитания в новый вектор
		result2.Print(); // Печатаем результат
	}
}