#include<stdio.h>
#include<stdlib.h>

int overThreshold(int *x, int N, int T1, int T2)
{
    int counter=0;

    for(int i=0;i<N;i++)
    {
        if(x[i]>=T1 && x[i]<=T2)
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    int size, start_val, finish_val;
    printf("Give number of positions for vector: \n");
    scanf("%d",&size);
    int *x = (int *)malloc(size * sizeof(int));
    for(int i=0;i<size;i++)
    {
        printf("Give value for vector of position %d: \n",i+1);
        scanf("%d",&x[i]);
    }
    printf("Give starting value: \n");
    scanf("%d",&start_val);
    printf("Give finishing value: \n");
    scanf("%d",&finish_val);
    
    printf("There are %d values between the limits",overThreshold(x,size,start_val,finish_val));

    free(x);
    return 0;
}