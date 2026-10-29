#include <GL/glut.h>
#include <cmath>

float posX = 0.0f;
float animTime = 0.0f;

void drawStickFigure() {
    glColor3f(0, 1, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 10) {
        float theta = 3.1415926f * float(i) / 180.0f;
        float x = 250.0f + 30.0f * cosf(theta);
        float y = 400.0f + 30.0f * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0, 1, 0);
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(250, 370);
    glVertex2f(250, 220);
    glEnd();

    glColor3f(0, 1, 0);
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(250, 320);
    glVertex2f(200, 350);
    glEnd();

    glColor3f(0, 1, 0);
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(250, 320);
    glVertex2f(300, 350);
    glEnd();

    float legAngle = 30.0f * sinf(animTime);
    float radL = legAngle * 3.1415926f / 180.0f;
    float radR = -legAngle * 3.1415926f / 180.0f;

    float lFootX = 0.0f * cosf(radL) - (-60.0f) * sinf(radL);
    float lFootY = 0.0f * sinf(radL) + (-60.0f) * cosf(radL);

    float rFootX = 0.0f * cosf(radR) - (-60.0f) * sinf(radR);
    float rFootY = 0.0f * sinf(radR) + (-60.0f) * cosf(radR);

    glColor3f(0, 1, 0);
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(250, 220);
    glVertex2f(250 + lFootX, 220 + lFootY);
    glEnd();

    glColor3f(0, 1, 0);
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(250, 220);
    glVertex2f(250 + rFootX, 220 + rFootY);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(posX, 0.0f, 0.0f);
    drawStickFigure();
    glutSwapBuffers();
}

void update(int value) {
    posX += 1.5f;
    animTime += 0.1f;
    if (posX > 500.0f) {
        posX = -100.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Walking Man");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}

