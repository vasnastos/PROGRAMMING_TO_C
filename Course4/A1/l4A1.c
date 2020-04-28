#include <stdio.h>
#include <stdlib.h>
int getsize()
{
    FILE *fp;
    char fn[100];
    printf("Give filename:");
    gets(fn);
    float x;
    int cnt=0;
    fp=fopen(fn,"r");
    while(fscanf(fp,"%f",&x)==1)
    {
       cnt++;
    }
    fclose(fp);
    return cnt;
}
void readdata(float *a,int size)
{
   FILE *fp;
    char fn[100];
    printf("Give filename:");
    gets(fn);
    float x;
    fp=fopen(fn,"r");
    int i=0;
    while(fscanf(fp,"%f",&x)==1)
    {
        a[i]=x;
        i++;
    }
    fclose(fp);
}
void function(float *a,int size,double *avg,double *precent)
{
    int sum=0;
    int cnt=0;
    for(int i=0;i<size;i++)
    {
        sum+=a[i];
        if(a[i]>5.0) cnt++;
    }
    *avg=(double)sum/size;
    *precent=((double)cnt/size)*100.0;
}
void run()
{
    double avg,prc;
    float *a;
    int x=getsize();
    a=(float *)malloc(x*sizeof(float));
    readdata(a,x);
    function(a,x,&avg,&prc);
    printf("Average grade:%.2lf\n",avg);
    printf("Pass precent:%.2lf\n",prc);
    free(a);
}
int main()
{
    run();
}