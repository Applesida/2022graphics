#include <GL/glut.h>
#include <stdio.h>
float angle[20] , oldx=0;///angle變陣列以致可以放更多選轉角度
int angleID=0;///0號關節 1號關節
FILE * fout = NULL ,  *fin = NULL;
void myWrite()
{

    if ( fout == NULL ) fout = fopen("file.txt", "w+");
    for (int i=0;i<20;i++){
        printf("%.1f ", angle[i]);///小黑印出來
        fprintf(fout , "%.1f " , angle[i] );///檔案印出來
    }
    printf("\n");///每次呼叫一次 小黑跳行
    fprintf(fout , "\n");///每呼叫一次 檔案也跳行
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
void keyboard(unsigned char key , int x  , int y)///根據按數字鍵多少決定第幾個關節要轉動
{ ///按數字鍵決定要改變哪個angleID
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
    angle[angleID]+=(x-oldx);///angle變成陣列
    oldx=x;
    myWrite();
    glutPostRedisplay();///請glut重新re display
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);
    glRectf( 0.3,0.5, -0.3,-0.5);

    glPushMatrix();
        glTranslatef(0.3,0.4,0);///
        glRotatef(angle[0],0,0,1);///旋轉 對Z軸轉 ///angle[0] 第一個值
        glTranslatef(-0.3,-0.4,0);///把手臂選轉中心放世界中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);///右手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0);;///(3)拉回到右上角
            glRotatef(angle[1],0,0,1);///(2)旋轉角度  ///angle[1] 第二個值
            glTranslatef(-0.7,-0.4,0);///(1)將軸心放到世界中心
            glColor3f(0,1,10);
            glRectf(0.7 , 0.5 , 1.0 , 0.3);///右上手臂
        glPopMatrix();
    glPopMatrix();

///左手跟右手的X軸相反，所以要加負號
    glPushMatrix();
        glTranslatef(-0.3,0.4,0);///
        glRotatef(angle[2],0,0,1);///旋轉 對Z軸轉  ///angle[2] 第三個值
        glTranslatef(0.3,-0.4,0);///把手臂選轉中心放世界中心
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.7,0.3);///左手臂

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///(3)拉回到左上角
            glRotatef(angle[3],0,0,1);///(2)旋轉角度  ///angle[3] 第四個值
            glTranslatef(0.7,-0.4,0);///(1)將軸心放到世界中心
            glColor3f(0,1,10);
            glRectf(-0.7 , 0.5 , -1.0 , 0.3);///左上手臂
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
