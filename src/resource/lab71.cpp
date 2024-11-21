#include "lab71.h"
namespace lab71 {
	/*1 Инициализация нулями вектора с n компонентами*/
	VECTOR::VECTOR(int n) {
		if (n > 200) {								// Проверка на размерность вектора.
			std::cerr << "err: Размер вектора превышает допустимый лимит [200]";
			exit(2);
		}
		this->n = n;								// Инициализируем размер вектора.
		for (size_t i{ 0 }; i < this->n; i++) {
			this->A[i] = 0.f;						// Инициализируем все элементы нулем.
		}
	}

	VECTOR::VECTOR(const VECTOR& other) {
		n = other.n;								// Копируем размер
		for (size_t i{ 0 }; i < n; ++i)
			A[i] = other.A[i];						// Копируем элементы массива
		std::cout << "! - Вызван конструктор копирования\n";
	}

	/* Метод для задания значений вектора по индексу */
	void VECTOR::SetValue(int index, float value) {
		if (index >= 0 && index < n)				// Проверяем, находится ли индекс в допустимых пределах
			A[index] = value;						// Присваиваем значение элементу вектора по индексу
	}

	/* Метод для вычитания другого вектора из текущего */
	VECTOR VECTOR::Sub(const VECTOR& what) {
		VECTOR result(this->n); // Создаем временный вектор для хранения результата
		for (size_t i{ 0 }; i < this->n; i++) // Выполняем поэлементное вычитание соответствующих компонентов векторов
			result.A[i] = this->A[i] - what.A[i]; // Вычитаем компоненты векторов
		return result;
	}


	/* Метод для умножения всех компонентов вектора на действительное число (скаляр) */
	VECTOR VECTOR::Cmul(float fScalar) {
		VECTOR result(this->n);						// Создаем временный вектор для хранения результата
		for (size_t i{ 0 }; i < this->n; i++)			// Выполняем поэлементное умножение каждого компонента вектора на скаляр
			result.A[i] = this->A[i] * fScalar;     // Умножаем компоненту на скаляр
		return result;
	}

	/*12 Вывод в виде “a(i)=” */
	void VECTOR::Print() {
		std::cout << "=========" << "\n";			// std::endl очищает буфер (может быть медленно). Система вывода C++ спроектирована так чтобы переодически очищаться самостоятельно
		for (size_t i{ 0 }; i < this->n; i++) std::cout << "a(" << i << ")=" << this->A[i] << "\n";
		std::cout << "=========" << "\n";
	}

	// Перегрузка оператора >>
	std::istream& operator>>(std::istream& in, VECTOR& vec) {
		std::cout << "Введите " << vec.n << " элементов: ";
		for (size_t i = 0; i < vec.n; ++i) {
			if (!(in >> vec.A[i])) {
				std::cerr << "Ошибка: введите корректные числа.\n";
				exit(1);
			}
		}
		return in;
	}

	// Перегрузка оператора <<
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