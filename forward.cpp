#include "forward.h"

void Forward::run() {
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(value, 0.0f, 0.0f);
	glEnd();
	glTranslatef(value, 0.0f, 0.0f);
}

std::istream& operator>>(std::istream& in, Forward& f) {
	in >> f.value;
	return in;
}
