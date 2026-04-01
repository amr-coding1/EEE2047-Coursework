#include "jump.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void Jump::run() {
    glTranslatef(value, 0.0f, 0.0f);
}

std::istream& operator>>(std::istream& is, Jump& j) {
    is >> j.value;
    return is;
}
