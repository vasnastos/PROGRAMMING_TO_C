#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

typedef struct
{
    int id;
    char fullname[100];
    double price;
}proion;

char databasename[100];

void createdb(char *dbname);
void inserttodb(int id,char *fn,double pr);
int getrecords();
void save_to_file();
void exportfromdb(proion *products);