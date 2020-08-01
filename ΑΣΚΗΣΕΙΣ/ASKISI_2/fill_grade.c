#include <stdio.h>
#include <stdlib.h>
#define r 5
#define c 5
int main()
{
    fflush(stdin);
    int **pin;
    pin=(int **)malloc(r * sizeof(int *));
    for(int i=0;i<r;i++)
    {
        pin[i]=(int *)malloc(c * sizeof(int));
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            pin[i][j]=rand()%3;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("res[%d][%d]:%d\t",i,j,pin[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<r;i++)
    free(pin[i]);
    free(pin);
}