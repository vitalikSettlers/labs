#include "lab05.h"
#include <math.h>
namespace lab05 {
	/*1 Инициализация вектора с n компонентами, выделяем динамически память */
	VECTOR::VECTOR(int n) {
		this->_n = n;                                 // Инициализируем размер вектора.
		this->_A = new float[n];                      // Выделяем память под массив
		for (int i = 0; i < this->_n; i++)
			this->_A[i] = 0.f;                        // Инициализируем все элементы нулем.
	}

	/* Конструктор копирования */
	VECTOR::VECTOR(const VECTOR& other) {
		_n = other._n;                                // Копируем размер
		_A = new float[_n];                           // Выделяем память для нового массива
		for (int i = 0; i < _n; ++i)
			_A[i] = other._A[i];                      // Копируем элементы массива
		printf("! - Copy constructor\n");
	}

	/* Деструктор для освобождения динамически выделенной памяти */
	VECTOR::~VECTOR() {
		delete[] _A;  // Освобождаем память
	}

	/* Метод для задания значений вектора по индексу */
	void VECTOR::SetValue(int iIndex, float fValue) {
		if (iIndex >= 0 && iIndex < _n)                // Проверяем, находится ли индекс в допустимых пределах
			_A[iIndex] = fValue;                       // Присваиваем значение элементу вектора по индексу
	}

	void VECTOR::SetValue() {
		printf("Setter must accept two parameters\n");
	}

	/* Метод для вычитания другого вектора из текущего */
	VECTOR VECTOR::Sub(const VECTOR& what) {
		VECTOR result(this->_n);                     // Создаем временный вектор для хранения результата
		for (int i{ 0 }; i < this->_n; i++)          // Выполняем поэлементное вычитание соответствующих компонентов векторов
			result._A[i] = this->_A[i] - what._A[i];   // Вычитаем компоненты векторов
		return result;
	}

	VECTOR VECTOR::Sub(float fScalar) {
		VECTOR result(this->_n);                     // Создаем временный вектор для хранения результата
		for (int i{ 0 }; i < this->_n; i++)          //  Выполняем вычитание скаляра из каждого элемента вектора
			result._A[i] = this->_A[i] - fScalar;
		return result;
	}

	/* Метод для умножения всех компонентов вектора на скаляр */
	VECTOR VECTOR::Cmul(float fScalar) {
		VECTOR result(this->_n);                     // Создаем временный вектор для хранения результата
		for (int i{ 0 }; i < this->_n; i++)          // Выполняем поэлементное умножение каждого компонента вектора на скаляр
			result._A[i] = this->_A[i] * fScalar;     // Умножаем компоненту на скаляр
		return result;
	}

	VECTOR VECTOR::Cmul(const VECTOR& vec) {
		VECTOR result(this->_n);                     // Создаем временный вектор для хранения результата
		for (int i{ 0 }; i < this->_n; i++)           // Выполняем поэлементное умножение каждого компонента вектора на скаляр
			result._A[i] = this->_A[i] * vec._A[i];    // Умножаем компоненту на скаляр
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

	/*12 Вывод в виде “a(i)=” */
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
		// Проверка на самоприсваивание
		if (this == &other)
			return *this;
		// Освобождаем старую память, если она есть
		delete[] this->_A;

		// Выделяем новую память и копируем данные
		this->_n = other._n;
		this->_A = new float[other._n];
		for (int i = 0; i < other._n; i++)
			this->_A[i] = other._A[i];

		return *this; // Возвращаем ссылку на текущий объект
	}

	void VECTOR::operator()(int iNewValue)
	{
		*_A = iNewValue;
	}
}