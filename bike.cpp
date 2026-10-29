#include <GL/glut.h>
#include <cmath>
float x = 0 ;
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(x, 0.0f, 0.0f);
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(50,200);
    glVertex2f(230,200);
    glVertex2f(250,250);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(230,200);
    glVertex2f(250,130);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(75,200);
    glVertex2f(30,130);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0 ; i<=360 ; i+=10){
        float a = float(i)*3.1415/180.0f;
        glVertex2f(250 + 30.0f*cosf(a), 130 + 30.0f*sinf(a));
    }

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0 ; i<=360 ; i+=10){
        float a = float(i)*3.1415/180.0f;
        glVertex2f(30 + 30.0f*cosf(a), 130 + 30.0f*sinf(a));
    }
    glEnd();
    glutSwapBuffers();
}

void update(int value){
    x += 1.0f;
    if (x > 500.0f) x = -250.0f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}
void init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}


int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bike");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(16,update,0);
    glutMainLoop();
}
