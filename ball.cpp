#include <GL/glut.h>
#include <cmath>

float ballX = 120.0f;
float ballY = 415.0f; // 400 (stair height) + 15 (ball radius)
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
    // Move across Step 1
    if (ballX < 150.0f) {
        ballX += 1.0f;
        if (ballX > 150.0f) ballX = 150.0f;
    } 
    // Fall down Drop 1
    else if (ballY > 365.0f) {
        ballY -= 2.0f;
        if (ballY < 365.0f) ballY = 365.0f;
    } 
    // Move across Step 2
    else if (ballX < 200.0f) {
        ballX += 1.0f;
        if (ballX > 200.0f) ballX = 200.0f;
    } 
    // Fall down Drop 2
    else if (ballY > 315.0f) {
        ballY -= 2.0f;
        if (ballY < 315.0f) ballY = 315.0f;
    } 
    // Move across Step 3
    else if (ballX < 250.0f) {
        ballX += 1.0f;
        if (ballX > 250.0f) ballX = 250.0f;
    } 
    // Fall down Drop 3
    else if (ballY > 265.0f) {
        ballY -= 2.0f;
        if (ballY < 265.0f) ballY = 265.0f;
    } 
    // Move across Step 4
    else if (ballX < 300.0f) {
        ballX += 1.0f;
        if (ballX > 300.0f) ballX = 300.0f;
    } 
    // Fall down Drop 4
    else if (ballY > 215.0f) {
        ballY -= 2.0f;
        if (ballY < 215.0f) ballY = 215.0f;
    } 
    // Move across Step 5, then reset
    else if (ballX < 330.0f) {
        ballX += 1.0f;
    } else {
        ballX = 120.0f;
        ballY = 415.0f;
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