#include <GL/glut.h>
#include <cmath>

float ballX = 120.0f;
float ballY = 410.0f;
float ballR = 15.0f;

void drawStairs() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(100.0f, 400.0f);
    glVertex2f(150.0f, 400.0f);
    glVertex2f(150.0f, 350.0f);
    glVertex2f(200.0f, 350.0f);
    glVertex2f(200.0f, 300.0f);
    glVertex2f(250.0f, 300.0f);
    glVertex2f(250.0f, 250.0f);
    glVertex2f(300.0f, 250.0f);
    glVertex2f(300.0f, 200.0f);
    glVertex2f(350.0f, 200.0f);
    glEnd();
}

void drawBall() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(ballX, ballY);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex2f(ballX + ballR * cos(rad), ballY + ballR * sin(rad));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawStairs();
    drawBall();
    glFlush();
}

void update(int value) {
    ballX += 1.0f;
    if (ballX > 320.0f) {
        ballX = 120.0f;
        ballY = 410.0f;
    } else if (ballX > 270.0f) {
        ballY = 225.0f;
    } else if (ballX > 220.0f) {
        ballY = 275.0f;
    } else if (ballX > 170.0f) {
        ballY = 325.0f;
    } else if (ballX > 120.0f) {
        ballY = 375.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Ball on Staircase Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}