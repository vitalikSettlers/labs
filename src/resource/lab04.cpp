#include "lab04.h"
#include <math.h>
namespace lab04 {
    /*1 Инициализация вектора с n компонентами, выделяем динамически память */
    VECTOR::VECTOR(int n) {
        this->n = n;                                 // Инициализируем размер вектора.
        this->A = new float[n];                      // Выделяем память под массив
        for (int i = 0; i < this->n; i++)
            this->A[i] = 0.f;                        // Инициализируем все элементы нулем.
    }

    /* Деструктор для освобождения динамически выделенной памяти */
    VECTOR::~VECTOR() {
        delete[] A;  // Освобождаем память
    }

    /* Конструктор копирования */
    VECTOR::VECTOR(const VECTOR& other) {
        n = other.n;                                // Копируем размер
        A = new float[n];                           // Выделяем память для нового массива
        for (int i = 0; i < n; ++i)
            A[i] = other.A[i];                      // Копируем элементы массива
        printf("! - Copy constructor\n");
    }

    /* Метод для задания значений вектора по индексу */
    void VECTOR::SetValue(int iIndex, float fValue) {
        if (iIndex >= 0 && iIndex < n)                // Проверяем, находится ли индекс в допустимых пределах
            A[iIndex] = fValue;                       // Присваиваем значение элементу вектора по индексу
    }

    /* Метод для вычитания другого вектора из текущего */
    VECTOR VECTOR::Sub(const VECTOR& what) {
        VECTOR result(this->n);                     // Создаем временный вектор для хранения результата
        for (int i = 0; i < this->n; i++)           // Выполняем поэлементное вычитание соответствующих компонентов векторов
            result.A[i] = this->A[i] - what.A[i];   // Вычитаем компоненты векторов
        return result;
    }

    /* Метод для умножения всех компонентов вектора на скаляр */
    VECTOR VECTOR::Cmul(float fScalar) {
        VECTOR result(this->n);                     // Создаем временный вектор для хранения результата
        for (int i = 0; i < this->n; i++)           // Выполняем поэлементное умножение каждого компонента вектора на скаляр
            result.A[i] = this->A[i] * fScalar;     // Умножаем компоненту на скаляр
        return result;
    }

    /*12 Вывод в виде “a(i)=” */
    void VECTOR::Print() {
        printf("=========\n");
        for (int i = 0; i < this->n; i++) printf("a(%d) = %f\n", i, this->A[i]);
        printf("=========\n");
    }

    float VECTOR::getValue(int iIndex) const {
        if (iIndex >= 0 && iIndex < n) return A[iIndex];
        return 0.f;
    }

    // Вычисление длины вектора (нормы)
    float VECTOR::Norm() {
        float fSum{ 0.f };
        for (int i{ 0 }; i < this->n; i++)
            fSum += this->A[i] * this->A[i]; // Возведение элемента в квадрат
        return static_cast<float>(sqrt(fSum)); // Возвращаем квадратный корень суммы квадратов
    }

    void VECTOR::showVector() {
        // Невиртуальный метод
        Print();  // Виртуальный метод, который может быть переопределен
    }

    float VECTOR::normVector() {
        // Невиртуальный метод
        return Norm();  // Виртуальный метод, который может быть переопределен
    }
}