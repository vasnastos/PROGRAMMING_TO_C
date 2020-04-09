#include <stdio.h>
#define r 5
#define c 5
int maxrowelement(int a[][c],int pos)
{
    int p=0;
    int max=a[pos][0];
    for(int i=1;i<c;i++)
    {
        if(a[pos][i]>max)
        {
            max=a[pos][i];
            p=i;
        }
    }
    return p;
}
int main()
{
    int pin[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("pin[%d][%d]:",i,j);
            scanf("%d",&pin[i][j]);
        }
    }
    int pel;
    printf("Give position of row:");
    scanf("%d",&pel);
    if(pel<0 || pel>r)
    printf("Wrong input the is no %d row in the table");
    else
    {
        printf("Max element of row %d in column:",pel,maxrowelement(pin,pel));
    }
    
}