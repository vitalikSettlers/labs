#pragma once
#include "lab04.h"
namespace lab04 {
    class AnotherVector : public VECTOR {
    public:
        // ���������� ����������� �������� ������
        AnotherVector(int n);
        // ������������� ����� SetValue, ����� ������������� �������� ���������� ��������
        void SetValue(int iIndex, float fValue) override;
        // ��������������� ������ ���������
        VECTOR Sub(const VECTOR& what) override;
        // ��������������� ������ ��������� �� ������
        VECTOR Cmul(float fScalar) override;
        // ���������� ����� ������� (�����)
        virtual float Norm() override;
        void Print() override;
    };
}