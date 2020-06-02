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
    //to be implement
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
    //to be implement
}

//C ΕΡΩΤΗΜΑ
void find_sales(salesman *salesmen,int size)
{
    //to be implement
}

//D ΕΡΩΤΗΜΑ

void sort_by_total_sales(salesman *salesmen,int size)
{
    //to be implement
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
    sort_by_total_sales(salesmen,20);
    for(int i=0;i<20;i++)
    {
        printf("%s---%d\n",salesmen[i].identity,total_sales[i]);
    }
}