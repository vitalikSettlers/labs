#include "CheckInput.h"
// �������� ������������ ������ �����
bool CheckInput::checkInt(const char* str, int& value) {
	char* endPtr;
	value = strtol(str, &endPtr, 10);
	return endPtr != str && *endPtr == '\n';
}

// �������� ������������ ����� � ��������� ������
bool CheckInput::checkDouble(const char* str, double& value) {
	char* endPtr;
	value = strtod(str, &endPtr);
	return endPtr != str && *endPtr == '\n';
}