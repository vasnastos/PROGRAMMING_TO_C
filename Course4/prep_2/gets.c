#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void funsplit(char data[],char n[],double *g)
{
    char word[20];
    int w1=0;
    char word1[20];
    int w2=0;
    int comma=0;
    for(int i=0;i<strlen(data);i++)
    {
       if(data[i]==',') comma++;
       if(comma==0 && *(data+i)!=',')
       {
           word[w1]=*(data+i);
           w1++;
       }
       else if(comma==1 && data[i]!=',')
       {
           word1[w2]=data[i];
           w2++;
       }
    }
    word[w1]='\0';
    word1[w2]='\0';
    strcpy(n,word);
    *g=atof(word1);
}
void  max_grade(double *g,int s,int *pm,int *check)
{
    double m=g[0];
   for(int i=1;i<s;i++)
   {
     if(g[i]>m)
     {
         m=g[i];
     }
   }
   int cnt=0;
   int p=-1;
   for(int i=0;i<s;i++)
   {
       if(g[i]==m)
       {
           p=i;
           cnt++;
       }
   }
   if(cnt==1)
   { 
     pm=(int *)malloc(sizeof(int));
     *pm=p;
   }
   else
   {
       pm=(int *)malloc(cnt*sizeof(int));
       int j=0;
       for(int i=0;i<s;i++)
       {
           if(g[i]==m)
           {
               pm[j]=i;
               j++;
           }
       }
   } 
   *check=cnt;
}
double average(double *g,int s)
{
    double sum=0;
    for(int i=0;i<s;i++)
    {
        sum+=g[i];
    }
    return sum/s*1.0;
}
void executable()
{
    FILE *fp;
    char fn[20];
    printf("give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    if(fp==NULL) 
    {
        printf("No such file exists");
        return;
    }
    int linecount=0;
    char data[100];
    while(fgets(data,100,fp)!=NULL)
    {
        linecount++;
    }
    fclose(fp);
    char names[linecount][20];
    double grades[linecount];
    fp=fopen(fn,"r");
    for(int i=0;i<linecount;i++)
    {
        char filedata[100];
        fgets(filedata,100,fp);
        funsplit(filedata,names[i],&grades[i]);
    }
    fclose(fp);
    int *pm,check;
    fp=fopen(fn,"a");
    fprintf(fp,"AVERAGE OF CLASS=%.2lf\n",average(grades,linecount));
    max_grade(grades,linecount,pm,&check);
    if(check==1)
    {
        fprintf(fp,"Max GRADE:%s,%lf",names[*pm],grades[*pm]);
    }
    else
    {
        int i=0;
       while(i<check)
       {
          fprintf(fp,"Max GRADE:%s,%lf\n",names[pm[i]],grades[pm[i]]);      
          i++;
       }
    }
    fclose(fp);
    free(pm);   
}
int main()
{
    executable();
}