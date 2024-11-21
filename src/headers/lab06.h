#pragma once
#include <cstdio>
namespace lab06 {
	void runDemo();
	// Шаблон класса, позволяющий использовать любой тип данных для элементов массива
	template <typename T>
	class smartArray {
	private:
		T* _tArray; // Указатель на динамический массив элементов типа T
		size_t _sSize; // Переменная для хранения размера массива
	public:
		smartArray(T* tInputArr, int iSize);
		~smartArray();
		// Метод для поиска последовательности
		int findSequence(T* tSequence, int iSeqSize) const;
	};

	template <typename T>
	smartArray<T>::smartArray(T* tInputArr, int iSize) : _sSize(iSize) {
		_tArray = new T[_sSize];
		// Копируем каждый элемент входного массива в новый массив
		for (size_t i{ 0 }; i < _sSize; ++i) _tArray[i] = tInputArr[i];
	}

	template <typename T>
	smartArray<T>::~smartArray() {
		delete[] _tArray;
	}

	// Метод для поиска последовательности
	template <typename T>
	int smartArray<T>::findSequence(T* tSequence, int iSeqSize) const {
		// Проходим по _tArray, оставляя место для сравнения последовательности
		for (size_t i{ 0 }; i <= _sSize - iSeqSize; ++i) {
			bool bFound{ true };
			// Цикл для проверки каждого элемента последовательности
			for (size_t j{ 0 }; j < iSeqSize; ++j) {
				// Сравниваем элемент из _tArray с соответствующим элементом tSequence
				if (_tArray[i + j] != tSequence[j])
					bFound = false; break;
			}
			if (bFound) return static_cast<int>(i); // Последовательность найдена
		}
		return -1; // Последовательность не найдена
	}
}