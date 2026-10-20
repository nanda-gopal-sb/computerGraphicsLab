#include <GL/glut.h>
#include <iostream>
#include <cmath>

// Initial line points (renamed to avoid conflict with standard library 'y1')
float x_1 = 100, y_1 = 100, x_2 = 250, y_2 = 250; 

// Transformed points for Translation, Rotation, and Scaling
float trx1, try1, trx2, try2;
float rrx1, rry1, rrx2, rry2;
float srx1, sry1, srx2, sry2;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // 1. Draw Original Line in BLACK (visible on white background)[cite: 1]
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(x_1, y_1);
    glVertex2f(x_2, y_2);
    glEnd();
    
    // 2. Draw Translated Line in RED[cite: 1]
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(trx1, try1);
    glVertex2f(trx2, try2);
    glEnd();

    // 3. Draw Rotated Line in DARK GREEN (visible on white background)[cite: 1]
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(rrx1, rry1);
    glVertex2f(rrx2, rry2);
    glEnd();

    // 4. Draw Scaled Line in BLUE[cite: 1]
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(srx1, sry1);
    glVertex2f(srx2, sry2);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to WHITE[cite: 1]
    gluOrtho2D(0, 600, 0, 600);           // 2D coordinate system[cite: 1]
}

int main(int argc, char** argv) {
    float tx, ty, angle, sx, sy;

    // Read inputs for all three transformations[cite: 1]
    std::cout << "--- Enter Transformation Parameters ---\n";
    std::cout << "Enter translation values (tx ty): ";
    std::cin >> tx >> ty;
    
    std::cout << "Enter rotation angle in degrees: ";
    std::cin >> angle;
    
    std::cout << "Enter scaling factors (sx sy): ";
    std::cin >> sx >> sy;

    // 1. Calculate Translation[cite: 1]
    trx1 = x_1 + tx; try1 = y_1 + ty;
    trx2 = x_2 + tx; try2 = y_2 + ty;

    // 2. Calculate Rotation[cite: 1]
    float rad = angle * 3.14159f / 180.0f;
    float c = cos(rad), s = sin(rad);
    rrx1 = x_1 * c - y_1 * s; rry1 = x_1 * s + y_1 * c;
    rrx2 = x_2 * c - y_2 * s; rry2 = x_2 * s + y_2 * c;

    // 3. Calculate Scaling[cite: 1]
    srx1 = x_1 * sx; sry1 = y_1 * sy;
    srx2 = x_2 * sx; sry2 = y_2 * sy;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("2D Transformations - Light Background");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}