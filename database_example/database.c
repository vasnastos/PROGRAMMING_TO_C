#include "database.h"

void createdb(char *dbname)
{
    strcpy(databasename,dbname);
    sqlite3 *db=NULL;
    char *errmsg=NULL;
    char sql[100];
    int res=sqlite3_open(databasename,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    strcpy(sql,"CREATE TABLE IF NOT EXISTS PRODUCT(ID INTEGER,FULLNAME VARCHAR(20),PRICE DOUBLE,PRIMARY KEY(ID));");
    res=sqlite3_exec(db,sql,0,0,&errmsg);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        sqlite3_free(errmsg);
        return;
    }
    else 
    {
        printf("Database Table have been created!!!!\n");
    }
    sqlite3_close(db);
}

void inserttodb(int id,char *fn,double pr)
{
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char sql[100];
    int res=sqlite3_open(databasename,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    strcpy(sql,"INSERT INTO PRODUCT(ID,FULLNAME,PRICE) VALUES(?,?,?);");
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    sqlite3_bind_int(q,1,id);
    sqlite3_bind_text(q,2,fn,-1,SQLITE_STATIC);
    sqlite3_bind_double(q,3,pr);
    sqlite3_step(q);
    sqlite3_close(db);
    printf("insertion complete!!!\n");
}

int getrecords()
{
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char sql[100];
    int res=sqlite3_open(databasename,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    }
    int pl=0;
    strcpy(sql,"SELECT COUNT(ID) FROM PRODUCT;");
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    }
    sqlite3_step(q);
    pl=sqlite3_column_int(q,0);
    sqlite3_close(db);
    return pl;
}

void exportfromdb(proion *products)
{
    int size=getrecords();
    if(size==0)
    {
        return;
    }
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char sql[100];
    int res=sqlite3_open(databasename,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    strcpy(sql,"SELECT * FROM PRODUCT;");
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
        int id=sqlite3_column_int(q,0);
        char s[100];
        strcpy(s,(char *)sqlite3_column_text(q,1));
        double pr=sqlite3_column_double(q,2);
        products[i].id=id;
        strcpy(products[i].fullname,s);
        products[i].price=pr;
        i++;
    }
    sqlite3_close(db);
}