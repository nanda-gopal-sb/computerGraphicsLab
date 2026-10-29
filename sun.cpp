#include <GL/glut.h>
#include <math.h>

float sy = 50;

void circle(float x, float y, float r)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++)
    {
        float a = i * 3.14159 / 180;
        glVertex2f(x + r*cos(a), y + r*sin(a));
    }
    glEnd();
}

void myInit()
{
    glClearColor(0.5, 0.8, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0.7, 0);
    circle(250, sy, 35);
    glColor3f(0, 0.6, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(250, 300);
    glVertex2f(500, 0);

    glEnd();

    glFlush();
}

void update()
{
    sy += 0.9;
    if (sy > 400) sy = 50;
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sunrise Animation");
    myInit();
    glutDisplayFunc(display);
    glutIdleFunc(update);
    glutMainLoop();
    return 0;
}
