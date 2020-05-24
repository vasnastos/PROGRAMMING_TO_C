#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    char name[100];
    int id;
    double grades[2];
}student;
int main()
{
    char line[100];
    student *students;
    int size=0;
    FILE *fp;
    fp=fopen("students.txt","r");
    if(fp==NULL)
    {
        printf("file did not found");
        exit(EXIT_FAILURE);
    }
    //int a,char nam[100],double x1,x2
    //fscanf(fp,"%d-%s-%lf-%lf",&a,&nam,&x1,&x2)
     while(fgets(line,100,fp)!=NULL)
     {
         size++;
     }
     fclose(fp);
     int i=0;
     students=(student *)malloc(size *sizeof(student));
     fp=fopen("students.txt","r");
     while(fgets(line,100,fp)!=NULL)
     {
         char *token=strtok(line,"-");
         students[i].id=atoi(token);
         token=strtok(NULL,"-");
         strcpy(students[i].name,token);
         token=strtok(NULL,"-");
         students[i].grades[0]=atof(token);
         token=strtok(NULL,"-");
         students[i].grades[1]=atof(token);
         i++;
     }
     fclose(fp);
}