#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Εύρεση Εγγραφών σε αρχείο
char fn[100];//Δήλωση ονόματος  αρχείου

int getsize()
{
    FILE *fp=fopen(fn,"r");
    if(fp==NULL)
    {
        return 0;
    }
    char line[100];
    int counter=0;
    while(fgets(line,100,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;
        counter++;
    }
    fclose(fp);
    return counter;
}

void readdata(int *data)
{
    FILE *fp=fopen(fn,"r");//Άνοιγμα αρχείου για διάβασμα
    char line[100];
    int i=0;
    while(fgets(line,100,fp)!=NULL)//Διάβασμα γραμμής από αρχειο
    {
        if(line[0]=='\n') continue;
        if(line[strlen(line)-1]=='\n') line[strlen(line)-1]=='\0';
        if(line[0]=='#') continue;
        data[i]=atoi(line);//atoi -->Μετατροπεί αλφαριθμητικού σε ακέραιο
        i++;
    }
    fclose(fp);
}
void append_to_file(int *data,int size)
{
    FILE *fp=fopen(fn,"a");//Άνοιγμα αρχείου για προσθήκη
    fprintf(fp,"SORT NUMBERS\n");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"INTEGER_%d:%d\n",i+1,data[i]);//Εκτύπωση σε αρχείο
    }
    fclose(fp);
}

void sort_board(int *data,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(data[j]>data[j+1])
           { 
              int temp=data[j];
              data[j]=data[j+1];
              data[j+1]=temp;
           }
        }
    }
}

void add_AVERAGE(int *data,int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=data[i];
    }
    double average=(double)sum/size;
    FILE *fp=fopen(fn,"a");
    fprintf(fp,"AVERAGE:%.2lf\n",average);
    fclose(fp);
}

int main()
{
    strcpy(fn,"demo.txt");
    int size=getsize();
    if(size==0)
    {
        exit(EXIT_FAILURE);
    }
    int *data=(int *)malloc(size * sizeof(int));
    readdata(data);
    sort_board(data,size);
    append_to_file(data,size);
    free(data);
}