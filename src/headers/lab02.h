#pragma once
#include <cstdio>
#include <windows.h>
namespace lab02 {
	void runDemo();
	class TextManager {
	private:
		const char** _ptrTxtArray;  // Массив указателей на строки
		const char** _ptrArray;     // Массив указателей на строки с найденным символом
		int _iArraySize{ 0 };       // Размер массива строк

	public:
		// Конструктор, принимающий массив строк и их размер
		TextManager(const char** ptrTxtArray, int iSize);

		// Метод для поиска строк, содержащих заданный символ
		const char** findString(char cLetter, int& foundCount);
	};
}