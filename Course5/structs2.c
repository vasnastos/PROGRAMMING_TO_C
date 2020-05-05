/*Εύρεση ενός μέγιστου βαθμου,μέσου όρο βαθμολογιών με συναρτήσεις για έναν πίνακα που θα περιέχει μαθητές*/
#include <stdio.h>
#include <stdlib.h>
#define ms 100
typedef struct
{
    int id;
    char *n;
    double grade;
}student;
void findelements(student *a,int size,int *m,double *av)
{
    double max=a[0].grade;
    *m=0;
    *av=a[0].grade;
    for(int i=1;i<size;i++)
    {
        *av+=a[i].grade;
       if(a[i].grade>max)
       {
           max=a[i].grade;
           *m=i;
       }
    }
    *av/=size;
}
void readdata(student *a,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("Give id:");
        scanf("%d",&a[i].id);
        fflush(stdin);
        printf("Give name:");
        a[i].n=(char *)malloc(ms * sizeof(char));
        gets(a[i].n);
        printf("Give grade:");
        scanf("%lf",&a[i].grade);
    }
}
void deletedata(student *students,int size)
{
   for(int i=0;i<size;i++)
   {
       free(students[i].n);
   }
}
int main()
{
    student *a;
    int s;
    printf("Give size of board:");
    scanf("%d",&s);
    a=(student *)malloc(s * sizeof(student));
    int pos;
    double avg;
    readdata(a,s);
    findelements(a,s,&pos,&avg);
    printf("BEST PERFORMANCE:%d \t %s \t %.3lf\n",a[pos].id,a[pos].n,a[pos].grade);
    printf("AVERAGE GRADE:%.2lf\n",avg);
    deletedata(a,s);
    free(a);
} 