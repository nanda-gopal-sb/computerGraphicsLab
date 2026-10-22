#include <GL/glut.h>

void drawCube() {
    glutWireCube(2.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -12.0f);

    glPushMatrix();
    glTranslatef(-3.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 2.5f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.0f, 0.0f, 0.0f);
    glRotatef(45.0f, 1.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -2.5f, 0.0f);
    glScalef(1.5f, 0.5f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    drawCube();
    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("All 3D Transformations Simultaneously");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}