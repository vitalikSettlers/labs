#include "AnotherVector.h"
#include <cmath>
namespace lab04 {
	// ���������� ����������� �������� ������
	AnotherVector::AnotherVector(int n) : VECTOR(n) {}

	// ������ ���������� ��������
	void AnotherVector::SetValue(int iIndex, float fValue) {
		if (iIndex >= 0 && iIndex < n) {
			A[iIndex] = fabs(fValue); // ��������� ���������� ��������
			printf("Element %d set in %f (absolute value)\n", iIndex, A[iIndex]);
		}
	}

	// ��������������� ������ ���������
	VECTOR AnotherVector::Sub(const VECTOR& what) {
		VECTOR result(this->n);
		for (int i = 0; i < this->n; ++i)
			result.SetValue(i, this->getValue(i) - what.getValue(i));
		return result;
	}

	// ��������������� ������ ��������� �� ������
	VECTOR AnotherVector::Cmul(float fScalar) {
		VECTOR result(this->n);
		for (int i = 0; i < this->n; ++i)
			result.SetValue(i, this->A[i] * fScalar);
		return result;
	}

	// ���������� L(����) ����� �������:
	float AnotherVector::Norm() {
		float maxVal{ 0.f };
		for (int i{ 0 }; i < this->n; i++) {
			if (fabs(this->A[i]) > maxVal)
				maxVal = fabs(this->A[i]);
		}
		return maxVal;
	}

	void AnotherVector::Print() {
		printf("======== VECTOR CONTENTS ========\n");
		for (int i = 0; i < this->n; i++)
			printf("| Index: %d | Value: %f |\n", i, this->A[i]);
		printf("==================================\n");
	}
}