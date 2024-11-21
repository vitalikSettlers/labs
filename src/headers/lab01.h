#pragma once
#include <iostream>
namespace lab01 {
	void runDemo();
	class VECTOR {
	private:
		int n{ 0 };
		float A[200];

	public:
		/*1 Инициализация нулями вектора с n компонентами*/
		VECTOR(int n);

		VECTOR(const VECTOR& other);

		/* Метод для задания значений вектора (для тестирования) */
		void SetValue(int index, float value);

		/*7 Вычитание*/
		VECTOR Sub(const VECTOR& what);

		/*9 Умножение на действительное число */
		VECTOR Cmul(float fScalar);

		/*12 Вывод в виде “a(i)=” */
		void Print();
	};
}