#include<stdio.h>
#include<stdlib.h>

int findMult(int *x, int N, int K)
{
    int counter = 0;
    for(int i=0;i<N;i++)
    {
        if((x[i]%K)==0)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    int size;
    int K;
    printf("Give number of positions for vector: \n");
    scanf("%d",&size);
    int *x = (int *)malloc(size * sizeof(int));
    for(int i=0;i<size;i++)
    {
        printf("Give value for position %d of vector: \n",i+1);
        scanf("%d",&x[i]);
    }
    printf("Give a number to find the multiplies: \n");
    scanf("%d",&K);

    printf("The vector has %d multiplies of the given number !",findMult(x,size,K));
    
    free(x);

    return 0;
}