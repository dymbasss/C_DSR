#include "header.h"
#define N 100
char mass[N], mass2[N];

int main ()
{
    FILE *fp;
    char *name = "/home/fox/DSR/Konk/String";   

    fp = fopen(name,"r");
    if(fp == NULL)
        exit(1);
    int i = 0;


    fgets(mass, N, fp);
    fgets(mass2, N, fp);

    for(i; i < 3; i++)
    {
        printf("%c", mass[i]);
    }
    
    int k = strcmp(mass, mass2);


   /* printf("%s", mass);
    printf("%s", mass2);
    printf("\n%d", k);*/

    
    getchar();   
}