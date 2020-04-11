#include <stdio.h>
#define r 5
#define c 5
void sumrows(int a[][c])
{
    int sum;
    for(int i=0;i<r;i++)
    {
        sum=0;
        for(int j=0;j<c;j++)
        {
            sum+=a[i][j];
        }
        printf("sum of row %d:%d\n",i+1,sum);
    }
}
int main()
{
    int pin[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) {
          printf("pin[%d][%d]:",i,j);
          scanf("%d",&pin[i][j]);
          printf("\n");
        }
    }
    sumrows(pin);
}