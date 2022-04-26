#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <GL/glut.h>
#include <opencv/cv.h>
#include "glm.h"///使用3d模型
GLMmodel * pmodel = NULL;
GLUquadric * sphere = NULL; ///指標 ，指到二次曲面
int myTexture(char * filename)

{

    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖

    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)

    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能

    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID

    glGenTextures(1, &id); /// 產生Generate 貼圖ID

    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);

    return id;

}
float angle = 0;
void display()

{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(angle ,0, 1, 0);
        if ( pmodel==NULL){
        pmodel=glmReadOBJ("data_Gundam/Gundam.obj");
        glmUnitize(pmodel); ///使用3D模型 ,縮放到-1...+1才看的到
        glmFacetNormals(pmodel);///使用3d模型，面的法向量
        glmVertexNormals(pmodel,90); ///使用3D模型，頂點的法向量
      }
      glmDraw(pmodel , GLM_TEXTURE);
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.3;

}

int main(int argc , char**argv)

{

    glutInit( &argc , argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week10_texture_model");

    glEnable(GL_DEPTH_TEST);

    glutIdleFunc(display);

    glutDisplayFunc(display);

    myTexture("data_Gundam/Diffuse.jpg");///輸入圖片名稱

    ///sphere=gluNewQuadric();///準備好二次曲面

    glutMainLoop();



}
