#include <GL/glut.h>
#include <stdio.h>
float angle[20] , oldx=0;///angle�ܰ}�C�H�P�i�H���h���ਤ��
int angleID=0;///0�����` 1�����`
FILE * fout = NULL ,  *fin = NULL;
void myWrite()
{

    if ( fout == NULL ) fout = fopen("file.txt", "w+");
    for (int i=0;i<20;i++){
        printf("%.1f ", angle[i]);///�p�¦L�X��
        fprintf(fout , "%.1f " , angle[i] );///�ɮצL�X��
    }
    printf("\n");///�C���I�s�@�� �p�¸���
    fprintf(fout , "\n");///�C�I�s�@�� �ɮפ]����
}
void myRead()
{
    if (fout != NULL) {
        fclose(fout);
        fout=NULL;
    }
    if (fin ==NULL ) fin = fopen("file.txt","r");
    for (int i=0;i<20;i++){
        fscanf(fin , "%f" ,&angle[i]) ;
    }
    glutPostRedisplay();
}
void keyboard(unsigned char key , int x  , int y)///�ھګ��Ʀr��h�֨M�w�ĴX�����`�n���
{ ///���Ʀr��M�w�n���ܭ���angleID
    if (key=='r') myRead();
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
    angle[angleID]+=(x-oldx);///angle�ܦ��}�C
    oldx=x;
    myWrite();
    glutPostRedisplay();///��glut���sre display
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);
    glRectf( 0.3,0.5, -0.3,-0.5);

    glPushMatrix();
        glTranslatef(0.3,0.4,0);///
        glRotatef(angle[0],0,0,1);///���� ��Z�b�� ///angle[0] �Ĥ@�ӭ�
        glTranslatef(-0.3,-0.4,0);///����u���त�ߩ�@�ɤ���
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);///�k���u

        glPushMatrix();
            glTranslatef(0.7,0.4,0);;///(3)�Ԧ^��k�W��
            glRotatef(angle[1],0,0,1);///(2)���ਤ��  ///angle[1] �ĤG�ӭ�
            glTranslatef(-0.7,-0.4,0);///(1)�N�b�ߩ��@�ɤ���
            glColor3f(0,1,10);
            glRectf(0.7 , 0.5 , 1.0 , 0.3);///�k�W���u
        glPopMatrix();
    glPopMatrix();

///�����k�⪺X�b�ۤϡA�ҥH�n�[�t��
    glPushMatrix();
        glTranslatef(-0.3,0.4,0);///
        glRotatef(angle[2],0,0,1);///���� ��Z�b��  ///angle[2] �ĤT�ӭ�
        glTranslatef(0.3,-0.4,0);///����u���त�ߩ�@�ɤ���
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.7,0.3);///�����u

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///(3)�Ԧ^�쥪�W��
            glRotatef(angle[3],0,0,1);///(2)���ਤ��  ///angle[3] �ĥ|�ӭ�
            glTranslatef(0.7,-0.4,0);///(1)�N�b�ߩ��@�ɤ���
            glColor3f(0,1,10);
            glRectf(-0.7 , 0.5 , -1.0 , 0.3);///���W���u
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("week13_rect_many_TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
}
