#include <stdio.h>
void sort(char *fn);
{
    //to be implement
}
void search(char *productname,char *filename)
{
    //to be implement
}
void insert(char *newproduct,double price,char *filename)
{
    //to be implement
}
int main()
{
    int choice;
    char fn[100];
    printf("Give filename you want to use:");
    gets(fn);
    while(1)
    {
        printf("PRODUCT BASE MENU::\n");
        printf("1-SORT\n");
        printf("2-SEARCH\n");
        printf("3-INSERT\n");
        printf("4_EXIT BASE\n");
        printf("Give choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            sort();
        }
        else if(choice==2)
        {
            char name[100];
            printf("Give name of product you want to search:");
            gets(name);
            search(name);
        }
        else if(choice==3)
        {
            char pn[100];
            double price;
            fflush(stdin);
            printf("Give name of new product:");
            gets(pn);
            printf("Give price of new product:");
            scanf("%lf",&price);
            insert(pn,price);
        }
        else if(choice==4)
        {
            //to be implement
        }
        else{
            printf("invalid choice!!\n");
        }
    }
}