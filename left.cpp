#include "left.h"

void Left::run() {
	glRotatef(value, 0.0f, 0.0f, 1.0f);
}

std::istream& operator>>(std::istream& in, Left& l) {
	in >> l.value;
	return in;
}
