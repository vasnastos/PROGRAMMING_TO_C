#include <stdio.h>
#include <stdlib.h>
#define r 3
#define c 4
void function(float **a,float *mx,float *mn,float *av)
{
    for(int i=0;i<r;i++)
    {
       mx[i]=a[i][0];
       mn[i]=a[i][0];
       av[i]=a[i][0];
       for(int j=1;j<c;j++)
       {
           if(mx[i]<a[i][j]) mx[i]=a[i][j];
           if(mn[i]>a[i][j]) mn[i]=a[i][j];
           av[i]+=a[i][j];
       }
       av[i]/=c;
    }
}
int main()
{
    float **pin;
    float *max,*min,*avg;
    pin=(float **)malloc(r * sizeof(float *));
    max=(float *)malloc(r * sizeof(float));
    min=(float *)malloc(r * sizeof(float));
    avg=(float *)malloc(r * sizeof(float));
    for(int i=0;i<r;i++)
    {
        pin[i]=(float *)malloc(c * sizeof(float));
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Give pin[%d][%d]:",i,j);
            scanf("%f",&pin[i][j]);
        }
    }
    function(pin,max,min,avg);
    for(int i=0;i<r;i++)
    {
       printf("ROW %d:::\n",i+1);
       printf("MAX=%.2f\n",max[i]);
       printf("Min=%.2f\n",min[i]);
       printf("AVG=%.2f\n",avg[i]);
       printf("\n");
    }
    free(max);
    free(min);
    free(avg);

    for(int i=0;i<r;i++)
    free(pin[i]);
    free(pin);
}