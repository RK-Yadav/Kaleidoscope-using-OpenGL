#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

int width=700,height=600;
int p[3],q[3],m,n,p1,q1;
float r=0,g=0.8,b=0.2;

void draw(int x,int y)
{    glLineWidth(5.0);
      glColor3f(r,g,b);
    glBegin(GL_LINE_STRIP);
     glVertex2i(p1,q1);
     glVertex2i(x,y);
    glEnd();
    glFlush();
    p1=x;q1=y;

}
void Redraw(int x,int y,int i)
{
    glPointSize(5.0);
    glColor3f(r,g,b);
    glBegin(GL_LINE_STRIP);
     glVertex2i(p[i],q[i]);
     glVertex2i(x,y);
    glEnd();
    glFlush();
    p[i]=x;q[i]=y;

}

void my_display()
{

}

void myinit()
{   srand(time(NULL));
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width/2,width/2,-height/2,height/2);
    glFlush();

}
int i;
void Menu(int p)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void my_click(int b,int s,int x,int y)
{
    if(b==GLUT_LEFT_BUTTON && s==GLUT_UP)
        i=0;

     glutCreateMenu(Menu);
        glutAddMenuEntry("Clear",1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void selectcolor(int x,int y)
{   int s=abs(x)/50;
    int t=abs(y)/50;

    if(s==0 && t==0)
        r=1.0,g=0.0,b=1.0;
    else if(s==1 && t==1)
        r=0.0,g=0.0,b=1.0;
    else if(s==2 && t==2)
        r=0.5,g=0.5,b=1.0;
    else if(s==3 && t==3)
        r=0.0,g=1.0,b=0.0;
    else if(s==4 && t==4)
        r=0.2,g=0.8,b=0.0;
    else if(s==5 && t==5)
        r=0.8,g=0.2,b=0.2;
    else
        r=1.0,g=0.0,b=0.0;

}

void my_mouse(int x,int y)
{
   m=x-width/2;
   n=height/2-y;

    if(i==0)
       {
           p1=m;q1=n;
           p[0]=-m;q[0]=-n;
           p[1]=m;q[1]=-n;
           p[2]=-m;q[2]=n;
       }
        //r= rand()%2+1;r--;
        //g= rand()%2+1;g--;
        //b= rand()%2+1;b--;

    selectcolor(m,n);

    draw(m,n);
    Redraw(-m,-n,0);
    Redraw(m,-n,1);
    Redraw(-m,n,2);
    i++;

}

int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(5,5);
    glutInitWindowSize(width,height);
    glutCreateWindow("Drawing");

    glutDisplayFunc(my_display);
    glutMotionFunc(my_mouse);
   glutMouseFunc(my_click);
    myinit();
    glutMainLoop();

    return 0;
}
