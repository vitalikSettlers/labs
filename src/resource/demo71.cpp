#include "lab71.h"
namespace lab71 {
	void runDemo() {
		setlocale(LC_ALL, "Rus");

		int iSize1{ 0 }, iSize2{ 0 };
		std::cout << "������� ������ ������� �������: ";
		std::cin >> iSize1;
		std::cout << "������� ������ ������� �������: ";
		std::cin >> iSize2;

		VECTOR v1(iSize1);
		VECTOR v2(iSize2);

		std::cin >> v1;
		std::cin >> v2;

		std::cout << "������ ������:\n" << v1 << std::endl;
		std::cout << "������ ������:\n" << v2 << std::endl;

		// ���������� ��������
		std::cout << "#���������� ��������: " << '\n';

		// �������� ������ v1 �� ��������� �������� 2
		std::cout << "#��������� ��������� ������� �������: " << '\n';
		VECTOR result = v1.Cmul(2.f); // ��������� ��������� ����������� � ����� ������
		result.Print();

		// ���������� ��������� v2 �� v1
		std::cout << "#��������� ��������� ������� ������� �� �������: " << '\n';
		VECTOR result2 = v1.Sub(v2); // ��������� ��������� ��������� � ����� ������
		result2.Print(); // �������� ���������
	}
}