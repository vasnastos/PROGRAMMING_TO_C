#include <stdio.h>
unsigned int factorial(int i)
{
    int s=1;
    for(int j=1;j<=i;j++)
    {
        s*=i;
    }
    return s;
}
int main()
{

    int pin[10];
    for(int i=0;i<10;i++)
    {
        printf("Give number:");
        scanf("%d",&pin[i]);
        printf("\n");

    }
    for(int i=0;i<10;i++)
    {
        printf("FACTORIAL of %d is %ld\n",pin[i],factorial(pin[i]));
    }
}