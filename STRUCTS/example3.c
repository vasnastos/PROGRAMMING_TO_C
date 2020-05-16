#include <stdio.h> 
#include <stdlib.h>
typedef struct    
{
   char name[100];
   double salary;
}employee;
void sort(employee *employees,int size)    
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(employees[j].salary>employees[j+1].salary) 
            {
                employee temp=employees[j];
                employees[j]=employees[j+1];
                employees[j+1]=temp;
            }
        }
    }
}
void save_to_file(employee *employees,int size)
{
   FILE *fp;
   char filename[100];
   fflush(stdin);
   printf("Give filename:");
   gets(filename);
   fp=fopen(filename,"w"); 
   for(int i=0;i<size;i++)
   {
       fprintf(fp,"Name:%s \t Salary:%.2lf \n",employees[i].name,employees[i].salary);
   }
   fclose(fp);
}
int main()
{
    employee *employees;
    employees=(employee *)malloc(5 * sizeof(employee));
    for(int i=0;i<5;i++)
    {
        fflush(stdin);
        printf("Give name of employee:");
        gets(employees[i].name);
        printf("Give salary of employee:");
        scanf("%lf",&employees[i].salary);
    }
    sort(employees,5);
    printf("AFTER SORT RESULTS WILL SAVE TO FILE\n");
    save_to_file(employees,5);
    free(employees);
}