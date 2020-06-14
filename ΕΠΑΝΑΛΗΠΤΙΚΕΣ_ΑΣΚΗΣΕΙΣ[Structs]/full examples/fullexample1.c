#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char filename[100];

typedef struct
{
    int id;
    char fullname;
    double *grades;
}student;

int getfilesize()
{
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        return 0;
    }
    int counter=0;
    char line[100];
    while(fgets(line,100,fp)!=NULL)
    {
      if(line[0]=='#') continue;
      if(line[0]=='\n') continue;
      counter++;
    }
    fclose(fp);
    return counter;
}

void readdata(student *data,int *size)
{
    //Εύρεση πλήθους μαθημάτων ανά φοιτητή
    FILE *fp=fopen(filename,"r");
    char line[100];
    int i=0;
    while(fgets(line,100,fp)!=NULL)
    {
        if(line[0]=='#' || line[0]=='\n') continue;
        char *token=strtok(line,"-,");
        data[i].id=atoi(token);
        token=strtok(NULL,"-,");
        strcpy(data[i].fullname,token);
        int counter=0;
        while(token!=NULL)
        {
            token=strtok(NULL,"-,");
            counter++;
        }
        data[i].grades=(double *)malloc(counter * sizeof(double));
        i++;
    }
    fclose(fp);

    //Διάβασμα βαθμών από το αρχείο.
    i=0;
    fp=fopen(filename,"r");
    while(fgets(line,100,fp)!=NULL)
    {
        int counter=0;
        char *token=strtok(line,"-,");
        while(token!=NULL)
        {
            token=strtok(NULL,"-,");
            counter++;
            if(counter<2) continue;
            else
            {
                size[i]++;
            }
        }
        i++;
    }
    fclose(fp);
}

void readgrades(student *sts)
{
    char line[100];
    FILE *fp=fopen(filename,"r");
    int i=0,j;
    while(fgets(line,100,fp)!=NULL)
    {
        j=0;
        int counter=0;
        char *token=strtok(line,"-,");
        while(token!=NULL)
        {
            counter++;
            if(counter<=2)
            {
                continue;
            }
            else
            {
                sts[i].grades[j]=atof(token);
                j++;
            }
            token=strtok(NULL,"-,");
        }
        i++;
    }
    fclose(fp);
}

void getaverage(student *sts,int size,double *avg,int *sizet)
{
    for(int i=0;i<size;i++)
    {
        avg[i]=0.0;
        for(int j=0;j<sizet[i];j++)
        {
            avg[i]+=sts[i].grades[j];
        }
        avg[i]/=sizet[i];
    }
}

void passprecent(student *sts,int size,double *pass,int *sizet)
{
    for(int i=0;i<size;i++)
    {
        pass[i]=0.0;
        for(int j=0;j<sizet[i];i++)
        {
            pass[j]+=1.0;
        }
        pass[i]/=sizet[i];
        pass[i]*=100.0;
    }
}

void show(student *sts,int size,double *av,double *pass)
{
    for(int i=0;i<size;i++)
    {
        printf("ID:%d \t NAME:%s \t AVERAGE:%.2lf \t PASS:%.2lf\n",sts[i].id,sts[i].fullname,av[i],pass[i]);
    }
}

void deletetables(student *sts,int *size,double *avg,double *pr)
{
   free(sts);
   free(size);
   free(avg);
   free(pr);
}

int main()
{
    const int sizetab=getfilesize();
    if(sizetab==0)
    {
        printf("No such file exist!!!");
        exit(1);
    }
    int *size=(int *)malloc(sizetab * sizeof(int));
    student *students=(student *)malloc(sizetab * sizeof(student));
    readdata(students,sizetab,size);
    readgrades(students);
    double *average=(double *)malloc(sizetab * sizeof(double));
    double *passpr=(double *)malloc(sizetab * sizeof(double));
    getaverage(students,sizetab,average,size);
    passprecent(students,sizetab,passpr,size);
    show(students,sizetab,average,passprecent);
    deletetables(students,size,average,passprecent);
}