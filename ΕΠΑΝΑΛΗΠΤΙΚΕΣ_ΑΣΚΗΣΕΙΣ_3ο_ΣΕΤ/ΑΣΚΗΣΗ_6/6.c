#include<stdio.h>
#include<stdlib.h>

int findNumbers(int *x, int N)
{
    int counter=0;
    for(int i=0;i<N;i++)
    {
        if((x[i]%3)==0 && (x[i]%5)==0)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    int size;
    printf("Give number of positions for vector:");
    scanf("%d",&size);
    int *x = (int *)malloc(size * sizeof(int));
    for(int i=0;i<size;i++)
    {
        printf("Give value for vector of position %d:", i+1);
        scanf("%d",&x[i]);
    }

    printf("There are %d numbers from vector that divide perfectly with 3 and 5", findNumbers(x,size));

    free(x);
    return 0;
}