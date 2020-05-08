//Ταξινόμιση με βάση την τιμή των βιβλίων σε έναν πίνακα από βιβλία.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ms 100
typedef struct {
    char *title;
    char *authors_name;
    double price;
}book;
void readdata(book *br,int size)
{
    printf("read data::\n");
    for(int i=0;i<size;i++)
    {
        br[i].title=(char *)malloc(ms * sizeof(char));
        br[i].authors_name=(char *)malloc(ms * sizeof(char));
        fflush(stdin);
        printf("Give title:");
        gets(br[i].title);
        printf("Give authors_name:");
        gets(br[i].authors_name);
        printf("Give price:");
        scanf("%lf",&br[i].price);
    }
}
void sortboard(book *b,int size)
{
    printf("sort by price!!\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(b[j].price>b[j+1].price)
            {
                //κάθε μεταβλητή έχει 3 πεδία,
                double temp=b[j].price;
                b[j].price=b[j+1].price;
                b[j+1].price=temp;
                char t1[ms];
                strcpy(t1,b[j].authors_name);
                strcpy(b[j].authors_name,b[j+1].authors_name);
                strcpy(b[j+1].authors_name,t1);
                char t2[ms];
                strcpy(t2,b[j].title);
                strcpy(b[j].title,b[j+1].title);
                strcpy(b[j+1].title,t2);
            }
        }
    }
}
void printtofile(book *br,int size)
{
    FILE *fp;
    fflush(stdin);
    char fn[100];
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"w");
    fprintf(fp,"SORT TABLE\n");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"%s-%s-%.3lf\n",br[i].title,br[i].authors_name,br[i].price);
    }
    fclose(fp);
}
void deletebooks(book *br,int size)
{
    for(int i=0;i<size;i++)
    {
        free(br[i].authors_name);
        free(br[i].title);
    }
}
int main()
{
    book books[6];
    readdata(books,6);
    sortboard(books,6);
    printtofile(books,6);
    deletebooks(books,6);
}