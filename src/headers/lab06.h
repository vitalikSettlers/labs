#pragma once
#include <cstdio>
namespace lab06 {
	void runDemo();
	// ������ ������, ����������� ������������ ����� ��� ������ ��� ��������� �������
	template <typename T>
	class smartArray {
	private:
		T* _tArray; // ��������� �� ������������ ������ ��������� ���� T
		size_t _sSize; // ���������� ��� �������� ������� �������
	public:
		smartArray(T* tInputArr, int iSize);
		~smartArray();
		// ����� ��� ������ ������������������
		int findSequence(T* tSequence, int iSeqSize) const;
	};

	template <typename T>
	smartArray<T>::smartArray(T* tInputArr, int iSize) : _sSize(iSize) {
		_tArray = new T[_sSize];
		// �������� ������ ������� �������� ������� � ����� ������
		for (size_t i{ 0 }; i < _sSize; ++i) _tArray[i] = tInputArr[i];
	}

	template <typename T>
	smartArray<T>::~smartArray() {
		delete[] _tArray;
	}

	// ����� ��� ������ ������������������
	template <typename T>
	int smartArray<T>::findSequence(T* tSequence, int iSeqSize) const {
		// �������� �� _tArray, �������� ����� ��� ��������� ������������������
		for (size_t i{ 0 }; i <= _sSize - iSeqSize; ++i) {
			bool bFound{ true };
			// ���� ��� �������� ������� �������� ������������������
			for (size_t j{ 0 }; j < iSeqSize; ++j) {
				// ���������� ������� �� _tArray � ��������������� ��������� tSequence
				if (_tArray[i + j] != tSequence[j])
					bFound = false; break;
			}
			if (bFound) return static_cast<int>(i); // ������������������ �������
		}
		return -1; // ������������������ �� �������
	}
}