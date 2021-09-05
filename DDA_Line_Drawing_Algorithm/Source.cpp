#include <gl/glut.h>
#include <stdio.h>
#include <iostream>
using namespace std;
const float PI = 3.14;
void drawLine(int x0, int y0, int x1, int y1) {
 glBegin(GL_POINTS);
 glColor3f(1.0, 1.0, 1.0);
 int tempx, tempy;
 if (x1 < x0) {
 tempx = x0;
 tempy = y0;
 y0 = y1;
 x0 = x1;
 x1 = tempx;
 y1 = tempy;
 }
 double m = (double)(y1 - y0) / (x1 - x0);
 double y = (double)y0;
 double x = (double)x0;
 if (m < 1) {
 while (x <= x1) {
 glColor3d(1, 0, 0);
 if (-m > 1) {
 glColor3d(0, 0, 1);
 }
 glVertex2d(x, floor(y));
 //printf("%f %f\n", floor(y), x);
 y = y + m;
 x++;
 }
 }
 else {
 double m1 = 1 / m;
 while (y <= y1) {
 glColor3d(0, 0, 1);
 glVertex2d(floor(x), y);
 y++;
 x = x + m1;
 }
 }
 glEnd();
}
void init(void) {
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-1000, 1000, -1000, 1000);
}
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 printf("\nEnter x1 y1:");
 int x1, y1, x2, y2;
 cin >> x1 >> y1;
 printf("\nEnter x2 y2:");
 cin >> x2 >> y2;
 drawLine(x1, y1, x2, y2);
 glutSwapBuffers();
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(50, 50);
 glutCreateWindow("DDA Line Drawing!");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
