#include "left.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void Left::run() {
    glRotatef(value, 0.0f, 0.0f, 1.0f);
}

std::istream& operator>>(std::istream& is, Left& l) {
    is >> l.value;
    return is;
}
