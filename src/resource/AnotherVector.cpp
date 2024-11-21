#include "AnotherVector.h"
#include <cmath>
namespace lab04 {
	// Используем конструктор базового класса
	AnotherVector::AnotherVector(int n) : VECTOR(n) {}

	// Только абсолютные значения
	void AnotherVector::SetValue(int iIndex, float fValue) {
		if (iIndex >= 0 && iIndex < n) {
			A[iIndex] = fabs(fValue); // Сохраняем абсолютное значение
			printf("Element %d set in %f (absolute value)\n", iIndex, A[iIndex]);
		}
	}

	// Переопределение метода вычитания
	VECTOR AnotherVector::Sub(const VECTOR& what) {
		VECTOR result(this->n);
		for (int i = 0; i < this->n; ++i)
			result.SetValue(i, this->getValue(i) - what.getValue(i));
		return result;
	}

	// Переопределение метода умножения на скаляр
	VECTOR AnotherVector::Cmul(float fScalar) {
		VECTOR result(this->n);
		for (int i = 0; i < this->n; ++i)
			result.SetValue(i, this->A[i] * fScalar);
		return result;
	}

	// Вычисление L(беск) норма вектора:
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