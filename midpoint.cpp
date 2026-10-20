// circle drawing 
#include <GL/glut.h>
#include <iostream>
void drawSymmetricPoints(int xc, int yc, int x, int y) {
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}
void midpointCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r; // Initial decision parameter
    glBegin(GL_POINTS);
    drawSymmetricPoints(xc, yc, x, y);
    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawSymmetricPoints(xc, yc, x, y);
    }
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f); // Set pixel color to white

    midpointCircle(320, 240, 100);
    glFlush();
}
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set 2D orthographic projection
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Midpoint Circle Algorithm - Legacy OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}