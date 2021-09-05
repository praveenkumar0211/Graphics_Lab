#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;
int xc, yc, r;
void plot(int x, int y)
{
glBegin(GL_POINTS);
glVertex2i(x + xc, y + yc);
glEnd();
}
void myInit(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
void midPointCircleAlgo(int xc, int yc, int r)
{
glBegin(GL_POINTS);
int x = 0;
int y = r;
float p = 5 / 4 - r;
glVertex2i(x + xc, y + yc);
while (y > x)
{
if (p < 0)
{
x++;
p += 2 * x + 1;
}
else
{
y--;
x++;
p += 2 * (x - y) + 1;
}
glVertex2i(x + xc, y + yc);
glVertex2i(x + xc, -y + yc);
glVertex2i(-x + xc, y + yc);
glVertex2i(-x + xc, -y + yc);
glVertex2i(y + xc, x + yc);
glVertex2i(-y + xc, x + yc);
glVertex2i(y + xc, -x + yc);
glVertex2i(-y + xc, -x + yc);
}
glEnd();
}
void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 0.0);
//4a
midPointCircleAlgo(250, 350, 50);
//4b - pizza
glPointSize(7.0);
glColor3f(0.94, 0.82, 0.22);
midPointCircleAlgo(250, 150, 50);
glPointSize(5.0);
glColor3f(1, 0, 0);
midPointCircleAlgo(250, 150, 45);
glPointSize(6.0);
glColor3f(0.94, 0.82, 0.22);
midPointCircleAlgo(250, 150, 40);
midPointCircleAlgo(250, 150, 35);
midPointCircleAlgo(250, 150, 30);
midPointCircleAlgo(250, 150, 25);
midPointCircleAlgo(250, 150, 20);
midPointCircleAlgo(250, 150, 15);
midPointCircleAlgo(250, 150, 10);
midPointCircleAlgo(250, 150, 5);
glPointSize(4.0);
glColor3f(1, 0, 0);
midPointCircleAlgo(250, 150, 3);
midPointCircleAlgo(230, 180, 3);
midPointCircleAlgo(220, 160, 3);
midPointCircleAlgo(220, 140, 3);
midPointCircleAlgo(230, 120, 3);
midPointCircleAlgo(270, 180, 3);
midPointCircleAlgo(280, 160, 3);
midPointCircleAlgo(280, 140, 3);
midPointCircleAlgo(270, 120, 3);
midPointCircleAlgo(240, 165, 3);
midPointCircleAlgo(260, 165, 3);
midPointCircleAlgo(240, 135, 3);
midPointCircleAlgo(260, 135, 3);
midPointCircleAlgo(250, 185, 3);
midPointCircleAlgo(250, 115, 3);
glFlush();
}
void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 150);
glutCreateWindow("Line Drawing Alogrithms");
glutDisplayFunc(myDisplay);
myInit();
glutMainLoop();
}
