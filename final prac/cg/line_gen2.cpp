#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include <stdlib.h>
using namespace std;

class line{
    double ax1,ax2,ay1,ay2;
    double x,y,xinc,yinc;
public:
    void get_data();
    void dda();
    void simple_bresenham();

}l;

void line::get_data(){
    cout<<"Enter coordinates for line"<<endl;
    cout<<"Enter x1 and y1 = ";
    cin>>ax1>>ay1;
    cout<<"Enter x2 and y2 = ";
    cin>>ax2>>ay2;
}
void plot(int x,int y){
    glPointSize(1.0);
    //glColor3f(1.0,1.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void line::simple_bresenham(){
    int p = 0;
    int dx = ax2 - ax1;
    int dy = ay2 - ay1;
    p = (2 * dx) - dy;
    int steps=0;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else (steps = abs(dy));

    glPointSize(5.0);

    for (int i = 0; i <= steps; i++)
    {
        if (p >= 0)
        {
            x = x + 1;
            y = y + 1;
            p = p + (2 * dy) - (2 * dx);
        }

        if (p < 0)
        {
            x = x + 1;
            y = y;
            p = p + (2 * dy);
        }
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
    glFlush();
}

void line::dda(){
    double dx=ax2-ax1;
    double dy=ay2-ay1;
    double steps=0.0;
    if(abs(dx)>abs(dy)){
        steps=dx;
    }
    else{
        steps=dy;
    }
    xinc=dx/steps;
    yinc=dy/steps;

    x=ax1;
    y=ay1;
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    for(int i=0;i<=steps;i++){
        x=x+xinc;
        y=y+yinc;
        glColor3f(1.0,1.0,0.0);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }
    glFlush();

}
void lines(int item){
    if(item==1){
        l.dda();
    }
    else if(item==2){
        l.simple_bresenham();
    }
}


void keyboard(unsigned char key,int x,int y){
     if(key=='d'){
        l.dda();
     }
     else if(key=='s'){
        l.simple_bresenham();
     }

}

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
}
void display(void){


}
int main(int argc,char* argv[]){
    cout<<"Press 'd' for dda line generation"<<endl;
    cout<<"Press 's' for simple bresenham"<<endl;
    l.get_data();
    glutInit(&argc,argv);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(5,5);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Line generation");
    init();
    glutKeyboardFunc(keyboard);
    glutCreateMenu(lines);
    glutAddMenuEntry("DDA",1);
    glutAddMenuEntry("Bresenham",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMainLoop();

}

