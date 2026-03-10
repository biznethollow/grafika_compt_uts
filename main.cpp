#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){

	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(8);
	glLineWidth(3);

	glBegin(GL_POINT_BIT);	
	glVertex2f(0,0);
	glVertex2f(0,5);
	glVertex2f(2.5,8);
	glVertex2f(5,5);
	glVertex2f(5,0);
	glVertex2f(0,0);
	glEnd();

	glBegin(GL_POINT);
		glRecti(1,0,2,3);
		glRecti(3,3,4,4);
	glEnd();

	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-0.5,9,-0.5,9);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.1,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Segitiga Titik");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}
