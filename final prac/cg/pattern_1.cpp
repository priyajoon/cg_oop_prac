#include<windows.h>
#include<bits/stdc++.h>
#include <GL/glut.h>
#include<math.h>
using namespace std;
int width = 800, height = 800;
int cx=400,cy=400;
float r=142;


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

void drawLine(int ax1,int ay1,int ax2,int ay2){
    int dx=ax2-ax1;
    int dy=ay2-ay1;
    int steps=0.0;
    if(abs(dx)>abs(dy)){
        steps=dx;
    }
    else{
        steps=dy;
    }
    double xinc=dx/steps;
    double yinc=dy/steps;

    int x=ax1;
    int y=ay1;
    glPointSize(3.0);
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
void display()
{
  glClearColor(0.0, 0.0,0.0, 0.0);

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  int x1,y1,x2,y2;
  cout<<"Enter the coordinates"<<endl;
  cin>>x1>>y1>>x2>>y2;

  //rect
  drawLine(x1,y1,x2,y1);
  drawLine(x1,y1,x1,y2);
  drawLine(x1,y2,x2,y2);
  drawLine(x2,y1,x2,y2);

  //rho
  int newx=(x1+x2)/2;
  int newy=(y1+y2)/2;
  drawLine(newx,y1,x1,newy);
  drawLine(x1,newy,newx,y2);
  drawLine(x2,newy,newx,y2);
  drawLine(newx,y1,x2,newy);
  //rectangle
  /*drawLine(200,600,600,600); //upline
  drawLine(200,200,600,200);//down line
  drawLine(200,200,200,600);//left
  drawLine(600,200,600,600);//right line(newx,y2,x2,newy)
  glLineWidth(2);
  //rhombus
  glColor3f(1.0, 1.0, 0.0);
  drawLine(400,200,200,400);
  drawLine(400,200,600,400);
  drawLine(600,400,400,600);
  drawLine(200,400,400,600);*/
  //circle
  int a=x1-newx;
  int b=newy-y1;
  int c=pow(a,2);
  int d=pow(b,2);
  int e=c+d;
  float g=sqrt(e);
  float rad=g/2;
  glColor3f (1.0, 1.0, 1.0);
  glPointSize(2.0);
  midPointCircleAlgo(rad);




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
  glutCreateWindow("7241_Priya_pat2");
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
  return 0;
}
