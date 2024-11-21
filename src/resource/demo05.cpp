#include "lab05.h"
namespace lab05 {
	void runDemo() {

		int iSize1{ 0 }, iSize2{ 0 };
		while (true) {
			printf("Enter size for FIRST vector: "); scanf_s("%d", &iSize1);
			printf("Enter size for SECOND vector: "); scanf_s("%d", &iSize2);

			// �������� �� ���������� ������ ��������
			if (iSize1 != iSize2)
				printf("Size of vectors must be EQUAL to perform operations.\n");
			else break;
		}
		// ������� ������� ������ AdvancedVector
		VECTOR v1{ iSize1 };
		VECTOR v2{ iSize2 };

		// ��������� ������ ������
		printf("Enter elements FIRST vector: \n");
		for (int i{ 0 }; i < iSize1; i++) {
			float fValue{ 0 };
			printf("a[%d] = ", i);
			scanf_s("%f", &fValue);
			v1.SetValue(i, fValue);
		}

		// ��������� ������ ������
		printf("Enter elements SECOND vector: \n");
		for (int i{ 0 }; i < iSize2; i++) {
			float fValue{ 0 };
			printf("a[%d] = ", i);
			scanf_s("%f", &fValue);
			v2.SetValue(i, fValue);
		}
		// ������ ������� ��������
		v1.Print();
		v2.Print();

		// ��������� ������� � ������ ������� � �����
		v1.Sub(.5f).Print(true);
		// ��������� ������� ������� �� ������
		v1.Cmul(v2).Print(true);
		// �������� �������� �� ���������
		printf_s("IS ==: %s\n", v1 == v2 ? "true" : "false");
		// ���������� ���������
		(++v1).Print();
		// �������� �������� �� �����������
		printf_s("IS !=: %s\n", v1 != v2 ? "true" : "false");
		// ������������� �������� ��������������
		printf_s("Result array: %f\n", v2[1]);


		// ������������ �� �����������
		VECTOR vCopy{ iSize1 };
		vCopy = static_cast<VECTOR&&>(v1); // ������ ������� v1 �������� � v2, � v1 ������
		vCopy.Print();

		vCopy(42);  // ������������� �������� 42 ��� ������� �������� �������
		vCopy.Print();  // ������ ��������, ��� ������ ������� ������ ����� 42

		vCopy = v2; 
			vCopy.Print();
	}
}

/*
 ����������� ���������: ���c��������, ������������ �� �����������, �������().
*/