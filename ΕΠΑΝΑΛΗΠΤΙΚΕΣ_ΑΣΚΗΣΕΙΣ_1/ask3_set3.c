#include <stdio.h>
#include <string.h>
float average(float av[],int size)
{
  float s=0.0;
  for(int i=0;i<size;i++)
  {
      s+=av[i];
  }
  return s/size;
}
void countmax(float g[],char n[][40],int size)
{
    float max=g[0];
    for(int i=1;i<size;i++)
    {
        if(g[i]>max)
        {
            max=g[i];
        }
    }
    printf("TOP STUDENTS!! \n");
    for(int i=0;i<size;i++)
    {
        if(g[i]==max)
        {
            printf("ID:%s \t GRADE:%.2f\n",n[i],g[i]);
        }
    }
}
int cntpass(float gr[],int size)
{
    int cnt=0;
    for(int i=0;i<size;i++)
    {
        if(gr[i]>5)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int x;
    printf("Give number of students you want to store::");
    scanf("%d",&x);
    char names[x][40];
    char id[x][40];
    float grade[x];
    fflush(stdin);
    for(int i=0;i<x;i++)
    {
        printf("Give id of student_%d:",i+1);
        gets(id[i]);
        printf("\n");
    }
    for(int i=0;i<x;i++)
    {
         printf("Give name of student_%d:",i+1);
        gets(names[i]);
        printf("\n");
    }
    for(int i=0;i<x;i++)
    {
        printf("Give grade of student_%d:",i+1);
        scanf("%f",&grade[i]);
        printf("\n");
    }
    printf("LESSON INFO::\n");
    printf("AVERAGE GRADE:%.2f\n",average(grade,x));
    printf("%d Students pass the lesson!!\n",cntpass(grade,x));
    printf("Success ratio %.2lf",((double)cntpass(grade,x)/x)*100.0);
    countmax(grade,names,x);
    return 0;
}