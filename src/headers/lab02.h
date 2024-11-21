#pragma once
#include <cstdio>
#include <windows.h>
namespace lab02 {
	void runDemo();
	class TextManager {
	private:
		const char** _ptrTxtArray;  // ������ ���������� �� ������
		const char** _ptrArray;     // ������ ���������� �� ������ � ��������� ��������
		int _iArraySize{ 0 };       // ������ ������� �����

	public:
		// �����������, ����������� ������ ����� � �� ������
		TextManager(const char** ptrTxtArray, int iSize);

		// ����� ��� ������ �����, ���������� �������� ������
		const char** findString(char cLetter, int& foundCount);
	};
}