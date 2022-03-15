#include <GL/glut.h>
#include <stdio.h>
float angle=0 , oldX=0;
int mx[1000],my[1000];
int n=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for (int i=0;i<n;i++){
        glVertex2f( (mx[i]-150)/150.0 , -(my[i]-150)/150.0);
    }
    glEnd();
    glutSwapBuffers();
}
void motion(int x, int y)
{
     angle+=(x-oldX);
    oldX=x;
    display();
}
void mouse ( int button , int state , int x ,int y)
{
   if ( state==GLUT_DOWN ){
        printf("   glVertex2f( (%d-150)/150.0 , -(%d-150)/150.0);\n",x,y);
        n++;
        mx[n-1]=x;my[n-1]=y;
    }
}
int main(int argc , char**argv)
{
    glutInit( &argc , argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 Rotate");
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutMainLoop();

}
