#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ms 100
typedef struct 
{
    char name[ms];
    int semester;
}lesson;
typedef struct
{
    int id;
    char lessonname[ms];
    double grade;
}student;
char filename[ms];
void getsize(int *c1,int *c2)
{
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("No file found!!!\n");
        return;
    }
    int cnt=0;
    *c1=0,*c2=0;
    char line[ms];
    while(fgets(line,ms,fp)!=NULL)
    {
        if(line[0]=='#') 
        {
            cnt++;
            continue;
        }
        if(line[0]=='\n') continue;
        if(cnt==1)
        {
            *c1++;
        }
        else if(cnt==2)
        {
            *c2++;
        }
    }
    fclose(fp);
}
void readfile(student *students,lesson *lessons)
{
    int i=0;
    int j=0;
    FILE *fp;
    int status;
    fp=fopen(filename,"r");
    char line[ms];
    while(fgets(line,ms,fp)!=NULL)
    {
        if(line[0]=='\n') continue;
        if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
        if(strcmp(line,"#student")==0 || strcmp(line,"#STUDENT")==0)
        {
            status=0;
            continue;
        }
        else if(strcmp(line,"#LESSON")==0 || strcmp(line,"#LESSON")==0)
        {
            status=1;
            continue;
        }
        if(status==0)
        {
            char *spl=strtok(line,"-,");
            students[i].id=atoi(spl);
            spl=strtok(NULL,"-,");
            strcpy(students[i].lessonname,line);
            spl=strtok(NULL,"-,");
            students[i].grade=atof(spl);
            i++;
        }
        else
        {
           char *spl=strtok(line,"-,");
           strcpy(lessons[j].name,line);
           spl=strtok(NULL,"-,");
           lessons[j].semester=atoi(line);
           j++;
        }
    }
    fclose(fp);
}

void display_grades(lesson *lessons,int lsize,student *students,int stsize)
{
    for(int i=0;i<lsize;i++)
    {
        printf("######%s######\n",lessons[i].name);
        for(int j=0;j<stsize;i++)
        {
            if(strcmp(students[j].lessonname,lessons[i].name)==0)
            {
                printf("ID:%d \t GRADE:%.2lf\n",students[j].id,students[j].grade);
            }
        }
        printf("--------------------------------\n");
    }
}
void display_in_file_pass_precent(lesson *lessons,int lsize,student *students,int stsize)
{
    FILE *fp;
    fp=fopen(filename,"a");
    fprintf(fp,"\n");
    fprintf(fp,"RESULTS PER LESSON\n \n");
    for(int i=0;i<lsize;i++)
    {
        int cnt=0;
        int sum=0;
        fprintf(fp,"######%s######\n",lessons[i].name);
        for(int j=0;j<stsize;i++)
        {
            if(strcmp(students[j].lessonname,lessons[i].name)==0)
            {
               cnt++;
               if(students[i].grade>=5.0) sum++;
            }
        }
        double pr=((double)sum/cnt)*100.0;
        fprintf(fp,"%s--%.2lf\n",lessons[i].name,pr);
        fprintf(fp,"--------------------------------\n");
    }
    fclose(fp);
}
void findstudent(student *students,int stsize,int id)
{
    int cnt=0;
    double avg=0.0;
    for(int i=0;i<stsize;i++)
    {
        if(students[i].id==id)
        {
            cnt=1;
            printf("%s---%.2lf\n",students[i].lessonname,students[i].grade);
            avg+=students[i].grade;
        }
    }
    if(cnt==0)
    {
        printf("student with id:%d didn't found\n",id);
    }
    printf("-----------------------\n");
    printf("AVERAGE:%.2lf\n",avg);
}
int main()
{
    int stsize=0;
    int lssize=0;
    int choice;
    printf("Give filename:");
    gets(filename);
    getsize(&stsize,&lssize);
    if(stsize==0 || lssize==0)
    {
      exit(EXIT_FAILURE);
    }
    student *students=(student *)malloc(stsize * sizeof(student));
    lesson *lessons=(lesson *)malloc(lssize * sizeof(lesson));
    readfile(students,lessons);
    while(1)
    {
        printf("SCHOOL.DB");
        printf("1-INFORMATION PER LESSON\n");
        printf("2-SHOW PASS PRECENT\n");
        printf("3-SEARCH STUDENT\n");
        printf("4-EXIT DB\n");
        printf("Give choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
           display_grades(lessons,lssize,students,stsize);
        }
        else if(choice==2)
        {
           display_in_file_pass_precent(lessons,lssize,students,stsize);
           printf("data adden in file::%s\n",filename);
        }
        else if(choice==3)
        { 
            int id;
             printf("Give id:");
             scanf("%d",&id);
             findstudent(students,stsize,id);
        }
        else if(choice==4)
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("invalid choice please try again\n");
        }
    }
}