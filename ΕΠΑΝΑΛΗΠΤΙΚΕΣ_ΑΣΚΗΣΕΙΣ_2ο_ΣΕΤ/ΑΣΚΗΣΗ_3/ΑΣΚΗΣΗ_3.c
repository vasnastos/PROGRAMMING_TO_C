#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    char name[100];
    char lastname[100];
    int age;
    double sales[3];
}empl;
char fn[100];

int getsize()
{
    FILE *fp=fopen(fn,"r");
    char line[100];
    int cnt=0;
    if(fp==NULL)
    {
        return 0;
    }
    while(fgets(line,100,fp)!=NULL)
    {
        if(line[0]='\n') continue;
        if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
        if(line[0]=='#')
        {
            continue;
        }
        cnt++;
    }
    fclose(fp);

    return cnt;
}

void readata(empl *employees)
{
    FILE *fp;
    fp=fopen(fn,"r");
    char line[100];
    int i=0;
    while(fgets(line,100,fp)!=NULL)
    {
        char *token=strtok(line,"-");
        strcpy(employees[i].name,token);
        token=strtok(NULL,"-");
        strcpy(employees[i].lastname,token);
        token=strtok(NULL,"-");
        employees[i].age=atoi(token);
        token=strtok(NULL,"-");
        int j=0;
        while(token!=NULL)
        {
            employees[i].sales[j]=atof(token);
            token=strtok(NULL,"-");
            j++;
        }
        i++;
    }
}

void find_total_average(empl *employees,int size,double *avg)
{
    for(int j=0;j<size;j++)
    {
        avg[j]=0.0;
        for(int i=0;i<size;i++)
        {
            avg[j]+=employees[i].sales[j];
        }
        *(avg+j)/=size;
    }
}

void find_max(empl *employees,int size,empl *max)
{
    for(int j=0;j<3;j++)
    {
        *(max+j)=employees[0];
        for(int i=1;i<size;i++)
        {
            if(employees[i].sales[j]>max[j].sales[j])
            {
                max[j]=employees[i];
            }
        }
    }
}

int main()
{
    int size=getsize();
    if(size==0)
    {
        printf("Error  file found!!!!\n");
        exit(EXIT_FAILURE);
    }
    empl *employees;
    employees=(empl *)malloc(size * sizeof(empl));
    readata(employees);
    double avg[3];
    empl maxperdate[3];
    find_total_average(employees,size,avg);
    find_max(employees,size,maxperdate);
    for(int i=0;i<sizeof(avg)/sizeof(avg[0]);i++)
    {
        printf("%d year average:%.2lf\n",i+1,avg[i]);
    }
    for(int i=0;i<sizeof(maxperdate)/sizeof(maxperdate[0]);i++)
    {
        printf("%d years max:%.2lf\n",i+1,maxperdate[i]);
    }
}