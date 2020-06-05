#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char filename[100];

int replaceChar(char *str)
{
    int counter=0;
    for(int i=0,k=strlen(str);i<k;i++)
    {
        if(str[i]==' ')
        {
            str[i]='_';
            counter++;
        }
    }
    return counter;
}

int getsize()
{
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        return 0;
    }
    char line[100];
    int counter=0;
    while(fgets(line,100,fp)!=NULL)
    {
      counter++;
    }
    fclose(fp);
    return counter;
}


void execute_space(int *data,int size)
{
   FILE *fp=fopen(filename,"r");
   char line[100];
   int i=0;
   while(fgets(line,100,fp)!=NULL)
   {
      data[i]=replaceChar(line);
      printf("%s",line);
      i++;
   }
   fclose(fp);
}

int main()
{
    strcpy(filename,"textdemo.txt");
    int size=getsize();
    if(size==0)
    {
        printf("File does not exist");
        exit(EXIT_FAILURE);
    }
    int *data=(int *)calloc(size,sizeof(int));
    execute_space(data,size);
    FILE *fp=fopen(filename,"a");
    fprintf(fp,"\n");
    fprintf(fp,"REPLACE SPACES PER LINE\n");
    for(int i=0;i<size;i++)
    {
       fprintf(fp,"Line_%d:%d\n",i+1,data[i]);
    }
    fclose(fp);
    free(data);
}