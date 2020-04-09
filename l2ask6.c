#include <stdio.h>
#define r 3
#define c 3
void changevalue(int a[][c],int i,int j,int pr)
{
    if(i<0 || i>r || j<0 || j>c)
    {
        perror("no such column or row in the board");
    }
    else
    {
        a[i][j]=pr;
        for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("pin[%d][%d]:%d\n",i,j,a[i][j]);
        }
    }
 
    }
    
}
int main()
{
    int pin[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("give pin[%d][%d]:",i,j);
            scanf("%d",&pin[i][j]);
        }
    }
    int p1,p2,value;
    printf("give row you want to modify:");
    scanf("%d",&p1);
    printf("give column you want to modify:");
    scanf("%d",&p2);
     printf("give value:");
    scanf("%d",&value);
    changevalue(pin,p1,p2,value);
}