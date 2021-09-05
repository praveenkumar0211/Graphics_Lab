#include<glut.h>
#include<stdio.h>
int x1, y1, x2, y2;
voidmyInit() {
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.0, 0.0, 1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0, 500, 0, 500);
}
voiddraw_pixel(intx, inty) {
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}
voiddraw_line(intx1, intx2, inty1, inty2) {
int dx, dy, i, e;
intincx, incy, inc1, inc2;
int x, y;
dx = x2 - x1;
dy = y2 - y1;
if (dx < 0)
dx = -dx;
if (dy< 0)
dy = -dy;
incx = 1;
if (x2<x1) incx = -1;
incy = 1;
if (y2<y1) incy = -1;
x = x1; y = y1;
if (dx >dy) {
draw_pixel(x, y);
e = 2 * dy - dx;
inc1 = 2 * (dy - dx);
inc2 = 2 * dy;
for (i = 0; i< dx; i++) {
if (e >= 0) {
y += incy;
e += inc1;
}
else
e += inc2;
x += incx;
draw_pixel(x, y);
}
}
else {
draw_pixel(x, y);
e = 2 * dx - dy;
inc1 = 2 * (dx - dy);
inc2 = 2 * dx;
for (i = 0; i<dy; i++) {
if (e >= 0) {
x += incx;
e += inc1;
}
else
e += inc2;
y += incy;
draw_pixel(x, y);
}
}
}
voidmyDisplay() {
//x1, x2, y1, y2
//left to right m<1
draw_line(10, 240, 240, 300);
//left to right m>1
draw_line(250, 310, 240, 470);
//letter A
draw_line(200, 250, 30, 220);
draw_line(250, 300, 220, 30);
draw_line(225, 275, 125, 125);
glFlush();
}
voidmain(intargc, char** argv) {
//printf("Enter (x1, y1, x2, y2)\n");
//scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutCreateWindow("Bresenham's Line Drawing");
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();
}
