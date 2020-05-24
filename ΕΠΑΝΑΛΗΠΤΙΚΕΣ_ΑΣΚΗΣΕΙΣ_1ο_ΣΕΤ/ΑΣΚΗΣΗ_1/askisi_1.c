#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int code;
    char category[100];
    double price;
}product;
int size=10;
void searchbycategory(product *products,char *cat)
{
        for(int i=0;i<size;i++)
        {
                if(strcmp(products[i].category,cat)==0)
                {
                        printf("Id:%d \t Price:%.2lf\n",products[i].code,products[i].price);
                }
        }
}
void sort(product *products)
{
 for(int i=0;i<size;i++)
 {
    for(int j=0;j<size-1;j++)
    {
        if(products[j].price>products[j].price)
        {
          product temp=products[j];
          products[j]=products[j+1];
          products[j+1]=temp;
        }
    }
 }
}
void save_to_file(product *products)
{
    FILE *fp;
    char fn[100];
    fflush(stdin);
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"w");
    fprintf(fp,"PRODUCTS LIST\n");
    fprintf(fp,"#################################\n");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"Id:%d \t Category:%s \t Price:%.2lf\n",products[i].code,products[i].category,products[i].price);
    }
    fclose(fp);
}
int main()
{
   int *codes;
   product *products=(product *)malloc(size * sizeof(product));
   for(int i=0;i<size;i++)
   {
        printf("product_%d",i+1);
        products[i].code=rand()%(100-i);
        fflush(stdin);
        printf("Give category:");
        gets(products[i].category);
        printf("give price:");
        scanf("%lf",&products[i].price);
   }
   printf("READING COMPLETE!\n");
   printf("########################\n");
   int choice=0;
   while(choice!=2)
   {
           printf("1-Search by category\n");
           printf("2-save_to_file\n");
           printf("3-sort by price\n");
           printf("Give choice:");
           printf("Give choice:");
           scanf("%d",&choice);
           if(choice==1)
           {
              char name[100];
              printf("give name:");
              gets(name);
              searchbycategory(products,name);
           }
           else if(choice==2)
           {
              save_to_file(products);
           }
           else if(choice==3)
           {
              sort(products);
           }
           else{
                   printf("invalid choice\n");
           }
   }
}