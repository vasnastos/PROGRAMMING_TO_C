#include <stdio.h>
#define r 3
#define c 3
float Average(int a[][c])
{
    int s=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            s+=a[i][j];
        }
    }
    return (float)s/(1.0*r*c);
}
int main()
{
    int pin[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Give pin[%d][%d]:",i,j);
            scanf("%d",&pin[i][j]);
        }
    }
    printf("Average of board=%.3f\n",Average(pin));
}