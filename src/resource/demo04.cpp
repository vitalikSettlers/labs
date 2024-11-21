#include "lab04.h"
#include "AnotherVector.h"
namespace lab04 {
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
		VECTOR* v1{ new AnotherVector(iSize1) };
		VECTOR* v2{ new AnotherVector(iSize2) };

		printf("#Output of two zero vectors\n");
		v1->showVector();
		v2->showVector();

		// ��������� ������ ������
		printf("Enter elements FIRST vector: \n");
		for (int i{ 0 }; i < iSize1; i++) {
			float fValue{ 0 };
			printf("a[%d] = ", i);
			scanf_s("%f", &fValue);
			v1->SetValue(i, fValue);
		}

		// ��������� ������ ������
		printf("Enter elements SECOND vector: \n");
		for (int i{ 0 }; i < iSize2; i++) {
			float fValue{ 0 };
			printf("a[%d] = ", i);
			scanf_s("%f", &fValue);
			v2->SetValue(i, fValue);
		}

		// �������� ��� ���������
		printf("#Take action:\n");
		printf("FIRST vector:\n"); v1->showVector();
		printf("SECOND vector:\n"); v2->showVector();

		// ������������ ������ Norm
		if (AnotherVector * ptrAv{ dynamic_cast<AnotherVector*>(v1) })
			printf("Length FIRST vector: %.2f\n", ptrAv->normVector());
		else printf("Cast failed\n");

		if (AnotherVector * ptrAv{ dynamic_cast<AnotherVector*>(v2) })
			printf("Length SECOND vector: %.2f\n", ptrAv->normVector());
		else printf("Cast failed\n");

		// ������������ ������ Sub (��������� ������� ������� �� �������)
		VECTOR* vSub{ new VECTOR(v1->Sub(*v2)) };
		printf("Subtraction (FIRST - SECOND):\n");
		vSub->showVector();

		// ������������ ������ Cmul (��������� ������� ������� �� ������)
		VECTOR* vCmul{ new VECTOR(v1->Cmul(2.f)) };
		printf("Multiplication FIRST vector by scalar\n");
		vCmul->showVector();
	}
}
/*
static_cast
������������ ��� ���������� ������ ���� � ������� �� ����� ����������, ���� ���������� ����� ��������� ������������ ����������.
����� �������, ��� ���������� ���������, � ��� ������������� � �������� �� ����� ����������.

dynamic_cast
������������ ��� ����������� ���������� ����� ��� ������� ������������ (����� � ������� ���� ����������� �������).
����� ���� ���������, ��� ���������� ������������� ��������� (��� ������ � ������������� � �������������).
*/