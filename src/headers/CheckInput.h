#pragma once
#include <cstdlib>

// ����� ��� �������� ������������ �����
class CheckInput {
public:
    // �������� ������������ ������ �����
    static bool checkInt(const char* str, int& value);

    // �������� ������������ ����� � ��������� ������
    static bool checkDouble(const char* str, double& value);
};