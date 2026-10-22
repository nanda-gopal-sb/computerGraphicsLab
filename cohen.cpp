#include <GL/glut.h>
#include <vector>

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

float xmin = 100, ymin = 100, xmax = 400, ymax = 400;

struct Line {
    float x1, y1, x2, y2;
    float ox1, oy1, ox2, oy2;
    bool accepted;
};

std::vector<Line> lines = {
    {50, 50, 450, 450, 50, 50, 450, 450, false},
    {150, 150, 350, 350, 150, 150, 350, 350, false},
    {50, 250, 450, 250, 50, 250, 450, 250, false},
    {20, 20, 80, 80, 20, 20, 80, 80, false},
    {420, 420, 480, 480, 420, 420, 480, 480, false}
};

int getCode(float x, float y) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}

void clip(Line& l) {
    float x1 = l.x1, y1 = l.y1, x2 = l.x2, y2 = l.y2;
    int code1 = getCode(x1, y1);
    int code2 = getCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 | code2) == 0) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            float x, y;
            int outcode = code1 ? code1 : code2;

            if (outcode & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (outcode & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (outcode & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (outcode & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (outcode == code1) {
                x1 = x; y1 = y;
                code1 = getCode(x1, y1);
            } else {
                x2 = x; y2 = y;
                code2 = getCode(x2, y2);
            }
        }
    }
    l.accepted = accept;
    if (accept) {
        l.x1 = x1; l.y1 = y1; l.x2 = x2; l.y2 = y2;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();

    for (const auto& l : lines) {
        glColor3f(0.7f, 0.7f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(l.ox1, l.oy1);
        glVertex2f(l.ox2, l.oy2);
        glEnd();

        if (l.accepted) {
            glColor3f(1.0f, 0.0f, 0.0f);
            glBegin(GL_LINES);
            glVertex2f(l.x1, l.y1);
            glVertex2f(l.x2, l.y2);
            glEnd();
        }
    }

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, 500, 0, 500);
    for (auto& l : lines) {
        clip(l);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cohen-Sutherland Line Clipping Sample Lines");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
