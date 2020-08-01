#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    int id;
    char category[100];
    double price;
}product;
char filename[100];
int getsizefromfile()
{
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        return 0;
    }
    int cnt=0;
    char line[100];
    while(fgets(line,100,fp)!=NULL)
    {
        cnt++;
    }
    fclose(fp);
    return cnt;
}
void loaddata(product *products)
{
    FILE *fp;
    fp=fopen(filename,"r");
    char line[100];
    int i=0;
    //strtok-->Διαχωρισμός αρχείου σε tokens[Διαφορετικές λέξεις ανάλογα με το σύμβολο διαχωρισμου].
    //επιστρέφει δείκτη σε χαρακτήρα αν εκτελεστεί επιτυχώς αλλιώς επιστρέφει ΝULL.
    while(fgets(line,100,fp)!=NULL)
    {
        char *temptok=strtok(line," -,");
        products[i].id=atoi(temptok);
        temptok=strtok(NULL," -,");
        strcpy(products[i].category,temptok);
        temptok=strtok(NULL," -,");
        products[i].price=atof(temptok);
        i++;
    }
    fclose(fp);
}
void search(int p,product *products,int s)
{
    int pos=-1;
    for(int i=0;i<s;i++)
    {
        if(p==products[i].id)
        {
            printf("Id:%d \t Category:%s \t Price:%.2lf\n",products[i].id,products[i].category,products[i].price);
            pos=i;
        }
    }
    if(pos==-1)
    {
        printf("Product didn't found\n");
    }
}
void search_by_category(product *products,int size,char *cat)
{
    int cnt=0;
   for(int i=0;i<size;i++)
   {
       if(strcmp(products[i].category,cat)==0)
       {
           printf("Id:%d \t Category:%s \t Price:%.2lf\n",products[i].id,products[i].category,products[i].price);
           cnt++;
       }
   }
   if(cnt==0)
   {
       printf("No such category found!!!\n");
   }
}
void display_products(product *products,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("Id:%d \t Category:%s \t Price:%.2lf\n",products[i].id,products[i].category,products[i].price);
    }
}
int main()
{
    strcpy(filename,"products.txt");
    int size=getsizefromfile();
    if(size==0)
    {
        printf("File doesn't exist!!!\n");
        exit(1);
    }
    product products[size];
    char categoryname[100];
    int flag=0;
    int choice;
    loaddata(products);
    int id;
    while(1)
    {
        printf("MAIN MENU::\n");
        printf("1-Search product id\n");
        printf("2-Search proucts by category\n");
        printf("3-Display products\n");
        printf("4-Exit\n");
        printf("Give choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
              printf("Give product id:");
              scanf("%d",&id);
              search(id,products,size);
              break;
            case 2:
              printf("Give category:");
              gets(categoryname);
              search_by_category(products,size,categoryname);
              break;
            case 3:
               display_products(products,size);
            case 4:
              flag=1;
              break;
            default:
              printf("invalid choice\n");
              break;
        }
        if(flag==1) break;
    }
}