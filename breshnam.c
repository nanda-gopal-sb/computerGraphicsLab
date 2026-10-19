#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int x0_pos = 50, y0_pos = 50;
int x1_pos = 350, y1_pos = 200;

void drawBresenhamLine(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0); // Green line

    int dx = abs(x1_pos - x0_pos);
    int dy = abs(y1_pos - y0_pos);
    
    // Initial decision parameter
    int p = 2 * dy - dx;

    int x = x0_pos;
    int y = y0_pos;

    glBegin(GL_POINTS);
    
    glVertex2i(x, y);

    // For each xk along the line
    while (x < x1_pos) {
        x++;
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        glVertex2i(x, y);
    }

    glEnd();
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    init();
    glutDisplayFunc(drawBresenhamLine);
    glutMainLoop();
    return 0;
}