#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ms 100
typedef struct 
{
    char *model;
    char *brand;
    int year;
    double price;
}car;
int find_array_size()
{
    FILE *fp;
    int cnt=0;
    char fn[ms],line[ms];
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    if(fp==NULL)
    {
        perror("NO SUCH FILE FOUND!!\n");
        return -1;
    }
    while(fgets(line,ms,fp)!=NULL)
    {
        cnt++;
    }
    fclose(fp);
    return cnt;
}
void split_string(char *s,car *c)
{
  int size=strlen(s);
  int cnt1=0;
  int cnt2=0;
  int cnt3=0,cnt4=0;
  char yr[ms],pr[ms];
  int comma=0;
  for(int i=0;i<size;i++)
  {
     if(s[i]==',') comma++;
     else if(s[i]!=',' && comma==0)
     {
         c->brand[cnt1]=s[i];
         cnt1++;
     }
     else if(s[i]!=',' && comma==1)
     {
         c->model[cnt2]=s[i];
         cnt2++;
     }
     else if(s[i]!=',' && comma==2)
     {
         yr[cnt3]=s[i];
         cnt3++;
     }
     else if(s[i]!=',' && comma==3)
     {
         pr[cnt4]=s[i];
         cnt4++;
     }
     else
     {
         break;
     }   
  }
  c->brand[cnt1]='\0';
  c->model[cnt2]='\0';
  yr[cnt3]='\0';
  pr[cnt4]='\0';
  c->year=atoi(yr);
  c->price=atof(pr);   
}
void readdata(car *cars)
{
    FILE *fp;
    char fn[ms],line[ms];
    printf("give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    int i=0;
    while(fgets(line,ms,fp)!=NULL)
    {
        split_string(line,&cars[i]);
        i++;
    }
    fclose(fp);
}
void sortbyyear(car *cars,int size)
{
  for(int i=0;i<size;i++)
  {
      for(int j=0;j<size-1;j++)
      {
          if(cars[j].year>cars[j+1].year)
          {
              //swap brand!!!!
              char b[ms];
              strcpy(b,cars[j].brand);
              strcpy(cars[j].brand,cars[j+1].brand);
              strcpy(cars[j+1].brand,b);
              //swap model!!!
              char m[ms];
              strcpy(m,cars[j].model);
              strcpy(cars[j].model,cars[j+1].model);
              strcpy(cars[j+1].model,m);
              //swap year
              int y=cars[j].year;
              cars[j].year=cars[j+1].year;
              cars[j+1].year=y;
              //swap price
              double pr=cars[j].price;
              cars[j].price=cars[j+1].price;
              cars[j+1].price=pr;
          }
      }
  }   
}
void savetofile(car *cars,int size)
{
   FILE *fp;
   char fn[ms];
   printf("Give filename:");
   gets(fn);
   fp=fopen(fn,"w");
   for(int i=0;i<size;i++)
   {
       fprintf(fp,"%s,%s,%d,%.2lf\n",cars[i].brand,cars[i].model,cars[i].year,cars[i].price);
   }
   fclose(fp);
}
void freememory(car *cars,int size)
{
   for(int i=0;i<size;i++)
   {
       free(cars[i].brand);
       free(cars[i].model);
   }
}
int main()
{
    int size=find_array_size();
    car cars[size];
    for(int i=0;i<size;i++)
    {
        cars[i].brand=(char *)malloc(ms * sizeof(char));
        cars[i].model=(char *)malloc(ms * sizeof(char));
    }
    readdata(cars);
    sortbyyear(cars,size);
    savetofile(cars,size);
    freememory(cars,size);   
}