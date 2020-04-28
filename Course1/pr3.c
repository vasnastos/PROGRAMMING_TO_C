#include <stdio.h>
#define size 10
int count_if(int a[],int x)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(a[i]==x)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int k[size];
    for(int i=0;i<size;i++)
    {
        printf("Give k[%d]:",i);
        scanf("%d",&k[i]);
        printf("\n");
    }
    printf("Give search element:");
    int search;
    scanf("%d",&search);
    int times=count_if(k,search);
    if(times==0)
    printf("NOT SUCH AN ELEMENT FOUND IN BOARD");
    else 
    printf("element %d found at the board %d times",search,times);
    return 0;
}