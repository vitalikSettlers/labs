#include "lab02.h"
namespace lab02 {
	void runDemo() {
		// Настройка кодировки консоли для работы с русским языком
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		// Создаем массив строк
		const char* ptrTxtArray[] = {
			"Борис",
			"Привет",
			"Батон",
			"Хлеб",
			"Быстро",
			"Тестовая строка"
		};
		int iArraySize{ sizeof(ptrTxtArray) / sizeof(ptrTxtArray[0]) };

		// Создаем объект TextManager один раз
		TextManager* ptrManager{ new TextManager(ptrTxtArray, iArraySize) };

		char cUserInput{ '~' };  // Переменная для хранения введенного символа
		while (true) {
			printf("Введите символ: ");  // Просим пользователя ввести символ
			scanf_s(" %c", &cUserInput, 1);

			if (cUserInput == '0') break;  // Если пользователь ввел '0', выходим из цикла

			// Ищем строки с введенным символом
			int iFoundCount{ 0 };
			const char** cFoundStrings{ ptrManager->findString(cUserInput, iFoundCount) };

			// Выводим найденные строки
			if (iFoundCount == 0) printf("Ничего не найдено.\n");
			else {
				printf("Найденные строки с символом <%c>:\n", cUserInput);
				for (int i = 0; i < iFoundCount; ++i) printf("%s | ptr: %p\n", cFoundStrings[i], cFoundStrings[i]);
			}
		}
		delete ptrManager;
	}
}