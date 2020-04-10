#include <stdio.h>
#define size 10
double max(double x[])
{
    double m=x[0];
    for(int i=1;i<size;i++)
    {
        if(x[i]>m)
         m=x[i];
    }
    return m;
}
double Average(double y[])
{
    double avg=0.0;
    for(int i=0;i<size;i++)
    {
        avg+=y[i];
    }
    return avg/size;
}
int main()
{
    double a[size];
    for(int i=0;i<size;i++)
    {
        printf("Give a[%d]:",i);
        scanf("%lf",&a[i]);
        printf("\n");
    }
    printf("MAX ELEMENT:%.3lf\n",max(a));
    printf("AVERAGE=%.3lf\n",Average(a));
    return 0;
}