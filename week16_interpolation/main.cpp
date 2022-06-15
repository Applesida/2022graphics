///week15_angle_TRT_again
///�ק�� week14_angles_fprintf_fscanf
#include <GL/glut.h>
#include <stdio.h>
float NewAngle[20], OldAngle[20];
float angle[20], oldX=0;
int angleID=0;
FILE * fout = NULL, * fin = NULL;
void myWrite(){///�C�I�s�@��myWrite()
    if( fout == NULL ) fout = fopen("file.txt", "w+");

    for(int i=0; i<20; i++){
        printf("%.1f ", angle[i] );///�p�¦L�X��
        fprintf(fout, "%.1f ", angle[i] );///�ɮצL�X��
    }///�L�X20�ӼƦr
    printf("\n");///�C�I�s�@��, �p�¸���
    fprintf(fout, "\n");///�C�I�s�@��, �ɮפ]����
}///�o�̦Ѯv�S��fclose
void myRead(){
    if( fout != NULL ) { fclose(fout); fout=NULL; }
    if( fin == NULL ) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        OldAngle[i]=NewAngle[i];
        fscanf(fin, "%f", &NewAngle[i] );
    }
    glutPostRedisplay();///���e�e��
}
void myInterpolate(float alpha)
{
    for (int i=0;i<20;i++){
        angle[i]=alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
    }
}
float alpha=0;
int t=0;
void keyboard(unsigned char key, int x, int y){
    if( key=='p' ){
            if(t%30==0) myRead();
        myInterpolate(alpha);
        glutPostRedisplay();
        t++;
    }
    if( key=='s' ) myWrite();///�զn�ʧ@,�~Save�s��
    if( key=='r' ) myRead();
    if( key=='0' ) angleID=0;
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle[angleID] += (x-oldX);
    ///myWrite();
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf( 0.3, 0.5,  -0.3, -0.5);

    glPushMatrix();
        glTranslatef( 0.3,  0.4, 0);
        glRotatef(angle[0], 0,0,1);
        glTranslatef(-0.3, -0.4, 0);
        glColor3f(1,0,0);
        glRectf( 0.3, 0.5,  0.7, 0.3);

        glPushMatrix();
            glTranslatef( 0.7,  0.4, 0);
            glRotatef(angle[1], 0,0,1);
            glTranslatef(-0.7, -0.4, 0);
            glColor3f(0,1,0);
            glRectf( 0.7, 0.5, 1.0, 0.3);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,  0.4, 0);
        glRotatef(angle[2], 0,0,1);
        glTranslatef(+0.3, -0.4, 0);
        glColor3f(1,0,0);
        glRectf(-0.3, 0.5, -0.7, 0.3);

        glPushMatrix();
            glTranslatef(-0.7,  0.4, 0);
            glRotatef(angle[3], 0,0,1);
            glTranslatef(+0.7, -0.4, 0);
            glColor3f(0,1,0);
            glRectf(-0.7, 0.5,-1.0, 0.3);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week15 angles TRT again");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}