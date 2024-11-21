#include "lab02.h"
namespace lab02 {
    // �����������, ����������� ������ ����� � �� ������
    TextManager::TextManager(const char** ptrTxtArray, int iSize)
        : _ptrTxtArray(ptrTxtArray), _iArraySize(iSize) {
        _ptrArray = new const char* [iSize]; // ��������� ������ ��� ������ ����������
    }

    // ����� ��� ������ �����, ���������� �������� ������
    const char** TextManager::findString(char cLetter, int& foundCount) {
        foundCount = 0;  // ��������� �������� ��������� �����
        for (int i{ 0 }; i < _iArraySize; ++i) {
            const char* str{ _ptrTxtArray[i] };
            while (*str != '\0') {
                if (*str == cLetter) {
                    _ptrArray[foundCount++] = _ptrTxtArray[i];  // ���������� ��������� ������
                    break;
                }
                ++str;
            }
        }
        return _ptrArray;  // ���������� ������ ��������� �����
    }
}