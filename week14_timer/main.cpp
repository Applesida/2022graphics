#include <stdio.h>
#include <GL/glut.h>
void timer(int t)
{
    printf("起床,現在時間 : %d\n",t);
}
void display()
{

}
int main(int argc ,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14 timer");

    glutTimerFunc(1000,timer,1);
    glutTimerFunc(2000,timer,2);
    glutTimerFunc(3000,timer,3);
    glutDisplayFunc(display);
    glutMainLoop();
}
