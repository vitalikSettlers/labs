#include "CheckInput.h"
// Проверка корректности целого числа
bool CheckInput::checkInt(const char* str, int& value) {
	char* endPtr;
	value = strtol(str, &endPtr, 10);
	return endPtr != str && *endPtr == '\n';
}

// Проверка корректности числа с плавающей точкой
bool CheckInput::checkDouble(const char* str, double& value) {
	char* endPtr;
	value = strtod(str, &endPtr);
	return endPtr != str && *endPtr == '\n';
}