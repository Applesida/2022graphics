#include <stdio.h>
int main()
{///�ɮ׫���  fout  �}���ɮ�(�ɦW , �g)
    FILE * fout = fopen("file.txt", "w+");
    fprintf(fout,"3.1415926\n");
    fclose(fout);///�����ɮ�

    float angle=0;
    FILE * fin = fopen("file.txt", "r");
    fscanf(fin , "%f", &angle);
    printf("Ū��F����:%f",angle);
    fclose(fin);
}
