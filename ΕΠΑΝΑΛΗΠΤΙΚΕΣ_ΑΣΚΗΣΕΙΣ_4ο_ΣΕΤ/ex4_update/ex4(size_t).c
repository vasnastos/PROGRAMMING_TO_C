#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
#include <stdbool.h>

#define s 200

bool loaded=false;
char filename;

typedef struct 
{
   char cityname[100];
   size_t population; 
}city;

int getsize()
{
   strcpy(filename,"data.txt");
   FILE *fp=fopen(filename,"r");
   if(fp==NULL)
   {
       return 0;
   }
   int counter=0;
   char line[100];
   while(fgets(line,100,fp)!=NULL)
   {
       if(line[0]=='#') continue;
       if(line[0]=='\n') continue;
       if(line[strlen(line)-1])
       {
           line[strlen(line)-1]='\0';
       }
       counter++;
   }
   fclose(fp);
   return counter;
}

void readpopulation(city *cities)
{
    char line[100];
    int i=0;
   FILE *fp=fopen(filename,"r");
   while(fgets(line,100,fp)!=NULL)
   {
       if(line[0]=='#') continue;
       if(line[0]=='\n') continue;
       if(line[strlen(line)-1])
       {
           line[strlen(line)-1]='\0';
       }
       char *token=strtok(line,"-");
       strcpy(cities[i].cityname,token);
       token=strtok(NULL,"-");
       cities[i].population=atoll(token);
       i++;
   }
}

void update_population(city *cities,int size)
{
    char filename[100],line[100];
    int cnt=1;
    strcpy(filename,"updatepop.txt");
    FILE *fp=fopen(filename,"r");
    while(fgets(line,100,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;

        if(line[strlen(line)-1]=='\n')
        {
            line[strlen(line)-1]='\0';
        }
        char cname[100];
        double perc;
        char *token=strtok(line,"-");
        strcpy(cname,token);
        token=strtok(NULL,"-");
        perc=atoi(token);
        if(perc==0.0) continue;
        int found=0;
        for(int i=0;i<size;i++)
        {
           if(strcmp(cname,cities[i].cityname)==0)
           {
               cities[i].population+=(perc * cities[i].population)/100;
               found=1;
           }
        }
        if(found==0)
        {
            printf("%d city of file did not found in board!!\n",cnt);
        }
        cnt++;
    }
    fclose(fp);
}

void printcity(city *cit)
{
    printf("NAME:%s \t POPULATION:%u\n",cit->cityname,cit->population);
}

void sort(city *cities,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(cities[j].population>cities[j+1].population)
            {
                city temp=cities[j];
                cities[j]=cities[j+1];
                cities[j+1]=temp;
            }
        }
    }
}

void show_over_n_pop(city *cities,int size,int n)
{
    for(int i=0;i<size;i++)
    {
        if(cities[i].population>=n)
        {
            printcity(cities+i);
        }
    }
}

char databasename[s];

void createdb()
{
   FILE *fp=fopen("dbname.txt","r");
   char line[s];
   while(fgets(line,s,fp)!=NULL)
   {
       if(line[0]=='#') continue;
       if(line[0]=='\n') continue;

       if(line[strlen(line)-1]=='\n'){
           line[strlen(line)-1]='\0';
       }
       strcpy(databasename,line);
   }
   fclose(fp);
  sqlite3 *db=NULL;
  char *errmsg=NULL;
  char *sql=NULL;
  sql=(char *)malloc(s * sizeof(char));
  int res=sqlite3_open(databasename,&db);
  if(res!=SQLITE_OK)
  {
      printf("%s\n",sqlite3_errmsg(db));
      sqlite3_close(db);
      return;
  }
  strcpy(sql,"CREATE TABLE IF NOT CITY(ID INTEGER PRIMARY KEY AUTOINCREMENT,NAME VARCHAR(30),POPULATION DOUBLE);");
  res=sqlite3_exec(db,sql,0,0,&errmsg);
  if(res!=SQLITE_OK)
  {
      printf("%s\n",sqlite3_errmsg(db));
      sqlite3_close(db);
      return;
  } 
  free(sql);
}

void insert_into_db(char *cn,size_t pop)
{
    sqlite3* db=NULL;
    sqlite3_stmt *q=NULL;
    char *sql;
    int res=sqlite3_open(databasename,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    sql=(char *)malloc(s * sizeof(char));
    strcpy(sql,"INSERT INTO CITY(NAME,POPULATION) VALUES(?,?);");
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    sqlite3_bind_text(q,1,cn,-1,SQLITE_STATIC);
    sqlite3_bind_int(q,2,pop);
    sqlite3_step(q);
    sqlite3_close(db);
}

void read_from_file_to_db()
{
    strcpy(filename,"data.txt");
    FILE *fp=fopen(filename,"r");
    char n[s];
    char line[s];
    size_t pop;
    while(fgets(line,s,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;
        if(line[strlen(line)-1]=='\n') 
        {
            line[strlen(line)-1]='\0';
        }
        char *token=strtok(line,"-");
        strcpy(n,token);
        token=strtok(NULL,"-");
        pop=atoll(token);
        insert_into_db(n,pop);
    }
    loaded=true;
    fclose(fp);
}

void read_data_from_user()
{
    
}

void main_menu()
{
    printf("MAIN APP MENU::\n");
    printf("1-READ DATA FROM FILE\n");
    printf("2-GIVE DATA AND STORE TO A DATABASE FROM USER\n");
    printf("3-READ DATA FROM FILE AND STORE THEM TO DB\n");
    printf("4-GET DATA FROM DATABASE\n");
    printf("5-FIND CITIES WITH POPULATION OVER N\n");
    printf("6-UPDATE POPULATION");
    printf("7-CLOSE APP\n");
}

int getchoice()
{
    int c;
    do
    {
      printf("Give choice:");
      scanf("%d",&c);
    }while(c<1 || c>7);
    return c;
}

int main()
{
    int choice,n;
    city *cities=NULL;
    while(true)
    {
       main_menu();
       choice=getchoice();
       if(choice==1)
       {
           int bs=getsize();
           cities=(city *)malloc(bs * sizeof(city));
           readpopulation(cities);
           printf("data read from file\n");
       }     
       else if(choice==2)
       {

       } 
    }
}