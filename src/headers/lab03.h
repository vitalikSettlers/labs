#pragma once
#include <cstdio>

namespace lab03 {
	void runDemo();
	class Dispersion {
	private:
		double* _ptrNumbers;    // ������������ ������ ��� �������� �����
		int _iCount;            // ���������� ����� ��������� �������������

	public:
		// ����������� ��� ������������� ������� � ������ ������ ����� ������
		Dispersion(int iSize, double* ptrNumbers);
		~Dispersion();
		// ���������� �������� ���������������
		double calculateMean();
		// ���������� ���������
		double calculateVariance();
	};
}