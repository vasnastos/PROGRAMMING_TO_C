#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ms 100
const double p=3.1415;
char filename[ms];
typedef struct{
    double radious;
}circle;
double getvolume(circle *c)
{
  return p * c->radious* c->radious;
}
double perimeter(circle *c)
{
    return 2*p* c->radious;
}
int getsize()
{
    //έλεγχος εγκυρότητας δεδομένων!!!!
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("No such file found");
        return 0;
    }
    char line[ms];
    int cnt;
    int size=0;
    while(fgets(line,ms,fp)!=NULL)
    {
        cnt=0;
        if(line[strlen(line)-1]=='\n' && strlen(line)>1) line[strlen(line)-1]='\0';
        if(line[0]=='\n') continue;
        if(line[0]=='#') continue;
       char *token=strtok(line,"=");
       if(token==NULL) continue;
       token=strtok(NULL,"=");
       if(token==NULL) continue;
       for(int i=0;i<strlen(token);i++)
       {
           if((token[i]<='0' && token[i]>='9') && token[i]!='.')
           {
               cnt=1;
               break;
           }
       }
       if(atof(token)==0.0 || cnt==1) continue;
       size++;
    }
    fclose(fp);
    return size;
}
void readdata(circle *circles)
{
    FILE *fp;
    fp=fopen(filename,"r");
    int cnt;
    char line[ms];
    int i=0;
    while(fgets(line,ms,fp)!=NULL)
    {
        cnt=0;
        if(line[strlen(line)-1]=='\n' && strlen(line)>1) line[strlen(line)-1]='\0';
        if(line[0]=='\n') continue;
        if(line[0]=='#') continue;
       char *token=strtok(line,"=");
       token=strtok(NULL,"=");
       printf("%s\n",token);
       for(int i=0;i<strlen(token);i++)
       {
           if((token[i]<='0' && token[i]>='9') && token[i]!='.')
           {
               cnt=1;
               break;
           }
       }
       if(atof(token)==0.0 || cnt==1) continue;
       circles[i].radious=atof(token)/2.0;
       i++;
    }
}
void savetofile(circle *circles,int size)
{
    FILE *fp;
    fflush(stdin);
    char file[ms];
    printf("give filename:");
    gets(file);
    fp=fopen(file,"w");
    fprintf(fp,"RADIUS \t VOLUME \t PERIMETER\n");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"%d \t %.2lf \t %.2lf\n",circles[i].radious,getvolume(circles+i),perimeter(circles+i));
    }
    fclose(fp);
}
int main()
{
    printf("Give filename:");
    gets(filename);
    int size=getsize();
    printf("%d",size);
    if(size==0) 
    {
        return 0;
    }
    circle *circles=(circle *)malloc(size * sizeof(circle));
    readdata(circles);
    savetofile(circles,size);
    free(circles);
    exit(EXIT_SUCCESS);
}