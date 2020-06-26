#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    char number[100];
    char color[100];
    char manufactioral[100];
    int year;
}car;
int getsize()
{
    FILE *fp;
    fp=fopen("cars.txt","r");
    if(fp==NULL)
    {
        return 0;
    }
    int cnt=0;
    char line[100];
    while(fgets(line,100,fp)!=NULL)
    {
        cnt++;
    }
    fclose(fp);
    return cnt;
}
void readdata(car *cars)
{
    FILE *fp;
    fp=fopen("cars.txt","r");
    int i=0;
    char line[100];
    while(fgets(line,100,fp)!=NULL)
    {
        char *token=strtok(line,"-");
        strcpy(cars[i].number,token);
        token=strtok(NULL,"-");
        strcpy(cars[i].color,token);
        token=strtok(NULL,"-");
        strcpy(cars[i].manufactioral,token);
        token=strtok(NULL,"-");
        cars[i].year=atoi(token);
        i++;
    }
    fclose(fp);
}
double precent2006(car *cars,int size)
{
    int cnt=0;
    for(int i=0;i<size;i++)
    {
        if(cars[i].year==2006)
        {
            cnt++;
        }
    }
    return (cnt/size*1.0)*100.0;
}
int diff2005_2004(car *cars,int size)
{
    int cnt2005=0;
    int cnt2004=0;
    for(int i=0;i<size;i++)
    {
       if(cars[i].year==2004)
       {
           cnt2004++;
       }
       if(cars[i].year==2005)
       {
           cnt2005++;
       }
    }
    return cnt2005-cnt2004;
}
int main()
{
    int size=getsize();
    car *cars=(car *)malloc(size * sizeof(car));
    readdata(cars,size);
    printf("precent munufactoring %lf\n",precent2006(cars,size));
    printf("diference=%d\n",diff2005_2004(cars,size));   
}