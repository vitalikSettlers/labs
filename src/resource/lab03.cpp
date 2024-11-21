#include "lab03.h"
namespace lab03 {
	// Конструктор для инициализации указателя на переданный массив
	Dispersion::Dispersion(int iSize, double* ptrNumbers) : _iCount(iSize), _ptrNumbers(ptrNumbers) {}

	Dispersion::~Dispersion() {					// Сработает после завершения программы
		delete[] _ptrNumbers;
	}

	// Вычисление среднего арифметического
	double Dispersion::calculateMean() {
		double sum = 0;
		for (int i = 0; i < _iCount; ++i) sum += _ptrNumbers[i];
		return sum / _iCount;					// Возвращаем среднее
	}

	// Вычисление дисперсии
	double Dispersion::calculateVariance() {
		double dMean{ calculateMean() };
		double dVariance{ 0 };
		for (int i = 0; i < _iCount; ++i) dVariance += (_ptrNumbers[i] - dMean) * (_ptrNumbers[i] - dMean);
		return dVariance / (_iCount - 1);		// Используем формулу для выборочной дисперсии
	}
}