#include <GL/glut.h>
#include <math.h>

float ballX = 120.0f;    // Ball translation variable (separate)
float legAngle = 0.0f;   // Leg rotation angle in degrees (separate)
int state = 0;           // Animation state machine

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for stick figure

    // 1. Head
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 15) {
        float rad = i * 3.14159f / 180.0f;
        glVertex2f(80 + 15 * cosf(rad), 300 + 15 * sinf(rad));
    }
    glEnd();

    // 2. Torso, Arms, and Standing Leg
    glBegin(GL_LINES);
    // Torso
    glVertex2f(80, 285); glVertex2f(80, 220);
    // Arms
    glVertex2f(80, 270); glVertex2f(55, 245);
    glVertex2f(80, 270); glVertex2f(105, 245);
    // Standing Leg
    glVertex2f(80, 220); glVertex2f(65, 180);
    glEnd();

    // 3. Kicking Leg (Fixed-length rotation using 2D rotation formulas)
    float rad = legAngle * 3.14159f / 180.0f;
    // Local leg vector (hip at 0,0 pointing down to y = -40)
    float footOffsetX = 0.0f * cosf(rad) - (-40.0f) * sinf(rad);
    float footOffsetY = 0.0f * sinf(rad) + (-40.0f) * cosf(rad);

    glBegin(GL_LINES);
    glVertex2f(80, 220); // Hip coordinate
    glVertex2f(80 + footOffsetX, 220 + footOffsetY); // Rotated Foot (rigid length!)
    glEnd();

    // 4. Ball (Rendered at its own independent translation position: ballX)
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(ballX, 180);
    for (int i = 0; i <= 360; i += 15) {
        float r = i * 3.14159f / 180.0f;
        glVertex2f(ballX + (12 * cosf(r)), 180 + (12 * sinf(r)));
    }
    glEnd();

    glutSwapBuffers();
}

void update(int v) {
    if (state == 0) {
        legAngle -= 2.0f; // Swing leg back
        if (legAngle <= -30.0f) state = 1;
    } else {
        legAngle += 3.5f; // Swing leg forward to kick
        if (legAngle > 20.0f) legAngle = 20.0f; // Limit follow-through angle

        // Ball translation is separate, but triggered when the leg swings forward
        if (legAngle >= -5.0f && ballX < 450.0f) {
            ballX += 3.0f; // Ball rolls forward independently
        }

        // Reset loop when ball goes off screen
        if (ballX >= 450.0f) {
            ballX = 120.0f;
            legAngle = 0.0f;
            state = 0;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Kicking a Ball - Clean Rotation");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
