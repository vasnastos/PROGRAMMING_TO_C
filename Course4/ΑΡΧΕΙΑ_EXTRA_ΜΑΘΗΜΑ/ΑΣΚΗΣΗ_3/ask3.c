#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 200
void read_content(char *fn)
{
    FILE *fp;
    char line[100];
    fp=fopen(fn,"r");
    if(fp==NULL)
    {
        printf("no such file found");
        return;
    }
    int cnt=0;
    char **lines;
    while(fgets(line,100,fp)!=NULL)
    {
       cnt++;
    }
    fclose(fp);
    lines=(char **)malloc(cnt * sizeof(char *));
    for(int i=0;i<cnt;i++)
    {
        lines[i]=(char *)malloc(maxsize * sizeof(char));
    }
    fp=fopen(fn,"r");
    int i=0;
    while(fgets(line,100,fp))
    {
        if(line[strlen(line)-1]=='\n')  line[strlen(line)-1]='\0';
        strcpy(lines[i],line);
        i++;
    }
    fclose(fp);
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<strlen(lines[i]);j++)
        {
            if(lines[i][j]>='a' && lines[i][j]<='z')
            {
                lines[i][j]-=32;
            }
        }
    }
    fclose(fp);
    fp=fopen(fn,"w");
    for(int i=0;i<cnt;i++)
    {
        fprintf(fp,"%s\n",line[i]);
    }
    fclose(fp);
}
void display(char *n)
{
   FILE *fp;
   fp=fopen(n,"r");
   char line[100];
   while(fgets(n,100,fp)!=NULL)
   {
       printf("%s",line);
   }
   fclose(fp);
}
int main()
{
    int choice;
    while(1)
    {
        printf("1-IN UPPER\n");
        printf("2-DISPLAY\n");
        printf("3-EXIT\n");
        printf("Give choice:");
        scanf("%d",&choice);
        fflush(stdin);
        char fn[100];
        printf("give filename:");
        gets(fn);
        if(choice==1)
        {
            read_content(fn);
        }
        else if(choice==2)
        {
            display(fn);
        }
        else if(choice==3)
        {
            break;
        }
        else
        {
            printf("invalid choice!!\n");
        }   
    }
}