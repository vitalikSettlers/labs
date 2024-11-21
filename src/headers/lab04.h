#pragma once
#include <stdio.h>
namespace lab04 {
	void runDemo();
	class VECTOR {
	protected:
		int n{ 0 };          // ������ �������
		float* A{ nullptr }; // ��������� �� ������������ ������

	public:
		VECTOR(int n);               // �����������
		VECTOR(const VECTOR& other); // ����������� �����������
		~VECTOR();                   // ����������

		float getValue(int iIndex) const;
		// ���������� �������� �� �������
		virtual void SetValue(int index, float value);
		// ���������
		virtual VECTOR Sub(const VECTOR& what);
		// ��������� �� ������
		virtual VECTOR Cmul(float fScalar);
		// ������ �������
		virtual void Print();
		void showVector();

		virtual float Norm();
		float normVector();
	};
}
