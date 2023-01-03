﻿#include<stdc++.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

int totStep = 0;

typedef enum
{
    MODE_BITMAP,
    MODE_STROKE
} mode_type;

static mode_type mode;
static int font_index;


void print_stroke_string(void* font, char* s)
{
    if (s && strlen(s))
    {
        while (*s)
        {
            glutStrokeCharacter(font, *s);
            s++;
        }
    }
}


void draw_stuff(int index, double tx, double ty)
{
    char string[8][256];
    unsigned int count;

    void* stroke_fonts[2] =
    {
        GLUT_STROKE_ROMAN,
        GLUT_STROKE_ROMAN
    };

    count = 0; string[0][count] = 49; string[0][++count] = '\0';
    count = 0; string[1][count] = 50; string[1][++count] = '\0';
    count = 0; string[2][count] = 51; string[2][++count] = '\0';
    count = 0; string[3][count] = 52; string[3][++count] = '\0';
    count = 0; string[4][count] = 53; string[4][++count] = '\0';
    count = 0; string[5][count] = 54; string[5][++count] = '\0';
    count = 0; string[6][count] = 55; string[6][++count] = '\0';
    count = 0; string[7][count] = 56; string[7][++count] = '\0';

    glColor3f(0.0, 0.0, 0.0);

    int stroke_scale = 10;
    glPushMatrix();
    {
        glTranslatef(tx, ty, 0);
        glScalef(0.2, 0.2, 0.2);
        print_stroke_string(stroke_fonts[font_index], string[index]);
    }
    glPopMatrix();

}


struct st {
    double x;
    double y;
    double rgb[3];
    int number;
};

int flg = 1, index = 6, action = -1, stopIndex = -1;

int grid[3][3] = { {4,3,2},
                 {7,5,8},
                 {1,6,0} };

double color[9][3] = { {0,0,0},{1,0,1},{1,1,0},{1,0,0},{0,0,1},{0,1,0},{1,1,1},{0,1,1},{0.5,0.3,0.5} };
double primaryPosition[9][2] = { {20,-60},{-60,-60},{20,20},{-20,20},{-60,20},{-20,-20},{-20,-60},{-60,-20},{20,-20} };
double counter = 40;
typedef struct st blok;

blok bloks[9];

void findZero(int* x, int* y) {
    int flag = 0, i = 0, j = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }
    *x = i;
    *y = j;
}

void drawGrid() {
    int i;

    glColor3f(1, 1, 1);//gray

    glBegin(GL_LINES); {

        for (int i = -60; i <= 60; i += 40) {
            //lines parallel to X-axis
            glVertex3f(-60, i, 0);
            glVertex3f(60, i, 0);

            //lines parallel to Y-axis
            glVertex3f(i, -60, 0);
            glVertex3f(i, 60, 0);
        }
    }
    glEnd();
}

void drawSquare(double x, double y, double r, double g, double b) {

    glColor3f(r, g, b);
    glBegin(GL_QUADS); {
        glVertex3f(x + 1, y + 1, 0);
        glVertex3f(x + 39, y + 1, 0);
        glVertex3f(x + 39, y + 39, 0);
        glVertex3f(x + 1, y + 39, 0);
    }
    glEnd();

}

bool check() {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] != cnt) return false;
            cnt++;
        }
    }
    return true;
}

void display()
{
    if (check()) {
        printf("Solved!!!\n");
        printf("Total number of step is %d", totStep);
        exit(0);
    }
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
    glColor3f(0, 1, 0);
 
    drawGrid();
    int temp1 = -60;
    int temp2 = -60;

    for (int i = 1; i < 10; i++) {
        if (flg == 1) {
            bloks[i - 1].number = grid[(i - 1) / 3][(i - 1) % 3];
            bloks[i - 1].x = primaryPosition[i - 1][0];
            bloks[i - 1].y = primaryPosition[i - 1][1];
        }
        for (int j = 0; j < 3; j++) bloks[i - 1].rgb[j] = color[i - 1][j];
        if (i - 1 != stopIndex) {
            double inc = 0.05;

            for (int k = 0; k < 5; k++) {

                if (i == 9) draw_stuff(7, bloks[i - 1].x + 10 + inc, bloks[i - 1].y + 10);
                else draw_stuff(i - 2, bloks[i - 1].x + 10 + inc, bloks[i - 1].y + 10);
                inc = inc + 0.05;


            }
            drawSquare(bloks[i - 1].x, bloks[i - 1].y, bloks[i - 1].rgb[0], bloks[i - 1].rgb[1], bloks[i - 1].rgb[2]);
        }
    }
    flg = 0;
    glutSwapBuffers();
}

void animate()
{
    glutPostRedisplay();
    if (flg == 0 && action != -1) {
        if (action == 1) {
            int limit = bloks[index].y + counter;
            if (limit <= 60 && counter > 0) {
                int x, y;
                findZero(&x, &y);
                stopIndex = grid[x][y];
                bloks[index].y += 0.05;
                counter -= 0.05;
            }
            if (counter < 0) {
                action = -1;
                stopIndex = -1;
                int x, y;
                findZero(&x, &y);
                int t = grid[x][y];
                bloks[t].y -= 40;

            }
        }

        else if (action == 2) {
            int limit = bloks[index].y + counter;
            if (limit >= -60 && counter < 0) {
                int x, y;
                findZero(&x, &y);
                stopIndex = grid[x][y];
                bloks[index].y -= 0.05;
                counter += 0.05;
            }
            if (counter > 0) {
                action = -1;
                stopIndex = -1;
                int x, y;
                findZero(&x, &y);
                int t = grid[x][y];
                bloks[t].y += 40;
            }
        }

        else if (action == 3) {
            int limit = bloks[index].x + counter;
            if (limit <= 60 && counter > 0) {
                int x, y;
                findZero(&x, &y);
                stopIndex = grid[x][y];
                bloks[index].x += 0.05;
                counter -= 0.05;
            }
            if (counter < 0) {
                action = -1;
                stopIndex = -1;
                int x, y;
                findZero(&x, &y);
                int t = grid[x][y];
                bloks[t].x -= 40;
            }
        }

        else if (action == 4) {
            int limit = bloks[index].x + counter;

            if (limit >= -60 && counter < 0) {
                int x, y;
                findZero(&x, &y);
                stopIndex = grid[x][y];
                bloks[index].x -= 0.05;
                counter += 0.05;

            }
            if (counter > 0) {
                action = -1;
                stopIndex = -1;
                int x, y;
                findZero(&x, &y);
                int t = grid[x][y];
                bloks[t].y += 40;
            }
        }

    }

}

void specialKeyListener(int key, int x, int y)
{
    if (key == GLUT_KEY_UP && action == -1) {
        int x, y;
        findZero(&x, &y);
        if (x < 2) {
            swap(grid[x][y], grid[x + 1][y]);
            action = 1;
            counter = 40;
            index = grid[x][y];
            totStep++;
        }

    }

    else if (key == GLUT_KEY_DOWN && action == -1) {
        int x, y;
        findZero(&x, &y);
        if (x > 0) {
            swap(grid[x][y], grid[x - 1][y]);
            action = 2;
            counter = -40;
            index = grid[x][y];
            totStep++;
        }

    }
    else if (key == GLUT_KEY_LEFT && action == -1) {
        int x, y;
        findZero(&x, &y);
        if (y < 2) {
            swap(grid[x][y], grid[x][y + 1]);
            action = 4;
            counter = -40;
            index = grid[x][y];
            totStep++;
        }

    }
    else if (key == GLUT_KEY_RIGHT && action == -1) {
        int x, y;
        findZero(&x, &y);
        if (y > 0) {
            swap(grid[x][y], grid[x][y - 1]);
            action = 3;
            counter = 40;
            index = grid[x][y];
            totStep++;
        }

    }

}

void init()
{
    mode = MODE_STROKE;
    font_index = 1;
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 1, 0.1, 10000.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 750);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

    glutCreateWindow("8 puzzle");
    init();
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);

    glutSpecialFunc(specialKeyListener);
    glutIdleFunc(animate);
    glutMainLoop();
    return 0;
}