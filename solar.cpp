#include <GL/glut.h>

float year = 0, day = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 1. Setup Projection Frustum
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 800.0 / 600.0, 0.1, 100.0);

    // 2. Setup Camera Position
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 5, 10, 0, 0, 0, 0, 1, 0);

    // Sun (Yellow)
    glColor3f(1.0f, 1.0f, 0.0f);
    glutWireSphere(1.0, 20, 16);

    // Earth (Blue)
    glRotatef(year, 0, 1, 0);
    glTranslatef(4.0f, 0, 0);
    glRotatef(day, 0, 1, 0);
    glColor3f(0.2f, 0.4f, 1.0f);
    glutWireSphere(0.4, 10, 8);

    glutSwapBuffers();
}

void idle() {
    year += 0.15f;
    day += 1.0f;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Solar System");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}