#include <GL/glut.h>
#include <iostream>

float ax = 50, ay = 50, bx = 150, by = 50, cx = 100, cy = 150;
float xx1, xy1, xx2, xy2, xx3, xy3;
float yx1, yy1, yx2, yy2, yx3, yy3;
float ox1, oy1, ox2, oy2, ox3, oy3;
float yx_x1, yx_y1, yx_x2, yx_y2, yx_x3, yx_y3;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(ax, ay); glVertex2f(bx, by); glVertex2f(cx, cy);
    glEnd();
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xx1, xy1); glVertex2f(xx2, xy2); glVertex2f(xx3, xy3);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(yx1, yy1); glVertex2f(yx2, yy2); glVertex2f(yx3, yy3);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(ox1, oy1); glVertex2f(ox2, oy2); glVertex2f(ox3, oy3);
    glEnd();

    glColor3f(0.5f, 0.0f, 0.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(yx_x1, yx_y1); glVertex2f(yx_x2, yx_y2); glVertex2f(yx_x3, yx_y3);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv) {
    xx1 = ax; xy1 = -ay; xx2 = bx; xy2 = -by; xx3 = cx; xy3 = -cy;
    yx1 = -ax; yy1 = ay; yx2 = -bx; yy2 = by; yx3 = -cx; yy3 = cy;
    ox1 = -ax; oy1 = -ay; ox2 = -bx; oy2 = -by; ox3 = -cx; oy3 = -cy;
    yx_x1 = ay; yx_y1 = ax; yx_x2 = by; yx_y2 = bx; yx_x3 = cy; yx_y3 = cx;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("All Triangle Reflections");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}