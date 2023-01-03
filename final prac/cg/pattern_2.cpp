#include<windows.h>
#include<bits/stdc++.h>
#include <GL/glut.h>
#include<math.h>
using namespace std;
int width = 800, height = 800;
int cx=400,cy=400;
float r=150,r2=300;

void drawLine(float ax1,float ay1,float ax2,float ay2){
    float dx=ax2-ax1;
    float dy=ay2-ay1;
    float steps=0.0;
    if(abs(dx)>abs(dy)){
        steps=dx;
    }
    else{
        steps=dy;
    }
    float xinc=dx/steps;
    float yinc=dy/steps;

    float x=ax1;
    float y=ay1;
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    for(int i=0;i<=steps;i++){
        x=x+xinc;
        y=y+yinc;
        glColor3f(.0,0.5,0.0);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }
    glFlush();

}
void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+cx, y+cy);
	glEnd();
}
void midPointCircleAlgo(int r)
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++;
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}
void midPointCircleAlgo2(int r2)
{
	int x = 0;
	int y = r2;
	float decision = 5/4 - r2;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++;
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}
}
void display()
{
  glClearColor(0.0, 0.0,0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);

  int r1,r2;
  cout<<"Enter radius of inner circle"<<endl;
  cin>>r1;
  cout<<"Enter radius of outer circle"<<endl;
  cin>>r2;



  //circle2
  glColor3f (1.0, 1.0, 1.0);
  glPointSize(2.0);
  midPointCircleAlgo(r1);
  //circle1
  glColor3f (1.0, 1.0, 1.0);
  glPointSize(2.0);
  midPointCircleAlgo2(r2);

  //trian
  float x=sqrt(3);
  float a=r1*x;
  float b=400-a;
  float c=400+a;
  float d=400-r1;
  float e=400+2*r1;

  //glColor3f(1.0, 1.0, 1.0);
  //glPointSize(2.0);
  glColor3f (0.0, 0.0, 1.0);
  glPointSize(2.0);
  drawLine(b,d,c,d);
  drawLine(b,d,400.0,e);
  drawLine(c,d,400.0,e);



  glFlush();
}


void myinit()
{

	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);


  glLoadIdentity();
  gluOrtho2D(0.0,800,0.0,800);
}
int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(width,height);
  glutCreateWindow("7241_Priya");
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
  return 0;
}