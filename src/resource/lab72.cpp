#include "lab72.h"
#include <iomanip> // Для std::setw, std::setprecision
namespace lab72 {
	std::ostream& FormattedIO::formatI1(std::ostream& out) const {
		return out << std::setw(5) << std::hex << std::uppercase << _i1;
	}

	std::ostream& FormattedIO::formatI2(std::ostream& out) const {
		return out << std::setw(5) << std::hex << std::uppercase << _i2;
	}

	std::ostream& FormattedIO::formatF1(std::ostream& out) const {
		return out << std::setw(5) << std::fixed << std::setprecision(2) << _f1;
	}

	std::ostream& FormattedIO::formatF2(std::ostream& out) const {
		return out << std::setw(5) << std::fixed << std::setprecision(3) << _f2;
	}

	std::ostream& FormattedIO::formatC(std::ostream& out) const {
		return out << std::setw(5) << _c;
	}

	// Перегрузка оператора ввода
	std::istream& operator>>(std::istream& in, FormattedIO& obj) {
		in >> obj._i1 >> obj._f1 >> obj._c >> obj._f2 >> obj._i2;
		return in;
	}

	// Перегрузка оператора вывода
	std::ostream& operator<<(std::ostream& out, const FormattedIO& obj) {
		out << "Result output:\n";
		out << std::setfill('*');
		obj.formatI2(out) << "\n";
		obj.formatI1(out) << "\n";
		obj.formatC(out) << "\n";
		obj.formatF1(out) << "\n";
		obj.formatF2(out) << "\n";
		return out;
	}
}