#include "lab06.h"
namespace lab06 {
	template <typename T>
	T calculateSum(const T* array, int size) {
		T sum{ 0 };
		for (size_t sI{ 0 }; sI < size; ++sI)
			sum += array[sI];
		return sum;
	}

	template <typename T>
	void findAndPrintSequence(T* elements, int size, T* sequence, int seqSize, const char* elementType, const char* sequenceStr) {
		smartArray<T> array(elements, size);
		int position{ array.findSequence(sequence, seqSize) };

		printf("+---------------------------------------------------+\n");
		printf("|       * Searching for a %s sequence *       |\n", elementType);
		printf("+---------------------------------------------------+\n");
		if (position != -1) {
			printf("|            Found the sequence %s!            |\n", sequenceStr);
			printf("|              Position in the array: %d             |\n", position);
		}
		else
			printf("|           Sequence %s not found            |\n", sequenceStr);
		printf("+---------------------------------------------------+\n");
	}

	void runDemo() {
		const int iSize{ 7 };

		int iArrayElements[iSize]{ 0, 1, 2, 4, 3, 5, 6 };
		int iSequenceInt[]{ 2, 4, 3 };
		findAndPrintSequence(iArrayElements, iSize, iSequenceInt, 3, "integer", "2, 4, 3");

		char cArrayElements[iSize]{ 'A', 'B', 'C', 'D', 'D', 'F' };
		char cSequenceChar[]{ 'D', 'D', 'F' };
		findAndPrintSequence(cArrayElements, iSize, cSequenceChar, 3, "character", "D, D, F");

		float fArrayElements[iSize]{ 1.f, 2.f, 3.f, 4.f, 5.f, 6.f };
		float fSequenceFloat[]{ 4.f, 5.f, 6.f };
		findAndPrintSequence(fArrayElements, iSize, fSequenceFloat, 3, "decimal", "4.f, 5.f, 6.f");

		printf("Sum of integer elements: %d\n", calculateSum(iArrayElements, iSize));
	}
}
// 1. Т.к. std::set это коллекция и она хранит все по порядку, то нужно перегрузить оператор функтор () или оператор сравнения <.
// 2. size_t нужен для хранения и индексов. Внутри это беззнаковое целое число точно гарантирует, что не будет отрицательных значений, и размер будет подходить под архитектуру пк.
// 3. Преимущества указать метод как const - гарантируем что метод ничего не поменяет в объекте (безопасность), для объекта const можно вызывать только const методы, компилятор может применить оптимизации.
// 6. Массив в памяти это ряд идущих ячеек, перемещается смещением.