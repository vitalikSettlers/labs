#include "lab05.h"
namespace lab05 {
	void runDemo() {

		int iSize1{ 0 }, iSize2{ 0 };
		while (true) {
			printf("Enter size for FIRST vector: "); scanf_s("%d", &iSize1);
			printf("Enter size for SECOND vector: "); scanf_s("%d", &iSize2);

			// Проверка на одинаковый размер векторов
			if (iSize1 != iSize2)
				printf("Size of vectors must be EQUAL to perform operations.\n");
			else break;
		}
		// Создаем объекты класса AdvancedVector
		VECTOR v1{ iSize1 };
		VECTOR v2{ iSize2 };

		// Заполняем первый вектор
		printf("Enter elements FIRST vector: \n");
		for (int i{ 0 }; i < iSize1; i++) {
			float fValue{ 0 };
			printf("a[%d] = ", i);
			scanf_s("%f", &fValue);
			v1.SetValue(i, fValue);
		}

		// Заполняем второй вектор
		printf("Enter elements SECOND vector: \n");
		for (int i{ 0 }; i < iSize2; i++) {
			float fValue{ 0 };
			printf("a[%d] = ", i);
			scanf_s("%f", &fValue);
			v2.SetValue(i, fValue);
		}
		// Печать нулевых значений
		v1.Print();
		v2.Print();

		// Вычитание скаляра в первом векторе и вывод
		v1.Sub(.5f).Print(true);
		// Умножение первого вектора на второй
		v1.Cmul(v2).Print(true);
		// Проверка векторов на равенство
		printf_s("IS ==: %s\n", v1 == v2 ? "true" : "false");
		// Префиксный инкремент
		(++v1).Print();
		// Проверка векторов на неравенство
		printf_s("IS !=: %s\n", v1 != v2 ? "true" : "false");
		// Перегруженный оператор индексирования
		printf_s("Result array: %f\n", v2[1]);


		// Присваивание по перемещению
		VECTOR vCopy{ iSize1 };
		vCopy = static_cast<VECTOR&&>(v1); // Теперь ресурсы v1 переданы в v2, а v1 очищен
		vCopy.Print();

		vCopy(42);  // Устанавливаем значение 42 для первого элемента вектора
		vCopy.Print();  // Должен показать, что первый элемент теперь равен 42

		vCopy = v2; 
			vCopy.Print();
	}
}

/*
 Перегрузить операторы: приcваивания, присваивания по перемещению, функтор().
*/