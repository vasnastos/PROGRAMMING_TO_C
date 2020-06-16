#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void function(int *pin,int size,int N,int *cnt,double *avg)
{
    (*cnt)=0;//Αρχικοποίηση περιεχομένου δείκτη
    int sum=0;
    for(int i=0;i<size;i++)
    {
        if(pin[i]%N==0)
        {
            (*cnt)++;//Αύξηση περιεχομένου δείκτη
        }
        sum+=pin[i];
    }
    *avg=(double)sum/size*1.0;//sizeof(pin)/sizeof(int)-->2-->sizeof(*)-->8
}

int main()
{
    int table[20];
    FILE *fp;
    char filename[100];
    strcpy(filename,"numbers.txt");
    //filename=numbers.txt-->Αντιγραφή από αλφαριθμητικό σε αλφαριθμητικό
    fp=fopen(filename,"r");
    //fgets(line,x,fp)-->Διαβάζει γραμμή γραμμή το αρχείο//Ανάθεση γραμμής σε αλφαριθμητικό.
    char line[200];
    int i=0;
    while(fgets(line,200,fp)!=NULL)
    {
        if(line[0]=='#') continue;//Ελέγχει αν η γραμμή ξεκινάει με # και αν ισχύει την παραλείπει
        if(line[0]=='\n') continue;
        if(line[strlen(line)-1]=='\n')//line->geia\n      strcmp(line,"geia");
        {
            line[strlen(line)-1]='\0';
        }
        char *token=strtok(line,":");
        token=strtok(NULL,":");
        table[i]=atoi(token);//Μετατροπή αλφαριθμητικού σε ακέραιο
        i++;
    }
    fclose(fp);
    int number,counter;
    double average;
    printf("Give number:");
    scanf("%d",&number);
    function(table,20,number,&counter,&average);
    printf("AVERAGE:%.2lf\n",average);
    printf("Multiplies of number %d:%d\n",number,counter);
}