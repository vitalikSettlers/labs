#include "lab05.h"
#include <math.h>
namespace lab05 {
	/*1 ������������� ������� � n ������������, �������� ����������� ������ */
	VECTOR::VECTOR(int n) {
		this->_n = n;                                 // �������������� ������ �������.
		this->_A = new float[n];                      // �������� ������ ��� ������
		for (int i = 0; i < this->_n; i++)
			this->_A[i] = 0.f;                        // �������������� ��� �������� �����.
	}

	/* ����������� ����������� */
	VECTOR::VECTOR(const VECTOR& other) {
		_n = other._n;                                // �������� ������
		_A = new float[_n];                           // �������� ������ ��� ������ �������
		for (int i = 0; i < _n; ++i)
			_A[i] = other._A[i];                      // �������� �������� �������
		printf("! - Copy constructor\n");
	}

	/* ���������� ��� ������������ ����������� ���������� ������ */
	VECTOR::~VECTOR() {
		delete[] _A;  // ����������� ������
	}

	/* ����� ��� ������� �������� ������� �� ������� */
	void VECTOR::SetValue(int iIndex, float fValue) {
		if (iIndex >= 0 && iIndex < _n)                // ���������, ��������� �� ������ � ���������� ��������
			_A[iIndex] = fValue;                       // ����������� �������� �������� ������� �� �������
	}

	void VECTOR::SetValue() {
		printf("Setter must accept two parameters\n");
	}

	/* ����� ��� ��������� ������� ������� �� �������� */
	VECTOR VECTOR::Sub(const VECTOR& what) {
		VECTOR result(this->_n);                     // ������� ��������� ������ ��� �������� ����������
		for (int i{ 0 }; i < this->_n; i++)          // ��������� ������������ ��������� ��������������� ����������� ��������
			result._A[i] = this->_A[i] - what._A[i];   // �������� ���������� ��������
		return result;
	}

	VECTOR VECTOR::Sub(float fScalar) {
		VECTOR result(this->_n);                     // ������� ��������� ������ ��� �������� ����������
		for (int i{ 0 }; i < this->_n; i++)          //  ��������� ��������� ������� �� ������� �������� �������
			result._A[i] = this->_A[i] - fScalar;
		return result;
	}

	/* ����� ��� ��������� ���� ����������� ������� �� ������ */
	VECTOR VECTOR::Cmul(float fScalar) {
		VECTOR result(this->_n);                     // ������� ��������� ������ ��� �������� ����������
		for (int i{ 0 }; i < this->_n; i++)          // ��������� ������������ ��������� ������� ���������� ������� �� ������
			result._A[i] = this->_A[i] * fScalar;     // �������� ���������� �� ������
		return result;
	}

	VECTOR VECTOR::Cmul(const VECTOR& vec) {
		VECTOR result(this->_n);                     // ������� ��������� ������ ��� �������� ����������
		for (int i{ 0 }; i < this->_n; i++)           // ��������� ������������ ��������� ������� ���������� ������� �� ������
			result._A[i] = this->_A[i] * vec._A[i];    // �������� ���������� �� ������
		return result;
	}

	VECTOR& VECTOR::operator++() {
		for (int i{ 0 }; i < this->_n; i++)
			this->_A[i]++;
		return *this;
	}

	bool VECTOR::operator==(const VECTOR& other) {
		if (this->_n != other._n) return false;
		for (int i{ 0 }; i < this->_n; i++)
			if (this->_A[i] != other._A[i]) return false;
		return true;
	}

	bool VECTOR::operator!=(const VECTOR& other) {
		if (this->_n != other._n) return false;
		for (int i{ 0 }; i < this->_n; i++)
			if (this->_A[i] == other._A[i]) return false;
		return true;
	}

	float& VECTOR::operator[](int iIndex) {
		if (iIndex < 0 || iIndex >= this->_n) {
			throw printf_s("#Not find element#");
		}
		return this->_A[iIndex];
	}

	/*12 ����� � ���� �a(i)=� */
	void VECTOR::Print() {
		printf("=========\n");
		for (int i{ 0 }; i < this->_n; i++) printf("a(%d) = %f\n", i, this->_A[i]);
		printf("=========\n");
	}

	void VECTOR::Print(bool bNewDesignOutput) {
		if (bNewDesignOutput) {
			const char* ptrReset{ "\033[0m" };
			const char* ptrHeaderColor{ "\033[1;34m" };
			const char* ptrLineColor{ "\033[1;32m" };

			printf("%s=============================================\n", ptrLineColor);
			printf("|%s               VECTOR CONTENTS             %s|\n", ptrHeaderColor, ptrLineColor);
			printf("=============================================%s\n", ptrReset);
			printf("|    Index    |          Value              |\n");
			printf("---------------------------------------------\n");
			for (int i = 0; i < this->_n; i++)
				printf("|    %5d    |    %20.6f    |\n", i, this->_A[i]);
			printf("=============================================\n");
			return;
		}

		printf("======== VECTOR CONTENTS ========\n");
		for (int i{ 0 }; i < this->_n; i++)
			printf("| Index: %d | Value: %f |\n", i, this->_A[i]);
		printf("==================================\n");
	}

	VECTOR& VECTOR::operator=(VECTOR&& other) noexcept {
		if (this != &other) {
			delete[] _A;
			_A = other._A;
			_n = other._n;

			other._A = nullptr;
			other._n = 0;
		}
		return *this;
	}

	VECTOR& VECTOR::operator=(const VECTOR& other) {
		// �������� �� ����������������
		if (this == &other)
			return *this;
		// ����������� ������ ������, ���� ��� ����
		delete[] this->_A;

		// �������� ����� ������ � �������� ������
		this->_n = other._n;
		this->_A = new float[other._n];
		for (int i = 0; i < other._n; i++)
			this->_A[i] = other._A[i];

		return *this; // ���������� ������ �� ������� ������
	}

	void VECTOR::operator()(int iNewValue)
	{
		*_A = iNewValue;
	}
}