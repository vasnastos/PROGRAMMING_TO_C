#include <stdio.h>
#include <stdlib.h>
#define r 3
#define c 3 
void function(float **a,float *max,float *min,float *avg)
{
    for(int i=0;i<r;i++)
    {
        *(max+i)=a[i][0];
        *(min+i)=a[i][0];
        *(avg+i)=a[i][0];
        for(int j=1;j<c;j++)
        {
            avg[i]+=a[i][j];
           if(*(a[i]+j)>max[i]) 
           {
               max[i]=a[i][j];
           }
           if(*(a[i]+j)<min[i]) 
           {
               min[i]=a[i][j];
           }
        }
        avg[i]/=c;
    }
}
int main()
{
    float **pin=(float **)malloc(r * sizeof(float *));
    for(int i=0;i<r;i++)
    {
        pin[i]=(float *)malloc(c * sizeof(float));
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("pin[%d][%d]:",i,j);
            scanf("%f",&pin[i][j]);
        }
    }
    float mx[r];
    float mn[r];
    float average[r];
    function(pin,mx,mn,average);//average==&average[0]
    for(int i=0;i<r;i++)
    {
        printf("ROW %d:::\t",i);
        printf("Max=%.2f\t",mx[i]);
        printf("Min=%.2f\t",mn[i]);
        printf("Avg=%.2f\n",average[i]);
    }
    for(int i=0;i<r;i++)
    {
        free(pin[i]);
    }
    free(pin);
}