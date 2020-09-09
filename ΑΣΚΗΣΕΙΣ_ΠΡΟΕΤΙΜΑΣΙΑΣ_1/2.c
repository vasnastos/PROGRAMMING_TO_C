#include <stdio.h>
int mysum(int a,int b)
{
    int sum=0;
    for(int i=a;i<=b;i++)
    {
        if(i%2==0)
        {
            sum+=i;
        }
    }
    return sum;
}

int main()
{
    int a,b;
    printf("Give number a:");
    scanf("%d",&a);
    printf("Give number b:");
    scanf("%d",&b);
    printf("Sum of even numbers between %d and %d is %d\n",a,b,mysum(a,b));
    return 0;
}