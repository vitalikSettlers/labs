#pragma once
#include <cstdio>

namespace lab03 {
	void runDemo();
	class Dispersion {
	private:
		double* _ptrNumbers;    // Динамический массив для хранения чисел
		int _iCount;            // Количество чисел введенных пользователем

	public:
		// Конструктор для инициализации массива и чтения данных через список
		Dispersion(int iSize, double* ptrNumbers);
		~Dispersion();
		// Вычисление среднего арифметического
		double calculateMean();
		// Вычисление дисперсии
		double calculateVariance();
	};
}