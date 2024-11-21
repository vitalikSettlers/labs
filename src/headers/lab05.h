#pragma once
#include <stdio.h>
namespace lab05 {
	void runDemo();
	class VECTOR {
	protected:
		int _n{ 0 };          // ������ �������
		float* _A{ nullptr }; // ��������� �� ������������ ������

	public:
		VECTOR(int n);               // �����������
		VECTOR(const VECTOR& other); // ����������� �����������
		VECTOR() = delete;           // ������ ������������ ����������� �� ���������
		~VECTOR();                   // ����������

		// ���������� �������� �� �������
		void SetValue(int index, float value);
		void SetValue();
		// ���������
		VECTOR Sub(const VECTOR& what);
		VECTOR Sub(float fScalar);
		// ��������� �� ������
		VECTOR Cmul(float fScalar);
		VECTOR Cmul(const VECTOR& vec);
		// ������ �������
		void Print();
		void Print(bool bNewDesignOutput);

		// ���������� ����������� ����������
		VECTOR& operator++();
		// ���������� ���������� ���������
		bool operator==(const VECTOR& other);
		bool operator!=(const VECTOR& other);
		// ���������� ��������� ��������������
		float& operator[](int iIndex);

		// ���.
		VECTOR& operator=(const VECTOR& other);
		VECTOR& operator=(VECTOR&& other) noexcept;
		void operator()(int iNewValue);
	};
}