#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodela1 = NULL;
GLMmodel * pmodela2 = NULL;
GLMmodel * pmodela3 = NULL;
GLMmodel * pmodela4 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
float x=0,y=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if( pmodela1 == NULL){
        pmodela1 = glmReadOBJ("data/data/body.obj");
        glmUnitize( pmodela1 );
        glmFacetNormals( pmodela1 );
        glmVertexNormals( pmodela1 , 90);
    }
        if( pmodela2 == NULL){
        pmodela2 = glmReadOBJ("data/data/hand.obj");
        glmUnitize( pmodela2 );
        glmFacetNormals( pmodela2 );
        glmVertexNormals( pmodela2 , 90);
    }

        if( pmodela3 == NULL){
        pmodela3 = glmReadOBJ("data/data/leg.obj");
        glmUnitize( pmodela3 );
        glmFacetNormals( pmodela3 );
        glmVertexNormals( pmodela3 , 90);
    }

        if( pmodela4 == NULL){
        pmodela4 = glmReadOBJ("data/data/head.obj");
        glmUnitize( pmodela4 );
        glmFacetNormals( pmodela4 );
        glmVertexNormals( pmodela4 , 90);
    }

glPushMatrix();
    glTranslatef(0,x,0);

    glPushMatrix();///head
        glTranslatef(0,0.5,0);
        glScalef(0.15,0.15,0.15);
        glRotatef(y,0,0,0);
      ///  glColor3f(1,0.5,1);
        glmDraw(pmodela4,GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///body
        glScalef(0.4,0.4,0.4);
      ///  glColor3f(0,0,0.3);
        glmDraw(pmodela1,GLM_TEXTURE);
        //glTranslatef(0,10,0);
    glPopMatrix();

    glPushMatrix();///rhands
        glTranslatef(0.2,0.4,0);
        glRotatef(250,0,0,1);
        glTranslatef(-0.135,0,0);
        glRotatef(90,0,0,1);
        glScalef(0.5,0.5,0.5);
      ///  glColor3f(1,1,0);
        glmDraw(pmodela2,GLM_TEXTURE);
        glPushMatrix();///ruhands
            glTranslatef(-0.01,0.35,0);
            glRotatef(-angle*2,0,0,1);
            glTranslatef(0,0.3,0);
          ///  glColor3f(1,0.5,0.6);
            glmDraw(pmodela2,GLM_TEXTURE);
        glPopMatrix();
    glPopMatrix();

   glPushMatrix();///lhands
        glTranslatef(-0.2,0.4,0);
        glRotatef(-70,0,0,1);
        glTranslatef(-0.135,0,0);
        glRotatef(90,0,0,1);
        glScalef(0.5,0.5,0.5);
     ///   glColor3f(1,1,0);
        glmDraw(pmodela2,GLM_TEXTURE);
        glPushMatrix();///luhands
            glTranslatef(-0.01,0.35,0);
            glRotatef(angle*2,0,0,1);
            glTranslatef(0,0.3,0);
      ///      glColor3f(1,0.5,0.6);
            glmDraw(pmodela2,GLM_TEXTURE);
        glPopMatrix();
    glPopMatrix();


    glPushMatrix();///rleg
        glTranslatef(0.15,-0.4,0);
        glRotatef(-70,0,0,1);
        glTranslatef(0.135,0,0);
        glRotatef(90,0,0,1);
        glScalef(0.5,0.5,0.5);
      ///  glColor3f(1,1,0);
        glmDraw(pmodela3,GLM_TEXTURE);
        glPushMatrix();///rdleg
            glTranslatef(0.01,-0.35,0);
            glRotatef(-angle*2,0,0,1);
            glTranslatef(0,0.3,0);
     ///       glColor3f(1,0.5,0.6);
            glmDraw(pmodela2,GLM_TEXTURE);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///lleg
        glTranslatef(-0.15,-0.4,0);
        glRotatef(-110,0,0,1);
        glTranslatef(0.135,0,0);
        glRotatef(90,0,0,1);
        glScalef(0.5,0.5,0.5);
   ///     glColor3f(1,1,0);
        glmDraw(pmodela3,GLM_TEXTURE);
        glPushMatrix();///ldleg
            glTranslatef(0.01,-0.35,0);
            glRotatef(angle*2,0,0,1);
            glTranslatef(0,0.3,0);
   ///         glColor3f(1,0.5,0.6);
            glmDraw(pmodela2,GLM_TEXTURE);
        glPopMatrix();
    glPopMatrix();

glPopMatrix();
    x+=0.005;
    y+=0.001;
    if(x>2.2) x=-1.8;

    glutSwapBuffers();
    angle+=1;

}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12_TRT_HW");
    glutInitWindowSize(200,200);

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    myTexture("sunset.jpg");
    glutMainLoop();
}
