#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void playchampionship(int **x,int r)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(i==j)
            {
                x[i][j]=-1;
            }
            else{
                x[i][j]=rand()%3;
            }
        }
    }
}
void returnres(int **x,int *wins,int *loses,int *ties,int r)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
           if(x[i][j]==1) wins[i]++;
           else if(*(x[i]+j)==2) loses[i]++;
           else if(*(x[i]+j)==0) ties[i]++;
           else continue;
        }
    }
    for(int j=0;j<r;j++)
    {
        for(int i=0;i<r;i++)
        {
           if(x[i][j]==2) wins[j]++;
           else if(*(x[i]+j)==1) loses[j]++;
           else if(*(x[i]+j)==0) ties[j]++;
           else continue;
        }
    }
}
void sorttable(char n[][20],int *g,int *wins,int *l,int *t,int r)
{
   for(int i=0;i<r;i++)
   {
       for(int j=0;j<r-1;j++)
       {
           if(*(g+j)<g[j+1])
           {
               int a=g[j];
               g[j]=g[j+1];
               g[j+1]=a;
               char t[20];
               strcpy(t,n[j]);
               strcpy(n[j],n[j+1]);
               strcpy(n[j+1],t);
               int w=wins[j];
               wins[j]=wins[j+1];
               wins[j+1]=w;
               int los=l[j];
               l[j]=l[j+1];
               l[j+1]=los;
               int tie=t[j];
               t[j]=t[j+1];
               t[j+1]=tie;
           }
       }
   }
}
void table(char n[][20],int *p,int *wins,int *l,int *t,int r)
{
    for(int i=0;i<r;i++)
    {
        p[i]=0;
    }
    for(int i=0;i<r;i++)
    {
        p[i]=(wins[i]*3)+t[i];
    }
    for(int i=0;i<r;i++)
    {
        printf("%d.%d\n",i,p[i]);
    }
    sorttable(n,p,wins,l,t,r);
}
int main()
{
    int **res;
    res=(int **)malloc(5 * sizeof(int *));
    for(int i=0;i<5;i++)
    {
        res[i]=(int *)malloc(5 * sizeof(int));
    }
    int *p;
    p=(int *)malloc(5*sizeof(int));
    char names[5][20];
    printf("Participants sign in::\n");
    for(int i=0;i<5;i++)
    {
        printf("Give of team_%d:",i);
        gets(names[i]);
    }
    int h=1;
    printf("Game starts::\n");
    char op[20];
    while(1)
    {
        printf("Start season?:");
        gets(op);
        if(strcmp(op,"y")==0)
        {
            printf("Season%d!!\n",h);
            playchampionship(res,5);
          for(int i=0;i<5;i++)
          {
            for(int j=0;j<5;j++)
            {
              printf("res[%d][%d]:%d\t",i,j,res[i][j]);
            }
            printf("\n");
          }
            int w[5]={0};
            int l[5]={0};
            int t[5]={0};
            returnres(res,w,l,t,5);
            table(names,p,w,l,t,5);
            printf("RANK \t TEAM \t POINTS\n");
            for(int i=0;i<5;i++)
            {
              printf("%d \t %s \t %d  \n",i+1,names[i],p[i]);
            }
            printf("CHAMPION!!!==>%s\n",names[0]);
            h++;
        }
        else break;
    }
    for(int i=0;i<5;i++)
    free(res[i]);
    free(res);
    free(p);
    return 0;
}