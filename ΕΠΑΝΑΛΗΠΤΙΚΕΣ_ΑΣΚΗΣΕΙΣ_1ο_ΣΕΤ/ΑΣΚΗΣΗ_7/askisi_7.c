#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b;
    printf("Give first number:");
    scanf("%d",&a);
    printf("Give second number:");
    scanf("%d",&b);
    int *p,*p1,*p2;
    p=&a;
    p1=&b;
    p2=(int *)malloc(sizeof(int));
    *p2=a+1;
    int sum=0;
    while(*p2<*p1)
    {
        sum+=*p2;
        (*p2)++;
    }
    printf("Sum between %d and %d is %d\n",*p,*p1,sum);
    free(p);
    free(p1);
    free(p2);
}