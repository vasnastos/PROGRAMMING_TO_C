#include <stdio.h>
void swap(int *k,int *l)
{
    int t=*k;
    *k=*l;
    *l=t;
}
void swapd(double *k,double *l)
{
    double t=*k;
    *k=*l;
    *l=t;
}
int main()
{
    int x1,x2;
    double y1,y2;
    printf("Dwse akeraia timi:");
    scanf("%d",&x1);
    printf("Dwse akeraia timi:");
    scanf("%d",&x2);
    printf("dwse dekadiki timi:");
    scanf("%lf",&y1);
    printf("dwse dekadiki timi:");
    scanf("%lf",&y2);
    printf("Before swap::\n");
    printf("X1=%d\n",x1);
    printf("X2=%d\n",x2);
    printf("Y1=%lf\n",y1);
    printf("Y2=%lf\n",y2);
    swap(&x1,&x2);
    swapd(&y1,&y2);
    printf("After swap::\n");
    printf("X1=%d\n",x1);
    printf("X2=%d\n",x2);
    printf("Y1=%.2lf\n",y1);
    printf("Y2=%.2lf\n",y2);
}