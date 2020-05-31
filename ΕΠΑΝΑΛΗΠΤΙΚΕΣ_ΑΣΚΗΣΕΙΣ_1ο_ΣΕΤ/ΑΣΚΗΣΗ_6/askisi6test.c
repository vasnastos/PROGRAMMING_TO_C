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
     while(fgets(line,100,fp)!=NULL)//fscanf(fp,"%d-%s-%lf-%lf",&students[i].id,&students[i].name,&students[i].grades[0],&students[i].grades[1])
     {
         if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
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
     int cntsuccess=0;
     int cntfail=0;
     char filename[100];
     printf("Give filename:");
     gets(filename);
     fp=fopen(filename,"w");
     for(int i=0;i<size;i++)
     {
         if(((students[i].grades[0]+students[i].grades[1])/2)>=5.0)
         {
             fprintf(fp,"%d--%s\n",students[i].id,students[i].name);
             cntsuccess++;
         }
     }
     fclose(fp);
     //fail αρχειο.
     printf("Give filename:");
     gets(filename);
     fp=fopen(filename,"w");
     for(int i=0;i<size;i++)
     {
         if(((students[i].grades[0]+students[i].grades[1])/2)<5.0)
         {
             fprintf(fp,"%d--%s\n",students[i].id,students[i].name);
             cntfail++;
         }
     }
     fclose(fp); 
     printf("SUCCESS:%d\n",cntsuccess);
     printf("Fail:%d\n",cntfail);
}