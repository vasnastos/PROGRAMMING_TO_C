#include <stdio.h>
#include "../sqlite3.h"
#include <stdlib.h>
#include <string.h>

char databasename[100];

typedef struct
{
   char name[100]; 
   char phonenum[100];
   char adress[100];
}phone;

void getdatabasename()
{
    char line[100];
    FILE *fp=fopen("dbname.txt","r");
    while(fgets(line,100,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;
        if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
        strcpy(databasename,line);
    }
    fclose(fp);
}

void createdb()
{
    getdatabasename();
    sqlite3 *db=NULL;
    char sql[200];
    char *errmsg=NULL;
    int res=sqlite3_open(databasename,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return;
    }
    strcpy(sql,"CREATE TABLE IF NOT EXISTS PHONE(FULLNAME VARCHAR(30),PHONENUMBER VARCHAR(30),AREA VARCHAR(20),PRIMARY KEY(FULLNAME,AREA));");
    res=sqlite3_exec(db,sql,0,0,&errmsg);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return;
    }
    else 
    {
        printf("Tables have been created!!!\n");
    }
    sqlite3_free(errmsg);
    sqlite3_close(db);
}

void insert_into_db(char *nam,char *pnum,char *ar)
{
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char *sql;
    int res=sqlite3_open(databasename,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    sql=(char *)malloc(200 * sizeof(char));
    strcpy(sql,"INSERT INTO PHONE(FULLNAME,PHONENUMBER,AREA) VALUES(?,?,?);");
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    sqlite3_bind_text(q,1,nam,-1,SQLITE_STATIC);
    sqlite3_bind_text(q,2,pnum,-1,SQLITE_STATIC);
    sqlite3_bind_text(q,3,ar,-1,SQLITE_STATIC);
    sqlite3_step(q);
    sqlite3_close(db);
    printf("Insertion complete!!!!!!!\n");
    free(sql);
}

int getrecords()
{
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char *sql=NULL;
    int plithos=0;
    int res=sqlite3_open(databasename,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return plithos;
    }
    sql=(char *)malloc(200 * sizeof(char));
    strcpy(sql,"SELECT COUNT(*) FROM PHONE;");
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return plithos;
    }
    if(sqlite3_step(q)==SQLITE_ROW)
    {
        plithos=sqlite3_column_int(q,0);
    }
    sqlite3_close(db);
    free(sql);
    return plithos;
}

void getphonerecords(phone *phones)
{
   sqlite3 *db=NULL;
   sqlite3_stmt *q=NULL;
   char *sql=NULL;
   int res=sqlite3_open(databasename,&db);
   if(res!=SQLITE_OK)
   {
       printf("%s\n",sqlite3_errmsg(db));
       sqlite3_close(db);
       return;
   }
   sql=(char *)malloc(100 * sizeof(char));
   strcpy(sql,"SELECT * FROM PHONE;");
   res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
   if(res!=SQLITE_OK)
   {
       printf("%s\n",sqlite3_errmsg(db));
       sqlite3_close(db);
       return;
   }
   int i=0;
   while(sqlite3_step(q)==SQLITE_ROW)
   {
      strcpy(phones[i].name,(const char *)sqlite3_column_text(q,0));
      strcpy(phones[i].phonenum,(const char *)sqlite3_column_text(q,1));
      strcpy(phones[i].adress,(const char *)sqlite3_column_text(q,2));
      i++;
   }
   sqlite3_close(db);
   free(sql);
}

void driver()
{
    createdb();
    
    int ok;
    while(1)
    {
        printf("DB MENOU::\n");
        printf("1-INSERT ELEMENT\n");
        printf("2-SHOW DATABASE DETAILS\n");
        printf("3-EXIT\n");
        printf("Give choice:");
        scanf("%d",&ok);

        if(ok==1)
        {
            fflush(stdin);
            char name[100];
            char phonenum[100];
            char addr[100];
            printf("Give name:");
            gets(name);
            printf("Give phoneNumber:");
            gets(phonenum);
            printf("Give address:");
            gets(addr);
            insert_into_db(name,phonenum,addr);
        }
        else if(ok==2)
        {
            int length=getrecords();
            phone *phones=(phone *)malloc(length * sizeof(phone));
            getphonerecords(phones);
            for(int i=0;i<length;i++)
            {
                printf("NAME:%s \t PHONE:%s \t ADDRESS:%s\n",phones[i].name,phones[i].phonenum,phones[i].adress);
            }
            free(phones);
        }
        else if(ok==3)
        {
            break;
        }
        else
        {
            printf("Invalid choice!!!\n");
        }  
    }
}

int main()
{
    driver();
    return 0;
}