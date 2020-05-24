#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
typedef struct {
    char cityname[100];
    char country[100];
    size_t population;
}city;
char filename[100];
int getsize()
{
    int cnt=0;
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        return 0;
    }
    char line[100];
    while(fgets(line,100,fp)!=NULL)
    {
        if(line[0]=='#' || line[0]=='\n') continue;
        cnt++;
    }
    fclose(fp);
    return cnt;
}
void readdata(city *cities)
{
    int i=0;
    FILE *fp;
    fp=fopen(filename,"r");
    char line[100];
    while(fgets(line,100,fp)!=NULL)
    {
       if(line[0]=='#' || line[0]=='\n')
       continue;
       char *token=strtok(line,"-");
       strcpy(cities[i].cityname,token);
       token=strtok(NULL,"-");
       strcpy(cities[i].country,token);
       token=strtok(NULL,"-");
       cities[i].population=atoll(token); 
       printf("City:%s \t Country:%s \t Population:%u\n",cities[i].cityname,cities[i].country,cities[i].population);
      i++;
    }
}
void showcountries(city *cities,int size,char *cntr)
{
    
    bool x=false;
    for(int i=0;i<size;i++)
    {
      if(strcmp(cities[i].country,cntr)==0 )
      {
          x=true;
          printf("CITY:%s \t POPULATION:%s\n");
      }
    }
    if(x==false)
    {
        printf("No such country:%s exist\n",cntr);
    }
}

void save_to_file(city *cities,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(cities[j].population>cities[j+1].population)
            {
                city temp=cities[j];
                cities[j]=cities[j+1];
                cities[j+1]=temp;
            }
        }
    }
    FILE *fp;
    fp=fopen(filename,"a");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"City:%s \t Country:%s \t Population:%u\n",cities[i].cityname,cities[i].country,cities[i].population);
    }
    fclose(fp);
}
int main()
{
    printf("Give filename:");
    gets(filename);
    int size=getsize();
    city *cities;
    cities=(city *)malloc(size * sizeof(city));
    readdata(cities);
    showcountries(cities,size,"greece");
    save_to_file(cities,size);
}