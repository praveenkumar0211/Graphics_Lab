#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <glut.h>
using namespace std;
int op = 0, edges, pntX1, pntY1;
vector<int> pntX;
vector<int> pntY;
int shearingX, shearingY;
double round(double d)
{
return floor(d + 0.5);
}
void drawPolygon()
{
glBegin(GL_POLYGON);
glColor3f(1, 0, 0);
for (int i = 0; i < edges; i++)
{
glVertex2i(pntX[i], pntY[i]);
}
glEnd();
}
void reflectX()
{
glBegin(GL_POLYGON);
glColor3f(0.51, 0.69, 0.94);
for (int i = 0; i < edges; i++)
{
glVertex2i(round(pntX[i]), round(pntY[i] * -1));
}
glEnd();
}
void reflectY()
{
glBegin(GL_POLYGON);
glColor3f(0.51, 0.69, 0.94);
for (int i = 0; i < edges; i++)
{
glVertex2i(round(pntX[i] * -1), round(pntY[i]));
}
glEnd();
}
void reflectOrigin()
{
glBegin(GL_POLYGON);
glColor3f(0.51, 0.69, 0.94);
for (int i = 0; i < edges; i++)
{
glVertex2i(round(pntX[i] * -1), round(pntY[i] * -1));
}
glEnd();
}
void reflectDiag()
{
glBegin(GL_POLYGON);
glColor3f(0.51, 0.69, 0.94);
for (int i = 0; i < edges; i++)
{
glVertex2i(round(pntY[i]), round(pntX[i]));
}
glEnd();
}
void shearX()
{
glBegin(GL_POLYGON);
glColor3f(0.51, 0.69, 0.94);
glVertex2i(pntX[0] + 150, pntY[0]);
glVertex2i(pntX[1] + shearingX + 150, pntY[1]);
glVertex2i(pntX[2] + shearingX + 150, pntY[2]);
glVertex2i(pntX[3] + 150, pntY[3]);
glEnd();
}
void shearY()
{
glBegin(GL_POLYGON);
glColor3f(0.51, 0.69, 0.94);
glVertex2i(pntX[0] + 150, pntY[0]);
glVertex2i(pntX[1] + 150, pntY[1]);
glVertex2i(pntX[2] + 150, pntY[2] + shearingY);
glVertex2i(pntX[3] + 150, pntY[3] + shearingY);
glEnd();
}
void myInit(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}
void myDisplay(void)
{
while (true) {
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_LINES);
glVertex2d(-640, 0);
glVertex2d(640, 0);
glVertex2d(0, 480);
glVertex2d(0, -480);
glEnd();
drawPolygon();
cout << "1. Reflection along X axis\n";
cout << "2. Reflection along Y axis\n";
cout << "3. Reflection about origin\n";
cout << "4. Reflection along X=Y\n";
cout << "5. Shearing along X axis\n";
cout << "6. Shearing along Y axis\n";
cout << "7. Exit\n";
cout << "Enter your choice : ";
cin >> op;
if (op == 7) {
break;
}
if (op == 1)
{
reflectX();
}
else if (op == 2)
{
reflectY();
}
else if (op == 3)
{
reflectOrigin();
}
else if (op == 4)
{
reflectDiag();
}
else if (op == 5)
{
cout << "Enter the shearing factor for X: "; cin >> shearingX;
shearX();
}
else if (op == 6)
{
cout << "Enter the shearing factor for Y: "; cin >> shearingY;
shearY();
}
glFlush();
}
}
void main(int argc, char** argv)
{
cout << "\nFor Polygon:\n" << endl;
cout << "Enter no of edges: "; cin >> edges;
cout << "\nEnter Polygon Coordinates : \n";
for (int i = 0; i < edges; i++) {
cout << "Vertex " << i + 1 << " : "; cin >> pntX1 >> pntY1;
pntX.push_back(pntX1);
pntY.push_back(pntY1);
}
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640, 480);
glutInitWindowPosition(100, 150);
glutCreateWindow("Transformations");
glutDisplayFunc(myDisplay);
myInit();
glutMainLoop();
}
