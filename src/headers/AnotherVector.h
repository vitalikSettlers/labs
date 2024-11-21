#pragma once
#include "lab04.h"
namespace lab04 {
    class AnotherVector : public VECTOR {
    public:
        // »спользуем конструктор базового класса
        AnotherVector(int n);
        // ѕереопределим метод SetValue, чтобы автоматически выводить абсолютное значение
        void SetValue(int iIndex, float fValue) override;
        // ѕереопределение метода вычитани€
        VECTOR Sub(const VECTOR& what) override;
        // ѕереопределение метода умножени€ на скал€р
        VECTOR Cmul(float fScalar) override;
        // ¬ычисление длины вектора (нормы)
        virtual float Norm() override;
        void Print() override;
    };
}