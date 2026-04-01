#include "repeat.h"

void Repeat::run() {
	for (int i(0); i < (int)value; i++) {
		prg.run();
	}
}

std::istream& operator>>(std::istream& in, Repeat& r) {
	in >> r.value;
	std::string bracket;
	in >> bracket;
	if (bracket != "[") {
		std::cerr << "Error: expected '[' after REPEAT count" << std::endl;
		return in;
	}
	in >> r.prg;
	return in;
}
