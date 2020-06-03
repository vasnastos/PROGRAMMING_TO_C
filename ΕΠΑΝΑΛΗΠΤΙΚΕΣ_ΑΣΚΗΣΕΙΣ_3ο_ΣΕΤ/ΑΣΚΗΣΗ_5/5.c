#include<stdio.h>
#include<stdlib.h>

#define f 3
//#define f 20

typedef struct
{
    int am;
    char fullname[100];
    double grades[2];
}foititis;

void readdata(foititis *foitites, int size)
{
    for(int i=0;i<size;i++)
    {
        do
        {
            printf("Give AM of student %d: \n", i+1);
            scanf("%d",&foitites[i].am);
        }while(foitites[i].am<100 || foitites[i].am>200);
        fflush(stdin);
        printf("Give fullname of student %d: \n", i+1);
        gets(foitites[i].fullname);
        for(int j=0;j<2;j++)
        {
            printf("Give grade for lesson %d of student %d: \n",j+1, i+1);
            scanf("%lf", &foitites[i].grades[j]);
            while(foitites[i].grades[j]<0.0 || foitites[i].grades[j]>10.0)
            {
                printf("Wrong input!! Give grade for lesson %d for student %d again: \n", j+1, i+1);
                scanf("%lf", &foitites[i].grades[j]);
            }
        }
    }
}

double failure_percentage(foititis *foitites, int size)
{
    int counter=0;
    for(int i=0;i<size;i++)
    {
            if(foitites[i].grades[0]<5.0 && foitites[i].grades[1]<5.0)
            {
                counter++;
            }
    }
    return ((double)counter/size)*100.0;
}

void pass(foititis *foitites, int size)
{
    for(int i=0;i<size;i++)
    {
            if(foitites[i].grades[0]>=50.0 || foitites[i].grades[1]>=50.0)
            {
                printf("The student with AM:%d Fullname:%s has passed at least 1 lesson \n", foitites[i].am, foitites[i].fullname);
            }
    }
}

int main()
{
    foititis foitites[f];
    readdata(foitites,f);
    printf("The percentage of students that didn't pass any lesson is: %.2lf %% \n",failure_percentage(foitites,f));
    pass(foitites,f);

    return 0;
}
