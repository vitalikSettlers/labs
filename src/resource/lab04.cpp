#include "lab04.h"
#include <math.h>
namespace lab04 {
    /*1 ������������� ������� � n ������������, �������� ����������� ������ */
    VECTOR::VECTOR(int n) {
        this->n = n;                                 // �������������� ������ �������.
        this->A = new float[n];                      // �������� ������ ��� ������
        for (int i = 0; i < this->n; i++)
            this->A[i] = 0.f;                        // �������������� ��� �������� �����.
    }

    /* ���������� ��� ������������ ����������� ���������� ������ */
    VECTOR::~VECTOR() {
        delete[] A;  // ����������� ������
    }

    /* ����������� ����������� */
    VECTOR::VECTOR(const VECTOR& other) {
        n = other.n;                                // �������� ������
        A = new float[n];                           // �������� ������ ��� ������ �������
        for (int i = 0; i < n; ++i)
            A[i] = other.A[i];                      // �������� �������� �������
        printf("! - Copy constructor\n");
    }

    /* ����� ��� ������� �������� ������� �� ������� */
    void VECTOR::SetValue(int iIndex, float fValue) {
        if (iIndex >= 0 && iIndex < n)                // ���������, ��������� �� ������ � ���������� ��������
            A[iIndex] = fValue;                       // ����������� �������� �������� ������� �� �������
    }

    /* ����� ��� ��������� ������� ������� �� �������� */
    VECTOR VECTOR::Sub(const VECTOR& what) {
        VECTOR result(this->n);                     // ������� ��������� ������ ��� �������� ����������
        for (int i = 0; i < this->n; i++)           // ��������� ������������ ��������� ��������������� ����������� ��������
            result.A[i] = this->A[i] - what.A[i];   // �������� ���������� ��������
        return result;
    }

    /* ����� ��� ��������� ���� ����������� ������� �� ������ */
    VECTOR VECTOR::Cmul(float fScalar) {
        VECTOR result(this->n);                     // ������� ��������� ������ ��� �������� ����������
        for (int i = 0; i < this->n; i++)           // ��������� ������������ ��������� ������� ���������� ������� �� ������
            result.A[i] = this->A[i] * fScalar;     // �������� ���������� �� ������
        return result;
    }

    /*12 ����� � ���� �a(i)=� */
    void VECTOR::Print() {
        printf("=========\n");
        for (int i = 0; i < this->n; i++) printf("a(%d) = %f\n", i, this->A[i]);
        printf("=========\n");
    }

    float VECTOR::getValue(int iIndex) const {
        if (iIndex >= 0 && iIndex < n) return A[iIndex];
        return 0.f;
    }

    // ���������� ����� ������� (�����)
    float VECTOR::Norm() {
        float fSum{ 0.f };
        for (int i{ 0 }; i < this->n; i++)
            fSum += this->A[i] * this->A[i]; // ���������� �������� � �������
        return static_cast<float>(sqrt(fSum)); // ���������� ���������� ������ ����� ���������
    }

    void VECTOR::showVector() {
        // ������������� �����
        Print();  // ����������� �����, ������� ����� ���� �������������
    }

    float VECTOR::normVector() {
        // ������������� �����
        return Norm();  // ����������� �����, ������� ����� ���� �������������
    }
}