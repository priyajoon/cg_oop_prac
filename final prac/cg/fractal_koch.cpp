#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;

GLfloat x=-0.5,y=-0.5;
GLint iter;

void drkochcurve(GLfloat dir,GLfloat len,GLfloat iter){
    GLdouble dirrad=0.0174533*dir;
    GLfloat nx=x+len*cos(dirrad);
    GLfloat ny=y+len*sin(dirrad);
    if(iter==0){
        glVertex2f(x,y);
        glVertex2f(nx,ny);
        x=nx;
        y=ny;

    }
    else{

        iter--;
        drkochcurve(dir,len,iter);
        dir+=60;
        drkochcurve(dir,len,iter);
        dir-=120;
        drkochcurve(dir,len,iter);
        dir+=60;
        drkochcurve(dir,len,iter);

    }

}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    cout<<"enter number of iterations"<<endl;
    cin>>iter;
    drkochcurve(0.1,0.015,iter);
    glEnd();
    glFlush();
}

int main(int argc,char* argv){
    glutInit(&argc,&argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(700,700);
    glutCreateWindow("koch curve");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
