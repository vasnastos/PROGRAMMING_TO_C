#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
#include <Windows.h>
#define s 200

char dbname[s];

//--------------------------------------------
void read_database_name()
{
    FILE *fp=fopen("dbname.txt","r");
    while(fgets(line,s,fp)!=NULL)
    {
      if(line[0]=='#') continue;
      if(line[0]=='\n') continue;
      if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
      strcpy(dbname,line);
    }
    fclose(fp);
}
//--------------------------------------------

//--------------------------------------------
void read_copyright()
{
    printf("##########################\n");
    char line[s];
    FILE *cop=fopen("copyright.txt","r");
    while(fgets(line,s,cop)!=NULL)
    {
        printf("%s",line);
    }
    fclose(cop);
    printf("############################\n");
    printf("\n");
}
//---------------------------------------------

char filename[s];

typedef struct
{
    char cityname[s];
    double *citytemp;
}temperature;

typedef struct 
{
    char name[s];
    double av;
}info;

int getsize()
{
    char line[s];
    int counter=0;
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        return 0;
    }
    while(fgets(line,s,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;
        counter++;
    }
    fclose(fp);
    return counter;
}

void get_sum_temp_by_city(int *a)
{
    int i=0;
    char line[s];
    FILE *temp=fopen(filename,"r");
    while(fgets(line,s,temp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;

        if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
        int counter=0;
        char *token=strtok(line,",");
        token=strtok(NULL,",");
        while(token!=NULL)
        {
            counter++;
            token=strtok(NULL,",");
        }
        a[i]=counter;
        i++;
    }
    fclose(temp);
}

void read_data(temperature *temps)
{
    char line[s];
    int i=0;
    int j;
    FILE *temp=fopen(filename,"r");
    while(fgets(line,s,temp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;

        if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
        j=0;
        char *fetch=strtok(line,",");
        strcpy(temps[i].cityname,fetch);
        fetch=strtok(NULL,",");
        while(fetch!=NULL)
        {
            temps[i].citytemp[j]=atof(fetch);
            fetch=strtok(NULL,",");
            j++;
        }
        i++;
    }
    fclose(temp);
}

void load_to_db()
{
     sqlite3 *db=NULL;
     char *sql;
     char *errmsg;
     int res=sqlite3_open(dbname,&db);
     if(res!=SQLITE_OK)
     {
         printf("%s\n",sqlite3_errmsg(db));
         sqlite3_free(errmsg);
         free(sql);
         sqlite3_close(db);
         return;
     }
     sql=(char *)malloc(200 * sizeof(char));
     strcpy(sql,"CREATE TABLE IF NOT EXISTS CITY(NAME VARCHAR(30),AVERAGE_TEMPERATURE DOUBLE,PRIMARY KEY(NAME));");
     res=sqlite3_exec(db,sql,0,0,&errmsg);
     if(res!=SQLITE_OK)
     {
         printf("%s\n",sqlite3_errmsg(db));
         sqlite3_free(errmsg);
         free(sql);
         sqlite3_close(db);
         return;
     }
     else
     {
         printf("Database creation on project..");
         for(int i=0;i<4;i++)
         {
             printf("....");
             Sleep(500);
         }
         printf("\n");
         printf("Database has been created!!!Hello world from database\n");
     }
     sqlite3_close(db);
     free(sql);
}

void insert_into_db(char *name,double av)
{
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char *sql;
    int res=sqlite3_open(dbname,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        free(db);
        sqqlite3_close(db);
        return;
    }
    sql=(char *)malloc(s * sizeof(char));
    strcpy(sql,"INSERT INTO CITY(NAME,AVERAGE_TEMPERATURE) VALUES(?,?);");
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK){
        printf("%s\n",sqlite3_errmsg(db));
        free(db);
        sqqlite3_close(db);
        return;
    }
    sqlite3_bind_text(q,1,name,-1,SQLITE_STATIC);
    sqlite3_bind_double(q,2,av);
    sqlite3_step(q);
    printf("Insertion is on the way please wait..");
    for(int i=0;i<4;i++)
    {
         printf("....");
         Sleep(400);
    }
     printf("\n");
    printf("Insertion complete!!!!\n");
    sqlite3_close(db);
    free(sql);
}

int count_records()
{
    int count=0;
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char *sql;
    int res=sqlite3_open(dbname,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        free(db);
        sqqlite3_close(db);
        return count;
    }
    sql=(char *)malloc(s * sizeof(char));
    strcpy(sql,"SELECT COUNT(*) FROM CITY;");
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK){
        printf("%s\n",sqlite3_errmsg(db));
        free(db);
        sqqlite3_close(db);
        return count;
    }
    if(sqlite3_step(q)==SQLITE_ROW)
    {
       count=sqlite3_column_int(q,0);
    }
    sqlite3_close(db);
    free(sql);
    return count;
}

info* get_records()
{
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char *sql;
    int res=sqlite3_open(dbname,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        free(db);
        sqqlite3_close(db);
        return count;
    }
    sql=(char *)malloc(s * sizeof(char));
    strcpy(sql,"SELECT COUNT * FROM CITY;");
    int size=get_records();
    if(size==0)
    {
        return NULL;
    }
    info *temps=(info *)malloc(size * sizeof(info));
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK){
        printf("%s\n",sqlite3_errmsg(db));
        free(db);
        sqqlite3_close(db);
        return NULL;
    }
    int i=0;
    while(sqlite3_step(q)=SQLITE_ROW)
    {
       strcpy(temps[i].name,(char *)sqlite3_column_text(q,0));
       temps[i].name=sqlite3_column_double(q,1);
       i++;
    }
    free(sql);
    sqlite3_close(db);
    return temps;
}

void get_cities_average_temp(temperature *temps,double *avg,int *col,int size)
{
   for(int i=0;i<size;i++)
   {
       avg[i]=0.0;
       for(int j=0;j<col[i];j++)
       {
           avg[i]+=temps[i].citytemp[j];
       }
       avg[i]/=col[i];
   }
}

void cities_below_and_under(double *avg,int size,int *below,int *under)
{
    (*below)=0;
    (*under)=0;
   for(int i=0;i<size;i++)
   {
      if(avg[i]>0)
      {
          (*under)++;
      }
      if(avg[i]<0)
      {
          (*below)++;
      }
   }
}


void delete_db_boards(temperature *tms,int *col,int size)
{
    for(int i=0;i<size;i++)
    {
        free(tms[i].citytemp);
    }
    free(col);
    free(tms);
}

int main()
{
    read_copyright();
    printf("Give filename:");
    gets(filename);
    int size=getsize();
    int *colsize;
    temperature *temps;
    if(size==0)
    {
        perror("No such file found\n");
        exit(EXIT_FAILURE);
    }
    printf("FILE LOADING");
    for(int i=0;i<5;i++)
    {
        printf("....");
        Sleep(500);
    }
    printf("\n\n");
    printf("File loading complete!!!!!!!\n");
    temps=(temperature *)malloc(size * sizeof(temperature));
    colsize=(int *)malloc(size * sizeof(int));
    get_sum_temp_by_city(colsize);
    for(int i=0;i<size;i++)
    {
        temps[i].citytemp=(double *)malloc(colsize[i] * sizeof(double));
    }
    read_data(temps);
    printf("DATA LOADING");
    for(int i=0;i<5;i++)
    {
        printf("....");
        Sleep(500);
    }
    double *average=(double *)malloc(size * sizeof(double));
    printf("\n\n");
    printf("Data loading complete!!!!!!!\n");
    printf("AVERAGE PER CITY\n");
    printf("###################################\n");
    get_cities_average_temp(temps,average,colsize,size);
    for(int i=0;i<size;i++)
    {
        printf("AVERAGE OF CITY:%s is:%.2lf\n",temps[i].cityname,average[i]);
        if(average[i]>0.0)
        {
            printf("TEMPARATURE OVER 0\n");
        }
        else if(average[i]<0.0)
        {
            printf("TEMPARATURE BELOW 0\n");
        }
        printf("\n");
    }
    printf("###################################\n");
    printf("\nSUMMARY OVERALL\n");
    printf("###################################\n");
    int over,below;
    cities_below_and_under(average,size,&below,&over);
    double averageover=((double)over/size)*100.0;
    double averagebelow=((double)below/size)*100.0;
    printf("%.2lf percent of cities have average temparature over 0\n",averageover);
    printf("%.2lf percent of cities have average temparature below 0\n",averagebelow);
    printf("###################################\n");

    int an;
    do
    {
      printf("Load to Database(0|yes),(1|No):");
      scanf("%d",&an);
    }while(an!=0 && an!=1);
    if(an==0)
    {
       read_database_name();
       load_to_db();
       for(int i=0;i<size;i++)
       {
           insert_into_db(temps[i].cityname,average[i]);
       }
       info *information=get_records();
       int sdb=count_records();
       printf("\n");
       printf("########################################\n");
       for(int i=0;i<sdb;i++)
       {
           printf("CITY NAME:%s \t CITY AVERAGE TEMPERATURE:%.2lf\n",information[i].av,information[i].av);
       }
       printf("########################################\n");
       printf("\n");
    }
    free(information);
    free(average);
    delete_db_boards(temps,colsize,size);
}