#include <GL/glut.h>
#include <iostream>

int projectionChoice = 1;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if (projectionChoice == 1) {
        glOrtho(-3.0, 3.0, -3.0, 3.0, 1.5, 20.0);
    } else {
        gluPerspective(45.0, 1.0, 1.5, 20.0);
    }
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, -0.5f, -5.0f);
    glRotatef(30.0f, 1.0f, 1.0f, 0.0f);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 1.5f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(0.0f, 1.5f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(0.0f, 1.5f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(0.0f, 1.5f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    
    glVertex3f(-1.0f, -1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    std::cout << "1. Parallel Projection\n2. Perspective Projection\nEnter choice: ";
    std::cin >> projectionChoice;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Pyramid Projections");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}