#include <opencv/highgui.h>
int main()
{
    IplImage *img = cvLoadImage("1.jpg");
    cvShowImage("week09",img);
    cvWaitKey(0);
}
