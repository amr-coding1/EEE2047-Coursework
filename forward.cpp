#include "forward.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void Forward::run() {
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(value, 0.0f, 0.0f);
    glEnd();
    glTranslatef(value, 0.0f, 0.0f);
}

std::istream& operator>>(std::istream& is, Forward& f) {
    is >> f.value;
    return is;
}
