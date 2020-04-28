#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double average(double p[],int size)
{
    double av=0.0;
    for(int i=0;i<size;i++)
    {
        av+=p[i];
    }
    return av/size*1.0;
}
void function(double *x,int size,double *max,double *rate)
{
    int cnt=0;
    *max=*x;
    for(int i=0;i<size;i++)
    {
        if(*(x+i)>5.0) cnt++;
        if(*(x+i)>*max) *max=*(x+i);
    }
    *rate=((double)cnt/size)*100.0;
}
void sort(double *gr,char n[][20],int s)
{
    for(int i=0;i<s;i++)//s=strlen(n);
    {
        for(int j=0;j<s-1;j++)
        {
            if(gr[j]>gr[j+1])
            {
                double t=gr[j];
                gr[j]=gr[j+1];
                gr[j+1]=t;
                char t1[20];
                strcpy(t1,n[j]);
                strcpy(n[j],n[j+1]);
                strcpy(n[j+1],t1);
            }
        }
    }
}
int main()
{
    int *x=(int *)malloc(sizeof(int));
    printf("give number of students:");
    scanf("%d",x);
    char names[*x][20];
    double grades[*x];
    fflush(stdin);
    for(int i=0;i<*x;i++)
    {
        printf("Give name of student_%d:",i+1);
        gets(names[i]);
        printf("\n");
    }
    for(int i=0;i<*x;i++)
    {
        printf("Give grade of %s:",names[i]);
        scanf("%lf",&grades[i]);
        printf("\n");
    }
    sort(grades,names,*x);
    printf("List of class results::\n");
    printf("NAME \t GRADE\n");
    for(int i=0;i<*x;i++)
    {
        printf("%s \t %.2lf\n",names[i],grades[i]);
    }
    printf("class average grade:%lf\n",average(grades,*x));
    double sr,max;
    function(grades,*x,&max,&sr);
    printf("Max grade:%lf\n",max);
    printf("Success ratio:%lf\n",sr);
    free(x);
    return 0;
}