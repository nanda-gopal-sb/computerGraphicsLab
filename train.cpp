#include <GL/glut.h>
#include <math.h>

float x = 150;

void box(float l, float b, float r, float t)
{
    glBegin(GL_QUADS);
    glVertex2f(l,b); glVertex2f(r,b);
    glVertex2f(r,t); glVertex2f(l,t);
    glEnd();
}

void circle(float x, float y, float r)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for (int i=0; i<=360; i++) {
        float a = i*3.14159f/180;
        glVertex2f(x+r*cosf(a), y+r*sinf(a));
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(x,0,0);

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(150,150); glVertex2f(230,150);
    glVertex2f(230,210); glVertex2f(180,210);
    glVertex2f(150,180);
    glEnd();
    box(175,210,195,235);

    glColor3f(0,0,1);
    box(235,150,340,210);

    glColor3f(1,1,1);
    for (int w=250; w<=290; w+=40) box(w,180,w+20,200);

    glColor3f(0,0,0);
    float wheels[] = {175,225,270,325};
    for (int i=0; i<4; i++) circle(wheels[i],140,15);

    glPopMatrix();
    glutSwapBuffers();
}

void update(int v)
{
    x -= 2;
    if (x < -350) x = 500;
    glutPostRedisplay();
    glutTimerFunc(16,update,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Train Movement");

    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutTimerFunc(16,update,0);
    glutMainLoop();
    return 0;
}
