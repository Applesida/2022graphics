#include <stdio.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;
int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();

    printf("隨便等你輸入數字，不然程式就要結束囉");
    int n;
    scanf("%d",&n);
}
