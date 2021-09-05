#include <stdio.h>
#include <windows.h>
#include <GL/glut.h>
#include <GL/glew.h>



void myInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2d(150, 250);
    glVertex2d(100, 200);
    glVertex2d(200, 200);
    glEnd();
}

void drawSquare() {
    glBegin(GL_QUADS);
    glVertex2d(100, 100);
    glVertex2d(200, 100);
    glVertex2d(200, 200);
    glVertex2d(100, 200);
    glEnd();
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    // POINTS
    // glBegin(GL_POINTS);
    //     glVertex2d(150,100);
    //     glVertex2d(100,230);
    //     glVertex2d(170,130);
    //     glVertex2d(300,350);
    // glEnd();

    LINES IN PAIRS OF 2
        glBegin(GL_LINES);
    glVertex2d(150, 100);
    glVertex2d(100, 230);
    glVertex2d(170, 130);
    glVertex2d(300, 350);
    glEnd();

    // LINES CONNECTING ALL POINTS
    // glBegin(GL_LINE_STRIP);
    //     glVertex2d(150,100);
    //     glVertex2d(100,230);
    //     glVertex2d(170,130);
    //     glVertex2d(300,350);
    // glEnd();

    // MULTIPLE TRIANGLES
    // glBegin(GL_TRIANGLES);
    //     glVertex2d(150,100);
    //     glVertex2d(100,230);
    //     glVertex2d(170,130);
    //     glVertex2d(200,200);
    //     glVertex2d(400,300);
    //     glVertex2d(300,300);
    // glEnd();

    // MULTIPLE QUADRILATERALS TAKING 4 POINTS
    // glBegin(GL_QUADS);
    //     glVertex2d(100, 100);
    //     glVertex2d(200, 100);
    //     glVertex2d(200, 200);
    //     glVertex2d(100, 200);

    //     glVertex2d(300, 300);
    //     glVertex2d(400, 300);
    //     glVertex2d(400, 400);
    //     glVertex2d(300, 400);
    // glEnd();


    // glBegin(GL_QUAD_STRIP);
    //     glVertex2d(100, 100);
    //     glVertex2d(200, 100);
    //     glVertex2d(200, 200);
    //     glVertex2d(100, 200);

    //     // glVertex2d(300, 300);
    //     // glVertex2d(400, 300);
    //     // glVertex2d(400, 400);
    //     // glVertex2d(300, 400);
    // glEnd();

    // glBegin(GL_POLYGON);
    //     glVertex2d(100,100);
    //     glVertex2d(200,100);
    //     glVertex2d(200,200);
    //     glVertex2d(100,200);
    //     // glVertex2d(100,100);
    // glEnd();

    // glBegin(GL_POINTS);

    // int flag = 1;
    // for(int i=200; i<400; i+=20) {
    //     for (int j=200; j<400; j+=20) {
    //         if(flag) {
    //             glVertex2d(i, j);
    //             flag = 0;
    //         }
    //         else {
    //             glVertex2d(i+10, j);
    //             flag = 1;
    //         }
    //     }
    // }

    // Checker Board
    // int start = 100;
    // int l = 40;
    // int n = 8;
    // glBegin(GL_QUADS);

    //     for (int i = start; i < start + (l * n) ; i += 2 * l)
    //     {
    //         for (int j = start; j < start + (l * n); j += 2 * l)
    //         {
    //             glVertex2d(i, j);
    //             glVertex2d(i + l, j);
    //             glVertex2d(i + l, j + l);
    //             glVertex2d(i, j + l);

    //             glVertex2d(i + l, j + l);
    //             glVertex2d(i + l + l, j + l);
    //             glVertex2d(i + l + l, j + l + l);
    //             glVertex2d(i + l, j + l + l);
    //         }
    //     }

    // glEnd();

    // X^2 graphs 
    // glBegin(GL_POINTS);
    // for(int i=-25; i<=25; i++) {
    //     glVertex2f(100 + i, 100 + i*i);
    // }

    // for(int i=-25; i<=25; i++) {
    //     glVertex2f(200 + i, 400 + -i*i);
    // }

    // for(int i=-25; i<=25; i++) {
    //     glVertex2f(300 + i, 100 + i*i);
    // }

    // for(int i=-25; i<=25; i++) {
    //     glVertex2f(400 + i, 400 + -i*i);
    // }

    // for(int i=-25; i<=25; i++) {
    //     glVertex2f(500 + i, 100 + i*i);
    // }

    // glEnd();

    //drawTriangle();
    //drawSquare();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1440, 1440);
    glutCreateWindow("First Exercise");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}

