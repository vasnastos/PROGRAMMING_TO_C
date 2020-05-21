#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ms 100
typedef struct 
{
    char reg[ms];
   char color[ms];
   char constructor[ms];
   int date;
}car;
int getsize()
{
    int cnt=0;
    FILE *fp;
    char fn[100];
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    if(fp==NULL)
    {
        return 0;
    }
    char line[100];
    while(fgets(line,100,fp))
    {
        cnt++;
    }
    fclose(fp);
    return cnt;
}
void readfromfile(car *cars)
{
    FILE *fp;
    char fn[100];
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    char x1[100],x2[100],x3[100];
    int dt;
    int i=0;
    while(fscanf(fp,"%s %s %s %d",x1,x2,x3,dt)>0)
    {
        strcpy(cars[i].reg,x1);
        strcpy(cars[i].color,x2);
        strcpy(cars[i].constructor,x3);
        cars[i].date=dt;
        i++;
    }
    fclose(fp);
}
double precentover2006(car *cars,int size)
{
    int cnt=0;
    for(int i=0;i<size;i++)
    {
       if(cars[i].date==2006)
       {
           cnt++;
       }
    }
    return ((double)cnt/size)*100.0;
}
void find_difference(car *cars,int size)
{
    int cnt=0;
    int cnt1=0;
    for(int i=0;i<size;i++)
    {
        if(cars[i].date==2004)
        {
            cnt++;
        }
        if(cars[i].date==2005)
        {
            cnt1++;
        }
    }
    if(cnt>cnt1)
    {
      printf("more cars on 2004\n");
      printf("difference between 2004 and 2005 %d\n",cnt-cnt1);
    }
    else
    {
      printf("more cars on 2004\n");
      printf("difference between 2004 and 2005 %d\n",cnt1-cnt);
    }
}
int main()
{
    int size=getsize();
    if(size==0)
    {
        printf("No file found!!\n");
        return 0;
    }
    car *cars=(car *)malloc(size * sizeof(car));
    readfromfile(cars);
    precentover2006(cars,size);
    find_difference(cars,size);
}