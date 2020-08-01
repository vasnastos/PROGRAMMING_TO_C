#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void deleteboard(char **n,int *d,int cnt)
{
    free(d);
    for(int i=0;i<cnt;i++)
    {
        free(n[i]);
    }
    free(n);
}
int main()
{
    FILE *fp;
    char fn[100];
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    if(fp==NULL)
    {
        perror("wrong input file!!!");
    }
    int cnt=0;
    char line[255];
    while(fgets(line,255,fp)!=NULL)
    {
        cnt++;
    }
    fclose(fp);
    char **name;
    int *dexterity;
    name=(char **)malloc(cnt * sizeof(char *));
    dexterity=(int *)malloc(cnt * sizeof(int));
    for(int i=0;i<cnt;i++)
    {
        name[i]=(char *)malloc(cnt * sizeof(char));
    }
    fp=fopen(fn,"r");
    char dex[20];
    char nam[20];
    int k=0;
    while(fgets(line,255,fp)!=NULL)
    {
        int cnt1=0,cnt2=0;
        int comma=0;
        for(int i=0;i<strlen(line);i++)
        {
           if(line[i]==',') comma++;
           else if(comma==0 && line[i]!=',')
           {
              nam[cnt1]=line[i];
              cnt1++;
            }
            else if(comma==1 && line[i]!=',')
             {
               dex[cnt2]=line[i];
               cnt2++;
             }
            else continue;
        }
        nam[cnt1]='\0';
        sprintf(name[k],"%s",nam);
        dex[cnt]='\0';
        dexterity[k]=atoi(dex);
        k++;
    }
    fclose(fp);
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<cnt-1;j++)
        {
            if(dexterity[j]>dexterity[j+1])
            {
                int t=dexterity[j];
                dexterity[j]=dexterity[j+1];
                dexterity[j+1]=t;
                char temp[20];
                strcpy(temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],temp);
            }
        }
    }
    fp=fopen(fn,"a");
    fprintf(fp,"After sort\n");
    for(int i=0;i<cnt;i++)
    {
        fprintf(fp,"%s,%d\n",name[i],dexterity[i]);
    }
    fclose(fp);
    deleteboard(name,dexterity,cnt);
}