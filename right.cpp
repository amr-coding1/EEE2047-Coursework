#include "right.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void Right::run() {
    glRotatef(-value, 0.0f, 0.0f, 1.0f);
}

std::istream& operator>>(std::istream& is, Right& r) {
    is >> r.value;
    return is;
}
