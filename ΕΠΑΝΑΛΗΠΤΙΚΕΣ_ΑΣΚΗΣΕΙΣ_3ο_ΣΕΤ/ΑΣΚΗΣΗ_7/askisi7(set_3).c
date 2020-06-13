#include <stdio.h>
#include <string.h>

double prices[3]={5.0,10.0,15.0};

typedef struct {
    char identity[100];
    int number_of_sales[3];
}salesman;

//A ΕΡΩΤΗΜΑ
void read_data(salesman *salesmen,int size)
{
    for(int i=0;i<size;i++)
    {
        fflush(stdin);
        printf("Give salesman identity:");
        gets(salesmen.identity);
        for(int j=0;j<sizeof(salesmen[i].number_of_sales)/sizeof(int);j++)
        {
            printf("Give salesman number of sales in product %d:",j+1);
            scanf("%d",&salesmen[i].number_of_sales[j]);
        }
    }
}

//B ΕΡΩΤΗΜΑ
int total_sales(salesman *sel)
{
    int total=0;
    for(int i=0;i<sizeof(sel->number_of_sales)/sizeof(int);i++)
    {
      total+=sel->number_of_sales[i];
    }
    return total;
}

void find_total_sales(salesman *salesmen,int size,int *total)
{
    for(int i=0;i<size;i++)
    {
        total[i]=total_sales(salesmen[i]);
    }
}

//C ΕΡΩΤΗΜΑ
double find_sales(salesman *salesmen,int size,int *total)
{
   double average;
   int sum=0;
   int counter=0;
   for(int i=0;i<size;i++)
   {
       sum+=total[i];
   }
   average=((double)sum/size)*0.8;
   for(int i=0;i<size;i++)
   {
       if(total>average)
       {
           counter++;
       }
   }
   return ((double)counter/size)*100.0;
}

//D ΕΡΩΤΗΜΑ

void sort_by_total_sales(salesman *salesmen,int size,int *total)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(total[j]>total[j+1])
            {
                salesman temp=salesmen[j];
                salesmen[j]=salesmen[j+1];
                salesmen[j+1]=temp;
                int temp1=total[j];
                total[j]=total[j+1];
                total[j+1]=temp1;
            }
        }
    }
}

int main()
{
    salesman salesmen[20];
    read_data(salesmen,20);
    int total_sales[20];
    find_total_sales(salesmen,20,total_sales);
    for(int i=0;i<20;i++)
    {
        printf("%s---%d\n",salesmen[i].identity,total_sales[i]);
    } 
    printf("Over 80%% of average sales %.2lf\n",find_sales(salesmen,20));
    sort_by_total_sales(salesmen,20,total);
    for(int i=0;i<20;i++)
    {
        printf("%s---%d\n",salesmen[i].identity,total_sales[i]);
    }
}