#ifndef __WINDOW_H__
#define __WINDOW_H__
//-----------------------------------------
// Do not modify this file
//-----------------------------------------

#include <GL/gl.h>     // The GL Header File
#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
#include <stdlib.h>
#include <iostream>
#include <fstream>

void draw(void);
void reshape(int w,int h);
void keyboard ( unsigned char key, int x, int y );
void display();

class window {
public:
	window(int argc, char** argv);
	~window()
	{
		delete[] colours;
	};

	static int width, height;
	static unsigned char* colours;

};
int window::width=500;
int window::height=500;
unsigned char* window::colours=NULL;

window::window(int argc, char** argv)
{
	glutInit( &argc, argv );
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
	glutInitWindowSize  ( width, height );
	colours = new unsigned char[3*width*height];
	glutCreateWindow    ( "ODD assignment" );
	glutDisplayFunc     ( display );
	glutReshapeFunc     ( reshape );
	glutKeyboardFunc    ( keyboard );
	glutMainLoop        ( );
}

void reshape ( int w, int h )
{
	window::width=w;
	window::height=h;
	glViewport     ( 0, 0, w, h );
	glMatrixMode   ( GL_PROJECTION );
	glLoadIdentity ( );
	if ( h==0 )
		gluPerspective ( 80, ( float ) w, 1.0, 5000.0 );
	else
		gluPerspective ( 80, ( float ) w / ( float ) h, 1.0, 5000.0 );
	glMatrixMode   ( GL_MODELVIEW );
	glLoadIdentity ( );
	delete[] window::colours;
	window::colours = new unsigned char[3*w*h];
}

void keyboard( unsigned char key, int x, int y )
{
	switch ( key ) {
	case 27:
		exit ( 0 );
		break;
	default:
		break;
	}
}

void display()
{
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-6.0f);
	glColor3f(1,1,1);
	draw();
	glReadPixels(0, 0, window::width, window::height,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			window::colours);
	std::ofstream out("screen.ppm", std::ios::binary);
	out << "P6\n" << window::width << " " << window::height << "\n255\n";
	out.write((char*)window::colours, 3*window::width*window::height);
	out.flush();
	out.close();
	glutSwapBuffers ( );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

#endif /* __WINDOW_H__ */
