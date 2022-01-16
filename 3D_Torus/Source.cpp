#include<GL/glut.h>

using namespace std;

int x = 0, y = 0;

void disp(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glColor3f(1, 0, 0);

	glPushMatrix();

	glOrtho(-2, 2, -2, 2, -2, 2);
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);

	glRotatef(x, 1, 0, 0);
	glRotatef(y, 0, 1, 0);
	glutWireTorus(0.4, 0.8, 10, 20);

	glPopMatrix();

	glFlush();
}

void time(int)
{
	x += 5, y += 5;
	glutPostRedisplay();
	glutTimerFunc(10, time, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Circle reflection");

	glClearColor(1, 1, 1, 0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(disp);
	glutTimerFunc(10, time, 0);
	glutMainLoop();


}
