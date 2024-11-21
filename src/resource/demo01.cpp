#include "lab01.h"
namespace lab01 {
	void runDemo() {
		setlocale(LC_ALL, "Rus");

		int iSize1{ 0 }; int iSize2{ 0 };
		std::cout << "������� ������ ������� �������: "; std::cin >> iSize1;
		std::cout << "������� ������ ������� �������: "; std::cin >> iSize2;

		// �������� �� ���������� ������ ��������
		if (iSize1 != iSize2) {
			std::cerr << "������� �������� ������ ���� ����������� ��� ���������� ��������." << "\n";
			exit(1);
		}

		// �������� ����������� ������ VECTOR
		VECTOR v1(iSize1);
		VECTOR v2(iSize2);
		std::cout << "#����� ���� ������� ��������" << '\n';
		v1.Print();
		v2.Print();

		// ��������� ������ ������
		std::cout << "������� �������� ������� �������: \n";
		for (int i = 0; i < iSize1; i++) {
			float value;
			std::cout << "a(" << i << ") = ";
			std::cin >> value;
			v1.SetValue(i, value);
		}

		// ��������� ������ ������
		std::cout << "������� �������� ������� �������: \n";
		for (int i = 0; i < iSize2; i++) {
			float value;
			std::cout << "a(" << i << ") = ";
			std::cin >> value;
			v2.SetValue(i, value);
		}

		// ���������� ��������
		std::cout << "#���������� ��������: " << '\n';

		// �������� ������ v1 �� ��������� �������� 2
		std::cout << "#��������� ��������� ������� �������: " << '\n';
		v1 = v1.Cmul(2.f);  // ��������� ��������� ���������
		v1.Print();

		// �������� v2 �� v1
		std::cout << "#��������� ��������� ������� ������� �� �������: " << '\n';
		v1 = v1.Sub(v2);    // ��������� ��������� ���������
		v1.Print();

		// ����� ������������ �����������
		VECTOR v3{ v2 };
		v3.Print();
	}
}
