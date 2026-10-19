#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

// Endpoints
double x1_pos = 50.0, y1_pos = 50.0;
double x2_pos = 350.0, y2_pos = 250.0;

int roundVal(double v) {
    return (int)(v + 0.5);
}

void drawDDA(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // White line

    double dx = x2_pos - x1_pos;
    double dy = y2_pos - y1_pos;

    double steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    double xIncrement = dx / steps;
    double yIncrement = dy / steps;

    double x = x1_pos;
    double y = y1_pos;

    glBegin(GL_POINTS);
    
    // Plot the first pixel
    glVertex2i(roundVal(x), roundVal(y));

    // Repeat steps times
    for (int i = 0; i < steps; i++) {
        x += xIncrement;
        y += yIncrement;
        glVertex2i(roundVal(x), roundVal(y));
    }

    glEnd();
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0); // 500x500 coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing Algorithm");
    init();
    glutDisplayFunc(drawDDA);
    glutMainLoop();
    return 0;
}