#include <GL/glut.h>
#include <iostream>

float x1 = 100, y1 = 100, x2 = 250, y2 = 100, x3 = 250, y3 = 200, x4 = 100, y4 = 200;
float xx1, xy1, xx2, xy2, xx3, xy3, xx4, xy4;
float yx1, yy1, yx2, yy2, yx3, yy3, yx4, yy4;
float xyx1, xyy1, xyx2, xyy2, xyx3, xyy3, xyx4, xyy4;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1); glVertex2f(x2, y2); glVertex2f(x3, y3); glVertex2f(x4, y4);
    glEnd();
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xx1, xy1); glVertex2f(xx2, xy2); glVertex2f(xx3, xy3); glVertex2f(xx4, xy4);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(yx1, yy1); glVertex2f(yx2, yy2); glVertex2f(yx3, yy3); glVertex2f(yx4, yy4);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xyx1, xyy1); glVertex2f(xyx2, xyy2); glVertex2f(xyx3, xyy3); glVertex2f(xyx4, xyy4);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, 800, 0, 800);
}

int main(int argc, char** argv) {
    float shx, shy;
    std::cout << "Enter shx and shy: ";
    std::cin >> shx >> shy;

    xx1 = x1 + shx * y1; xy1 = y1;
    xx2 = x2 + shx * y2; xy2 = y2;
    xx3 = x3 + shx * y3; xy3 = y3;
    xx4 = x4 + shx * y4; xy4 = y4;

    yx1 = x1; yy1 = y1 + shy * x1;
    yx2 = x2; yy2 = y2 + shy * x2;
    yx3 = x3; yy3 = y3 + shy * x3;
    yx4 = x4; yy4 = y4 + shy * x4;

    xyx1 = x1 + shx * y1; xyy1 = y1 + shy * x1;
    xyx2 = x2 + shx * y2; xyy2 = y2 + shy * x2;
    xyx3 = x3 + shx * y3; xyy3 = y3 + shy * x3;
    xyx4 = x4 + shx * y4; xyy4 = y4 + shy * x4;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("All Rectangle Shear Transformations");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}