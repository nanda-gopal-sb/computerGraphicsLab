#include <GL/glut.h>
#include <iostream>
#include <cmath>

float ax = 200, ay = 100, bx = 300, by = 300, cx = 100, cy = 300;
float nx1, ny1, nx2, ny2, nx3, ny3;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glVertex2f(cx, cy);
    glEnd();
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(nx1, ny1);
    glVertex2f(nx2, ny2);
    glVertex2f(nx3, ny3);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    float angle;
    std::cout << "Enter rotation angle in degrees: ";
    std::cin >> angle;
    
    float rad = angle * 3.14159f / 180.0f;
    float c = cos(rad), s = sin(rad);
    
    nx1 = ax * c - ay * s;
    ny1 = ax * s + ay * c;
    nx2 = bx * c - by * s;
    ny2 = bx * s + by * c;
    nx3 = cx * c - cy * s;
    ny3 = cx * s + cy * c;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangle Rotation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
