#pragma once
#include <stdio.h>
namespace lab04 {
	void runDemo();
	class VECTOR {
	protected:
		int n{ 0 };          // Размер вектора
		float* A{ nullptr }; // Указатель на динамический массив

	public:
		VECTOR(int n);               // Конструктор
		VECTOR(const VECTOR& other); // Конструктор копирования
		~VECTOR();                   // Деструктор

		float getValue(int iIndex) const;
		// Установить значение по индексу
		virtual void SetValue(int index, float value);
		// Вычитание
		virtual VECTOR Sub(const VECTOR& what);
		// Умножение на скаляр
		virtual VECTOR Cmul(float fScalar);
		// Печать вектора
		virtual void Print();
		void showVector();

		virtual float Norm();
		float normVector();
	};
}
