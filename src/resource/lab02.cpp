#include "lab02.h"
namespace lab02 {
    // Конструктор, принимающий массив строк и их размер
    TextManager::TextManager(const char** ptrTxtArray, int iSize)
        : _ptrTxtArray(ptrTxtArray), _iArraySize(iSize) {
        _ptrArray = new const char* [iSize]; // Выделение памяти под массив указателей
    }

    // Метод для поиска строк, содержащих заданный символ
    const char** TextManager::findString(char cLetter, int& foundCount) {
        foundCount = 0;  // Обнуление счетчика найденных строк
        for (int i{ 0 }; i < _iArraySize; ++i) {
            const char* str{ _ptrTxtArray[i] };
            while (*str != '\0') {
                if (*str == cLetter) {
                    _ptrArray[foundCount++] = _ptrTxtArray[i];  // Добавление найденной строки
                    break;
                }
                ++str;
            }
        }
        return _ptrArray;  // Возвращаем массив найденных строк
    }
}