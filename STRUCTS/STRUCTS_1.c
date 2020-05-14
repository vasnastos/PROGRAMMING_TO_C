#include <stdio.h>
typedef struct 
{
    int id;
    char name[100];
    double grade;
}student;
double sum_grades(student *y,int size)
{
  double sum=0.0;
  for(int i=0;i<size;i++)
  {
      sum+=y[i].grade;
  }
  return sum;
}
int main()
{
    student x[5]; 
    for(int i=0;i<5;i++)
    {
        printf("Give id:");
       scanf("%d",&x[i].id);
       printf("Give name:");
       gets(x[i].name);
       printf("give grade");
       scanf("%lf",&x[i].grade);
    }
    printf("sum grades=%.2lf\n",sum_grades(x,5));
   /* student s1;
    student s2={1,"xv",7.8};
    int i;
    scanf("%d",&i);
    scanf("%d",&s1.id);
    gets(s1.name);
    scanf("%lf",&s1.grade);
    if(s1.grade>s2.grade)
    {
        printf("s1");
    }*/
}
