#include "jump.h"

void Jump::run() {
	glTranslatef(value, 0.0f, 0.0f);
}

std::istream& operator>>(std::istream& in, Jump& j) {
	in >> j.value;
	return in;
}
