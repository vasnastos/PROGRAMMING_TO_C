#include <stdio.h>
#define r 5
#define c 5
float maxgrade(float l[][c],int pos)
{ 
    //έστω γραμμές φοιτητές-στήλες μαθήματα
    int max=l[0][pos];
    for(int i=1;i<r;i++)
    {
      if(l[i][pos]>max)
      max=l[i][pos];
    }
    return max;
}
float Average(float l[][c],int pos)
{
    float sum=0.0;
    for(int i=0;i<r;i++)
    {
        sum+=l[i][pos];
    }
    return sum/r;
}
int main()
{
    float pin[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Give pin[%d][%d]:",i,j);
            scanf("%f",&pin[i][j]);
        }
    }
    for(int j=0;j<c;j++)
    {
        printf("lesson %d details::\n",j+1);
        printf("MAX_GRADE:%.2f\n",maxgrade(pin,j));
        printf("AVERAGE_GRADE:%.2f\n",Average(pin,j));
    }
}