#pragma once
#include <iostream>
namespace lab72 {
	void runDemo();
	class FormattedIO {
	private:
		int _i1, _i2;
		float _f1, _f2;
		char _c;

		// Приватные методы для форматирования
		std::ostream& formatI1(std::ostream& out) const;
		std::ostream& formatI2(std::ostream& out) const;
		std::ostream& formatF1(std::ostream& out) const;
		std::ostream& formatF2(std::ostream& out) const;
		std::ostream& formatC(std::ostream& out) const;

	public:
		friend std::istream& operator>>(std::istream& in, FormattedIO& obj);
		friend std::ostream& operator<<(std::ostream& out, const FormattedIO& obj);
	};
}
