///week13_rect_many_TRT
#include <GL/glut.h>
float angle[4] , oldx=0;
int angleID=0;///0號關節 1號關節
void keyboard(unsigned char key , int x  , int y)
{
    if (key=='0') angleID=0;
    if (key=='1') angleID=1;
    if (key=='2') angleID=2;
    if (key=='3') angleID=3;
}
void mouse(int button , int state , int x ,int y)
{
    oldx=x;
}
void motion (int x, int y)
{
    angle[angleID]+=(x-oldx);
    oldx=x;
    glutPostRedisplay();///請glut重新re display
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);
    glRectf( 0.3,0.5, -0.3,-0.5);

    glPushMatrix();
        glTranslatef(0.3,0.4,0);///
        glRotatef(angle[0],0,0,1);///旋轉 對Z軸轉
        glTranslatef(-0.3,-0.4,0);///把手臂選轉中心放世界中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);

        glPushMatrix();
            glTranslatef(0.7,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,10);
            glRectf(0.7 , 0.5 , 1.0 , 0.3);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.4,0);///
        glRotatef(angle[2],0,0,1);///旋轉 對Z軸轉
        glTranslatef(0.3,-0.4,0);///把手臂選轉中心放世界中心
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.7,0.3);

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);
            glRotatef(angle[3],0,0,1);
            glTranslatef(0.7,-0.4,0);
            glColor3f(0,1,10);
            glRectf(-0.7 , 0.5 , -1.0 , 0.3);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("week13_rect_TRT");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
