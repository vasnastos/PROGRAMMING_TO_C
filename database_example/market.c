#include "database.h"

void readdata(proion *proionta,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("Give details for product %d::\n",i+1);
        do{
          printf("Give code:");
          scanf("%d",&proionta[i].id);
        }while(proionta[i].id<1000 || proionta[i].id>9999);
        fflush(stdin);
        printf("Give name of product:");
        gets(proionta[i].fullname);
        do{
           printf("Give price of product:");
           scanf("%lf",&proionta[i].price);
        }while(proionta[i].price<0.0);
    }
}

int lowerthanten(proion *proionta,int size)
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

void printproduct(proion *pr)
{
    printf("ID:%d \t FULLNAME:%s \t PRICE:%.2lf\n",pr->id,pr->fullname,pr->price);
}

void printproducts(proion *proionta,int size)
{
    for(int i=0;i<size;i++)
    {
        if(proionta[i].id>=6000 && proionta[i].id<6999)
        {
            printproduct(proionta+i);
        }
    }
}

int main()
{
    proion *prods;
    int chdb;
    printf("Read new data:(0|no,1|yes):");
    scanf("%d",&chdb);
     int s;
    if(chdb==1)
    {
      printf("Give size:");
      scanf("%d",&s);
      prods=(proion *)malloc(s * sizeof(proion));
      readdata(prods,s);
      printf("Products lower than 10$:%d\n",lowerthanten(prods,s));
      printproducts(prods,s);
    }
    int choice;
    do
    {
      printf("Save to database:(0|cancel,1|continue):");
      scanf("%d",&choice);
    }while(choice!=0 && choice!=1);

    if(choice==1)
    {
        printf("database exists(0|no,1|yes):");
        int ch;
        scanf("%d",&ch);
        if(ch==0)
        {
         char dbname[100];
         fflush(stdin);
         printf("Give database name:");
         gets(dbname);
         createdb(dbname);
         for(int i=0;i<s;i++)
         {
             inserttodb(prods[i].id,prods[i].fullname,prods[i].price);
         }
        } 
        else
        {
          char bdexistname[100]; 
          char line[100];
          FILE *fp=fopen("dbname.txt","r");
          while(fgets(line,100,fp)!=NULL)
          {
             if(line[0]=='#') continue;
             if(line[0]=='\n') continue;
             strcpy(bdexistname,line);
          }
          fclose(fp);
          createdb(bdexistname);
        }
        
        printf("Get records from db:(0|No,1|yes):");
        scanf("%d",&ch);
        if(ch==1)
        {
            proion *records;
            int sizedb=getrecords();
            records=(proion *)malloc(sizedb * sizeof(proion));
            exportfromdb(records);
            for(int i=0;i<sizedb;i++)
            {
               printproduct(records+i);
            }
            free(records);
        }
    }
    free(prods);
}