#include <windows.h>
#include <stdio.h>
int main()
{
    PlaySound("07042111.wav" , NULL , SND_ASYNC);
    while (1){
        printf("½Ð¿é¤J¼Æ¦r: ");
        int n;
        scanf("%d",&n);
        if(n==1) PlaySound("do.wav",NULL,SND_ASYNC);
        if(n==2) PlaySound("re.wav",NULL,SND_ASYNC);
        if(n==3) PlaySound("mi.wav",NULL,SND_ASYNC);
    }
}
