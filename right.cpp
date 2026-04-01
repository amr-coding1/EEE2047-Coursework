#include "right.h"

void Right::run() {
	glRotatef(-value, 0.0f, 0.0f, 1.0f);
}

std::istream& operator>>(std::istream& in, Right& r) {
	in >> r.value;
	return in;
}
