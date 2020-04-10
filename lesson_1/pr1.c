#include <stdio.h>
#define size 10
int sum(int a[])
{
    int s=0;
    for(int i=0;i<size;i++)
    {
        s+=a[i];
    }
    return s;
}
int main()
{
    int a[size];
    for(int i=0;i<size;i++)
    {
        printf("Give a[%d]:",i);
        scanf("%d",&a[i]);
        printf("\n");
    }
    printf("sum of board=%d\n",sum(a));
    return 0;
}