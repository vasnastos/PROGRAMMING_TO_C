#include <stdio.h>
#include <stdlib.h>
void swapint(int *a,int *b)
{
    int *temp=(int *)malloc(sizeof(int));
    *temp=*a;
    *a=*b;
    *b=*temp;
    free(temp);
}
void swapfloat(float *a,float *b)
{
    float *temp=(float *)malloc(sizeof(float));
    *temp=*a;
    *a=*b;
    *b=*temp;
    free(temp);
}
int main(int argc,char **argv) //g++ test1.c - o test test 5 argv[0]="test" argv[1]="5"
{
  int x1,x2;
  float y1,y2;
  printf("x1=");
  scanf("%d",&x1);//x1
  printf("x2=");
  scanf("%d",&x2);
  printf("Y1=");
  scanf("%f",&y1);
  printf("Y2=");
  scanf("%f",&y2);
  swapint(&x1,&x2);
  swapfloat(&y1,&y2);
  printf("X1=%d \t X2=%d\n",x1,x2);
  printf("Y1=%f \t Y2=%f\n",y1,y2);
}