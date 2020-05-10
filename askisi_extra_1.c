#include <stdio.h>
#include <string.h>
int highestsalary(double *sal,int size)
{
   int mp=0;
   double max=salary[0];
   for(int i=0;i<size;i++)
   {
       if(sal[i]>max)
       {
           max=sal[i];
           mp=i;
       }
   }
   return mp;
}
int main()
{
    FILE *fp;
    char fn[100];
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    if(fp==NULL)
    {
        printf("ERROR!!!no such file found\n");
        return;
    }
    char line[100];
    int cnt=0;
    while(fgets(line,100,fp)!=NULL)
    {
        cnt++;
    }
    fclose(fp);
    char **name;
    double *salary;
    name=(char **)malloc(cnt * sizeof(char *));
    salary=(double *)malloc(cnt * sizeof(double));
    for(int i=0;i<cnt;i++)
    {
        name[i]=(char *)malloc(100 * sizeof(char));
    }
    fp=fopen(fn,"r");
    char x[100];
    double y;
    while(fscanf(fp,"%s-%lf",&x,&y)!=NULL)
    {
        strcpy(name[i],x);
        salary[i]=y;
    }
    fclose(fp);
    char fb[100];
    double sal;
    for(int i=0;i<cnt;i++)
    {
      for(int j=0;j<cnt-1)
      {
        strcpy(fb,name[j]);
        strcpy(name[j],name[j+1]);
        strcpy(name[j+1],fb);
        sal=salary[j];
        salary[j]=salary[j+1];
        salary[j+1]=sal;
      }
    }
    fp=fopen(fn,"w");
    for(int i=0;i<cnt;i++)
    {
        fprintf(fp,"Name:%s \t SALARY:%.2lf\n",name[i],salary[i]);
    }
    int pos=highestsalary(salary,cnt);
    fprintf(fp."HIGHEST PAID EMPLOYEE:NAME:%s \t SALARY:%.2lf\n",name[pos],salary[pos]);
    fclose(fp);
}