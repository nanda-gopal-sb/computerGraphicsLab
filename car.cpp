#include <GL/glut.h>

float carX = -100.0f;

void drawCar() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 20.0f);
    glVertex2f(80.0f, 20.0f);
    glVertex2f(80.0f, 50.0f);
    glVertex2f(0.0f, 50.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(20.0f, 50.0f);
    glVertex2f(60.0f, 50.0f);
    glVertex2f(50.0f, 75.0f);
    glVertex2f(30.0f, 75.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(15.0f, 10.0f);
    glVertex2f(25.0f, 10.0f);
    glVertex2f(25.0f, 20.0f);
    glVertex2f(15.0f, 20.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(55.0f, 10.0f);
    glVertex2f(65.0f, 10.0f);
    glVertex2f(65.0f, 20.0f);
    glVertex2f(55.0f, 20.0f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(600.0f, 0.0f);
    glVertex2f(600.0f, 100.0f);
    glVertex2f(0.0f, 100.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(carX, 100.0f, 0.0f);
    drawCar();
    glPopMatrix();

    glFlush();
}

void timer(int value) {
    carX += 2.0f;
    if (carX > 600.0f) {
        carX = -100.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Moving Car Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}