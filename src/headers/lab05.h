#pragma once
#include <stdio.h>
namespace lab05 {
	void runDemo();
	class VECTOR {
	protected:
		int _n{ 0 };          // Размер вектора
		float* _A{ nullptr }; // Указатель на динамический массив

	public:
		VECTOR(int n);               // Конструктор
		VECTOR(const VECTOR& other); // Конструктор копирования
		VECTOR() = delete;           // Нельзя использовать конструктор по умолчанию
		~VECTOR();                   // Деструктор

		// Установить значение по индексу
		void SetValue(int index, float value);
		void SetValue();
		// Вычитание
		VECTOR Sub(const VECTOR& what);
		VECTOR Sub(float fScalar);
		// Умножение на скаляр
		VECTOR Cmul(float fScalar);
		VECTOR Cmul(const VECTOR& vec);
		// Печать вектора
		void Print();
		void Print(bool bNewDesignOutput);

		// Перегрузка префиксного инкремента
		VECTOR& operator++();
		// Перегрузка операторов равенства
		bool operator==(const VECTOR& other);
		bool operator!=(const VECTOR& other);
		// Перегрузка оператора индексирования
		float& operator[](int iIndex);

		// Доп.
		VECTOR& operator=(const VECTOR& other);
		VECTOR& operator=(VECTOR&& other) noexcept;
		void operator()(int iNewValue);
	};
}