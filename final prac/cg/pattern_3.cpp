#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,500.0,0.0,500.0);
}
void line1(int x1,int y1,int x2,int y2)
{
   int dx=(x2-x1);
  int dy=(y2-y1);
  float m=(1.0*dy/dx);
  if(abs(dx)>=abs(dy))
  {
      if(x1<x2)
      {
       float yold=y1;
        for(int i=x1;i<=x2;i++)
        {
           glBegin(GL_POINTS);
			glVertex2i(i,round(yold));
			glEnd();
			glFlush();
           yold=yold+m;
           
        }
      }
      else
      {
        float yold=y1;
        for(int i=x1;i>=x2;i--)
        {
           glBegin(GL_POINTS);
			glVertex2i(i,round(yold));
			glEnd();
			glFlush();
           yold=yold-m;
           
        }
      }
   }

      else
      {
        if(y1<y2)
        {
        float xold=x1;
        for(int i=y1;i<=y2;i++)
        {
           
           glBegin(GL_POINTS);
			glVertex2i(round(xold),i);
			glEnd();
			glFlush();
         
            xold=xold+(1/m);
        }
        }
        else
        {
          float xold=x1;
        for(int i=y1;i>=y2;i--)
        {
           
          glBegin(GL_POINTS);
			glVertex2i(round(xold),i);
			glEnd();
			glFlush();
         
            xold=xold-(1/m);
        }
       }
      }
  
 }

void pattern(void)
{

  glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
  int x1,y1,x2,y2;
  cout<<"Enter the coordinates"<<endl;
  cin>>x1>>y1>>x2>>y2;
 
  line1(x1,y1,x2,y1);
  line1(x1,y1,x1,y2);
  line1(x1,y2,x2,y2);
  line1(x2,y1,x2,y2);
  int newx=(x1+x2)/2;
  int newy=(y1+y2)/2;
  line1(x1,newy,newx,y1);
  line1(x1,newy,newx,y2);
  line1(newx,y2,x2,newy);
  line1(newx,y1,x2,newy);
  int x1new,x2new,y1new,y2new;
  x1new=(x1+newx)/2;
  x2new=(x2+newx)/2;
  y1new=(y1+newy)/2;
  y2new=(y2+newy)/2;
  line1(x1new,y1new,x2new,y1new);
  line1(x1new,y1new,x1new,y2new);
  line1(x1new,y2new,x2new,y2new);
  line1(x2new,y2new,x2new,y1new);

}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
 	glutCreateWindow("");
	init();
	glutDisplayFunc(pattern);
	glutMainLoop();
 
  
}
