#include "lab02.h"
namespace lab02 {
	void runDemo() {
		// ��������� ��������� ������� ��� ������ � ������� ������
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		// ������� ������ �����
		const char* ptrTxtArray[] = {
			"�����",
			"������",
			"�����",
			"����",
			"������",
			"�������� ������"
		};
		int iArraySize{ sizeof(ptrTxtArray) / sizeof(ptrTxtArray[0]) };

		// ������� ������ TextManager ���� ���
		TextManager* ptrManager{ new TextManager(ptrTxtArray, iArraySize) };

		char cUserInput{ '~' };  // ���������� ��� �������� ���������� �������
		while (true) {
			printf("������� ������: ");  // ������ ������������ ������ ������
			scanf_s(" %c", &cUserInput, 1);

			if (cUserInput == '0') break;  // ���� ������������ ���� '0', ������� �� �����

			// ���� ������ � ��������� ��������
			int iFoundCount{ 0 };
			const char** cFoundStrings{ ptrManager->findString(cUserInput, iFoundCount) };

			// ������� ��������� ������
			if (iFoundCount == 0) printf("������ �� �������.\n");
			else {
				printf("��������� ������ � �������� <%c>:\n", cUserInput);
				for (int i = 0; i < iFoundCount; ++i) printf("%s | ptr: %p\n", cFoundStrings[i], cFoundStrings[i]);
			}
		}
		delete ptrManager;
	}
}