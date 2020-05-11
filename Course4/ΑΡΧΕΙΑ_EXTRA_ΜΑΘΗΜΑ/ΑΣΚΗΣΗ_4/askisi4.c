#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int getsize(char *fn)
{
   FILE *fp;
   fp=fopen(fn,"r");
   int cnt=0;
   char line[100];
   if(fp==NULL) return cnt;
   while(fgets(line,100,fp)!=NULL)
   {
       cnt++;
   }
   fclose(fp);
   return cnt;
}
void fillTable(char *fn,char **name,double *sal)
{
    FILE *fp;
    fp=fopen(fn,"r");
    char line[100];
    int j=0;
    while(fgets(line,100,fp)!=NULL)
    {
        line[strlen(line)-1]='\0';
       int cnt1=0,cnt2=0,comma=0;
       char n[100],s[100];
       for(int i=0;i<strlen(line);i++)
       {
           if(line[i]==',') comma++;
           if(comma==0 && line[i]!=',')
           {
               n[cnt1]=line[i];
               cnt1++;
           }
           if(comma==1 && line[i]!=',')
           {
               s[cnt2++]=line[i];
           }
       }
       n[cnt1]='\0';
       s[cnt2]='\0';
       strcpy(name[j],n);
       s[j]=atof(s);
       j++;
    }
}
void sort(char *fn)
{
   int cnt=getsize(fn);
   char **name;
   double *salary;
   name=(char **)malloc(cnt * sizeof(char *));
   salary=(double *)malloc(cnt * sizeof(double));
   for(int i=0;i<cnt;i++)
   {
       name[i]=(char *)malloc(100 * sizeof(char));
   }
   fillTable(fn,name,salary);
   for(int i=0;i<cnt;i++)
   {
       if(salary[i]>salary[i+1])
       {
           double s=salary[i];
           salary[i]=salary[i+1];
           salary[i+1]=s;
           char t[100];
           strcpy(t,name[i]);
           strcpy(name[i],name[i+1]);
           strcpy(name[i+1],t);
       }
   }
   FILE *fp;
   fp=fopen(fn,"w");
   for(int i=0;i<cnt;i++)
   {
       fprintf(fp,"%s-%.2lf\n",name[i],salary[i]);
   }
   fclose(fp);
}

void search(char *productname, char *filename)
{
    FILE *fp;
    fp=fopen(filename,"r");
    char n[100];
    double s;
    int found=0;
    while(fscanf(fp,"%s-%lf",&n,&s)>0)
    {
        if(strcmp(n,productname)==0)
        {
            found=1;
            printf("PRODUCT FOUND!!!");
            printf("NAME:%s \t PRICE:%.2lf\n",n,s);
        }
    }
    fclose(fp);
    if(found==0)
    {
        printf("product doesn't exist in database\n");
    }
}

void insert(char *newproduct, double price, char *filename)
{
   FILE *fp;
   fp=fopen(filename,"a");
   fprintf(fp,"%s-%.2lf\n",*newproduct,price);
   fclose(fp);
}

int main()
{
    double x;
    int choice;
    char fn[100];
    printf("Give filename you want to use:");
    gets(fn);
    while (1)
    {
        printf("PRODUCT BASE MENU::\n");
        printf("1-SORT\n");
        printf("2-SEARCH\n");
        printf("3-INSERT\n");
        printf("4_EXIT BASE\n");
        printf("Give choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            sort(fn);
        }
        else if (choice == 2)
        {
            char name[100];
            printf("Give name of product you want to search:");
            gets(name);
            search(name,fn);
        }
        else if (choice == 3)
        {
            char pn[100];
            double price;
            fflush(stdin);
            printf("Give name of new product:");
            gets(pn);
            printf("Give price of new product:");
            scanf("%lf", &price);
            insert(pn, price,fn);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("invalid choice!!\n");
        }
    }
}