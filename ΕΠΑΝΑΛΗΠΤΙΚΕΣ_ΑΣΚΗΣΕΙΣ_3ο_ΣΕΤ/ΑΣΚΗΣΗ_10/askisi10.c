/*AUTHOR NASTOS VASILEIOS DIT UOI*/

#include <stdio.h>

//#define size 120
#define size 5

typedef struct 
{
    int code;
    char product_name[100];
    double price;
}proion;

void readdata(proion *proionta)
{
    for(int i=0;i<size;i++)
    {
        do
        {
          printf("Give code of product:");
          scanf("%d",&proionta[i].code);
        }while(proionta[i].code<1000 || proionta[i].code>9999);
        fflush(stdin);
        printf("Give product name:");
        gets(proionta[i].product_name);
        do
        {
          printf("Give product price:");
          scanf("%lf",&(proionta+i)->price);
        }while(proionta[i].price<0);
        printf("\n");
    }
}

int products_lower_10(proion *proionta)
{
    int counter=0;
    for(int i=0;i<size;i++)
    {
        if(proionta[i].price<10.0)
        {
            counter++;
        }
    }
    return counter;
}

void find_code(proion *proionta)
{
    for(int i=0;i<size;i++)
    {
        if((proionta+i)->code>=6000 && (proionta+i)->code<6999)
        {
            printf("CODE:%d \t NAME:%s \t Price:%.2lf\n");
        }
    }
}

int main()
{
    proion proionta[size];
    readdata(proionta);
    printf("%d products have price lower than 10 euros\n",products_lower_10(proionta));
    find_code(proionta);
}