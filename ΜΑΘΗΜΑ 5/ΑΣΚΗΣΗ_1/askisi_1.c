#include <stdio.h>
#define ms 100
typedef struct 
{
    char name[ms];
    char lastname[ms];
    int age;
    char sex[ms];
    char phone[10];
    double salary[3];
}employee;
//Εύρεση μέσου όρου μισθών για υπαλλήλους.
void findaverage(employee *employees,int size,double *avg)
{
    for(int i=0;i<size;i++)
    {
        avg[i]=0;
        for(int j=0;j<3;j++)
        {
            avg[i]+=employees[i].salary[j];
        }
        avg[i]/=3;
    }
}
//Εύρεση μέσου όρου μισθών τελευταίου χρόνου
double last_year_average(employee *employees,int size)
{
    double avg=0.0;
    for(int i=0;i<size;i++)
    {
        avg+=employees[i].salary[2];
    }
    return avg/size;
}
//Εύρεση υπαλλήλου που είχε μεγαλύτερο μισθό τον 3 χρόνο
void findmax(employee *emp,int size,employee *max)
{
    *max=emp[0];
    double m=max->salary[2];
    for(int i=1;i<size;i++)
    {
      if(emp[i].salary[2]>m)
      {
          *max=emp[i];
          m=max->salary[2];
      }
    }
}
int main()
{
  employee employees[10];
  //Διάβασμα δεδομένων
  for(int i=0;i<10;i++)
  {
      printf("Give details of employee %d:::\n",i+1);
      fflush(stdin);
      printf("Give name:");
      gets(employees[i].name);
      printf("Give surname:");
      gets(employees[i].lastname);
      printf("Give age:");
      scanf("%d",&employees[i].age);
      fflush(stdin);
      printf("Give sex of employee:");
      gets(employees[i].sex);
      printf("Give phone of employee:");
      gets(employees[i].phone);
      for(int j=0;j<3;j++)
      {
          printf("Give salary of year %d:",i+1);
          scanf("%lf",&employees[i].salary[j]);
      }
  }
  FILE *fp;
  employee max;
  double avg[10];
  findaverage(employees,10,avg);
  findmax(employees,10,&max);
  fflush(stdin);
  char fn[ms];
  printf("Give filename:");
  gets(fn);
  fp=fopen(fn,"w");
  for(int i=0;i<10;i++)
  {
      fprintf(fp,"EMPLOYEE_%d###########\n",i+1);
      fprintf(fp,"Name:%s\n",employees[i].name);
      fprintf(fp,"Lastname:%s\n",employees[i].lastname);
      fprintf(fp,"Age:%d\n",employees[i].age);
      fprintf(fp,"Sex:%s\n",employees[i].sex);
      fprintf(fp,"Phone:%s\n",employees[i].phone);
      fprintf(fp,"SALARY INFO**********\n");
      for(int j=0;j<3;j++)
      {
         fprintf(fp,"SALARY:%d:%.2lf\n",j+1,employees[i].salary[j]);
      }
      fprintf(fp,"%.2lf\n",avg[i]);
      fprintf(fp,"\n");
  }
  fprintf(fp,"EMPLOYEE WITH MAX SALARY###########::\n");
  fprintf(fp,"Name:%s\n",max.name);
  fprintf(fp,"Lastname:%s\n",max.lastname);
  fprintf(fp,"Age:%d\n",max.age);
  fprintf(fp,"Sex:%s\n",max.sex);
  fprintf(fp,"Phone:%s\n",max.phone);
  fclose(fp);
}
