#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
#define s 200

//Όνομα βάσης δεδομένων μου.
char db_name[s];

//Δομή οντότητας που θα αναπαριστά τα στοιχεία από την βάση δεδομένων σε τύπο.
typedef struct 
{
    char period[s];
    char status[s];
    char sex[s];
    char age[s];
    int pop;
}population;

//Διάβασμα ονόματος βάσης δεδομένων από αρχείο
void read_db_name()
{
    char line[s];
    FILE *fp=fopen("dbname.txt","r");
    while(fgets(line,s,fp)!=NULL)
    {
       if(line[0]=='#') continue;
       if(line[0]=='\n') continue;
       if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
       strcpy(db_name,line);
       break;
    }
    fclose(fp);
}

//Δημιουργία βάσης δεδομένων και πίνακα στην βάση δεδομένων.
void create_db()
{
    sqlite3 *db=NULL;
    char *err_msg;
    char *sql;
    int res=sqlite3_open(db_name,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
    sql=(char *)malloc(s * sizeof(char));
    strcpy(sql,"create table if not exists population(period varchar(20),status varchar(5),sex varchar(20),age varchar(10),pop integer,primary key(period,sex,age));");
    res=sqlite3_exec(db,sql,0,0,&err_msg);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_free(db);
        sqlite3_close(db);
    }
    else
    {
        printf("Hello world from database!!!!\n");
    }
    free(sql);
    sqlite3_free(err_msg);
    sqlite3_close(db);
}

//Εισαγωγή δεδομένων στην Βάση
void insert_to_db(char *p,char *st,char *sx,char *ag,size_t pop)
{
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char *sql;
    int res=sqlite3_open(db_name,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg);
        sqlite3_close(db);
    }
    sql=(char *)malloc(s * sizeof(char));
    strcpy(sql,"insert into population(period,status,sex,age,pop) values(?,?,?,?,?);");
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    sqlite3_bind_text(q,1,p,-1,SQLITE_STATIC);
    sqlite3_bind_text(q,2,st,-1,SQLITE_STATIC);
    sqlite3_bind_text(q,3,sx,-1,SQLITE_STATIC);
    sqlite3_bind_text(q,4,ag,-1,SQLITE_STATIC);
    sqlite3_bind_int(q,5,pop);
    sqlite3_step(q);
    sqlite3_close(db);
    free(sql);
}

//Ανάγνωση δεδομένων από αρχείο csv και εισαγωγή τους στην βάση δεδομένων.
void read_data()
{
    char line[s];
    FILE *fp=fopen("source_population_in_c_db.csv","r");
    while(fgets(line,s,fp)!=NULL)
    {
       if(line[0]=='#') continue;
       if(line[0]=='\n') continue;
       if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
       char *token=strtok(line,",");
       population p;
       strcpy(p.period,token);
       token=strtok(NULL,",");
       strcpy(p.status,token);
       token=strtok(NULL,",");
       strcpy(p.sex,token);
       token=strtok(NULL,",");
       strcpy(p.age,token);
       token=strtok(NULL,",");
       p.pop=atoi(token);
       insert_to_db(p.period,p.status,p.sex,p.age,p.pop);
    }
    fclose(fp);
}

//Έυρεση αριθμού μοναδικών ηλικιών από βάση δεδομένων
int count_distinct_ages()
{
    sqlite3* db=NULL;
    sqlite3_stmt *q=NULL;
    char sql[200];
    int res=sqlite3_open(db_name,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    }
    strcpy(sql,"select distinct age from population;");
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    }
    int counter=0;
    while(sqlite3_step(q)==SQLITE_ROW)
    {
        counter++;
    }
    sqlite3_close(db);
    return counter;
}

//Εύρεση ηλικιών από την βάση δεδομένων
void get_ages(char **ages)
{
    sqlite3* db=NULL;
    sqlite3_stmt *q=NULL;
    char sql[200];
    int res=sqlite3_open(db_name,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    strcpy(sql,"select distinct age from population;");
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
        strcpy(ages[i],(char *)sqlite3_column_text(q,0));
        i++;
    }
    sqlite3_close(db);
}

//Εύρεση πληθυσμού με βάση την ηλικία για όλες τις καταγγεγραμένες ηλικίες της βάσης δεδομένων μου.
void find_population_per_age()
{
    char **ages;
    int count=count_distinct_ages();
    ages=(char **)malloc(count * sizeof(char *));
    for(int i=0;i<count;i++)
    {
        ages[i]=(char *)malloc(s * sizeof(char));
    }
    get_ages(ages);
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char *sql;
    int res=sqlite3_open(db_name,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    sql=(char *)malloc(s * sizeof(char));
    strcpy(sql,"select period,status,sex,pop from population where age=?;");
    int size=count_distinct_ages();
    for(int i=0;i<size;i++)
    {
        res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
        if(res!=SQLITE_OK)
       {
          printf("%s\n",sqlite3_errmsg(db));
          sqlite3_close(db);
          return;
       }
       sqlite3_bind_text(q,1,ages[i],-1,SQLITE_STATIC);
       printf("*********** AGE:%s **********************\n",ages[i]);
       while(sqlite3_step(q)==SQLITE_ROW)
       {
           printf("Period:%s\t",(char *)sqlite3_column_text(q,0));
           printf("Status:s\t",(char *)sqlite3_column_text(q,1));
           printf("Sex:%s\t",(char *)sqlite3_column_text(q,2));
           printf("population:%d\n",sqlite3_column_int(q,3));
       }
       printf("******************************************\n");
    }
    free(sql);
    for(int i=0;i<count;i++)
    {
        free(ages[i]);
    }
    free(ages);
    sqlite3_close(db);
}


//Εύρεση πληροφοριών με βάση το φύλο.
void find_per_gender()
{
    int j;
    char gender[3][s]={"female","male","total"};
    do{
       printf("search by gender[1/female,2/male,3/total info],please give your choice:");
       scanf("%d",&j);
       if(j<1 || j>3)
       {
           printf("Invallid choice please try again!!!\n");
       }
    }while(j<1 || j>3);
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char *sql;
    int res=sqlite3_open(db_name,&db);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    printf("ok");
    sql=(char *)malloc(s * sizeof(char));
    strcpy(sql,"select period,status,age,pop from population where sex=?;");
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    sqlite3_bind_text(q,1,gender[j-1],-1,SQLITE_TRANSIENT);
    printf("********************* AGE INFORMATION **************************\n");
    while(sqlite3_step(q)==SQLITE_ROW)
    {
        printf("Period:%s\t",(char *)sqlite3_column_text(q,0));
        printf("Status:%s\t",(char *)sqlite3_column_text(q,1));
        printf("Age:%s\t",(char *)sqlite3_column_text(q,2));
        printf("Population:%d\n",sqlite3_column_int(q,3));
    }
    printf("******************************************************************\n");
    sqlite3_close(db);
    free(sql);
}

//Αποθήκευση συνολικών πληροφοριών σε csv αρχείο.
void save_total_info_to_csv()
{
    fflush(stdin);
    char filename[s];
    printf("Give filename:");
    gets(filename);
    sqlite3 *db=NULL;
    sqlite3_stmt *q=NULL;
    char sql[s];
    int res=sqlite3_open(db_name,&db);
    if(res!=SQLITE_OK){
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    strcpy(sql,"select period,status,age,pop from population where sex='total';");
    if(res!=SQLITE_OK){
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    res=sqlite3_prepare_v2(db,sql,-1,&q,NULL);
    if(res!=SQLITE_OK){
        printf("%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    FILE *out=fopen(filename,"w");
    fprintf(out,"********************** INFORMATION BY GENDER *****************\n");
    int count=0;
    while(sqlite3_step(q)==SQLITE_ROW)
    {
        count++;
        fprintf(out,"Period:%s   ",(char *)sqlite3_column_text(q,0));
        fprintf(out,"Status:%s   ",(char *)sqlite3_column_text(q,1));
        fprintf(out,"Age:%s      ",(char *)sqlite3_column_text(q,2));
        fprintf(out,"Population:%d\n",sqlite3_column_int(q,3));
    }
    fprintf(out,"****************************************************************\n");
    sqlite3_close(db);
    fclose(out);
}

//Κύριο μενού εφαρμογής.
int main_menu()
{
    int ch;
    printf("Main Menu::\n");
    printf("1-Information per age\n");
    printf("2-Find information per gender\n");
    printf("3-Save to csv form\n");
    printf("4-Exit\n");
    printf("Give choice:");
    scanf("%d",&ch);
    return ch;
}

//Συνάρτηση που εκκινεί το πρόγραμμα και τρέχει τις διαδικασίες.
void runnable()
{
    read_db_name();
    create_db();
    int choice;
    while(1)
    {
        choice=main_menu();
        if(choice==1)
        {
            find_population_per_age();
        }
        else if(choice==2)
        { 
            find_per_gender();
        }
        else if(choice==3)
        {
            save_total_info_to_csv();
        }
        else if(choice==4)
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("Invalid choice!!!!\n");
        } 
    }
}

//Κύρια συνάρτηση προγράμματος.
int main()
{
    runnable();
    return 0;
}