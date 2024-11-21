#include "lab71.h"
namespace lab71 {
	/*1 ������������� ������ ������� � n ������������*/
	VECTOR::VECTOR(int n) {
		if (n > 200) {								// �������� �� ����������� �������.
			std::cerr << "err: ������ ������� ��������� ���������� ����� [200]";
			exit(2);
		}
		this->n = n;								// �������������� ������ �������.
		for (size_t i{ 0 }; i < this->n; i++) {
			this->A[i] = 0.f;						// �������������� ��� �������� �����.
		}
	}

	VECTOR::VECTOR(const VECTOR& other) {
		n = other.n;								// �������� ������
		for (size_t i{ 0 }; i < n; ++i)
			A[i] = other.A[i];						// �������� �������� �������
		std::cout << "! - ������ ����������� �����������\n";
	}

	/* ����� ��� ������� �������� ������� �� ������� */
	void VECTOR::SetValue(int index, float value) {
		if (index >= 0 && index < n)				// ���������, ��������� �� ������ � ���������� ��������
			A[index] = value;						// ����������� �������� �������� ������� �� �������
	}

	/* ����� ��� ��������� ������� ������� �� �������� */
	VECTOR VECTOR::Sub(const VECTOR& what) {
		VECTOR result(this->n); // ������� ��������� ������ ��� �������� ����������
		for (size_t i{ 0 }; i < this->n; i++) // ��������� ������������ ��������� ��������������� ����������� ��������
			result.A[i] = this->A[i] - what.A[i]; // �������� ���������� ��������
		return result;
	}


	/* ����� ��� ��������� ���� ����������� ������� �� �������������� ����� (������) */
	VECTOR VECTOR::Cmul(float fScalar) {
		VECTOR result(this->n);						// ������� ��������� ������ ��� �������� ����������
		for (size_t i{ 0 }; i < this->n; i++)			// ��������� ������������ ��������� ������� ���������� ������� �� ������
			result.A[i] = this->A[i] * fScalar;     // �������� ���������� �� ������
		return result;
	}

	/*12 ����� � ���� �a(i)=� */
	void VECTOR::Print() {
		std::cout << "=========" << "\n";			// std::endl ������� ����� (����� ���� ��������). ������� ������ C++ �������������� ��� ����� ������������ ��������� ��������������
		for (size_t i{ 0 }; i < this->n; i++) std::cout << "a(" << i << ")=" << this->A[i] << "\n";
		std::cout << "=========" << "\n";
	}

	// ���������� ��������� >>
	std::istream& operator>>(std::istream& in, VECTOR& vec) {
		std::cout << "������� " << vec.n << " ���������: ";
		for (size_t i = 0; i < vec.n; ++i) {
			if (!(in >> vec.A[i])) {
				std::cerr << "������: ������� ���������� �����.\n";
				exit(1);
			}
		}
		return in;
	}

	// ���������� ��������� <<
	std::ostream& operator<<(std::ostream& out, const VECTOR& vec) {
		out << "{ ";
		for (size_t i = 0; i < vec.n; ++i) {
			out << vec.A[i];
			if (i < vec.n - 1) out << ", ";
		}
		out << " }";
		return out;
	}
}