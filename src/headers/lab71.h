#pragma once
#include <iostream>
namespace lab71 {
	void runDemo();
	class VECTOR {
	private:
		int n{ 0 };
		float A[200];

	public:
		/*1 ������������� ������ ������� � n ������������*/
		VECTOR(int n);

		VECTOR(const VECTOR& other);

		/* ����� ��� ������� �������� ������� (��� ������������) */
		void SetValue(int index, float value);

		/*7 ���������*/
		VECTOR Sub(const VECTOR& what);

		/*9 ��������� �� �������������� ����� */
		VECTOR Cmul(float fScalar);

		/*12 ����� � ���� �a(i)=� */
		void Print();

		// ���������� ���������� ����� � ������
		friend std::istream& operator>>(std::istream& in, VECTOR& vec);
		friend std::ostream& operator<<(std::ostream& out, const VECTOR& vec);
	};
}