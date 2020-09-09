#include <stdio.h>
int main()
{
    double sal;
    int counter=0;
    double max;
    FILE *fp=fopen("salaries.txt","r");
    if(fp==NULL)
    {
        printf("File did not found\n");
        return 1;
    }
    while(fscanf(fp,"%lf",&sal)>0)
    {
        if(sal<500.0 && sal>0.0)
        {
            counter++;
            if(counter==1)
            {
              max=sal;
            }
            else
            {
                if(sal>max)
                {
                    max=sal;
                }
            }
        }
    }
    fclose(fp);
    printf("Total salaries below 500:%d\n",counter);
    printf("Max salary of those which are lower than 500:%lf\n",max);
    return 0;
}