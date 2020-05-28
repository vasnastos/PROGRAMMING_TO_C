#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    char name[100];
    char id[9];
    double grade[2];
}student;
char filename[100];
int getsize()
{
    int cnt=0;
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL) return 0;
    char line[100];
    while(fgets(line,100,fp)!=NULL)
    {
        cnt++;
    }
    fclose(fp);
    return cnt;
}

void readfile(student *students)
{
    FILE *fp;
    fp=fopen(filename,"r");
    char line[100];
    int i=0;
    while(fgets(line,100,fp)!=NULL)
    {
        char *token=strtok(line,"-");
        strcpy(students[i].id,token);
        token=strtok(NULL,"-");
        strcpy(students[i].name,"-");
        token=strtok(NULL,"-");
        students[i].grade[0]=atof(token);
        token=strtok(NULL,"-");
        students[i].grade[1]=atof(token);
        i++;
    }
    fclose(fp);
}

void findaverage(double *av,student *students,int size)
{
   for(int i=0;i<size;i++)
   {
       av[i]=0.0;
       for(int j=0;j<2;j++)
       av[i]+=students[i].grade[j];
       av[i]/=2.0;
   }
}

void savepass(student *students,int size,double *av,int *cnt)
{
    FILE *fp;
    fp=fopen(filename,"w");
    fprintf(fp,"PASS STUDENTS\n");
    for(int i=0;i<size;i++)
    {
        if(av[i]>5.0 && students[i].grades[0]>5.0 && students[i].grade[1]>5.0)
        {
            fprintf(fp,"ID:%s \t NAME:%s\n",students[i].id,students[i].name);
            *cnt++;
        }
    }
    fclose(fp);
}

void savefail(student *students,int size,double *av,int *cnt)
{
    FILE *fp;
    fp=fopen(filename,"w");
    fprintf(fp,"FAIL STUDENTS\n");
    for(int i=0;i<size;i++)
    {
        if(av[i]<5.0 || (students[i].grades[0]<5.0 && students[i].grade[1]<5.0))
        {
            fprintf(fp,"ID:%s \t NAME:%s\n",students[i].id,students[i].name);
            *cnt++;
        }
    }
    fclose(fp);
}

int main()
{
    printf("Give filename:");
    gets(filename);
    int size=getsize();
    student *students=(student *)malloc(size * sizeof(student));
    readfile(students);
    double *average=(double *)malloc(size * sizeof(double));
    findaverage(average,students,size);
    int cntpass=0,cntfail=0;
    savepass(students,size,average,&cntpass);
    savefail(students,size,average,&cntfail);
    print("SUCCESS:%.2lf\n",((double)cntpass/size)*100.0);
    print("Fail:%.2lf\n",((double)cntfail/size)*100.0);   
}