#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;
    fp=fopen("STRTOK.txt","r");
    if(fp==NULL)
    {
        printf("No such file found!!\n");
        return 0;
    }
    char line[100];
    while(fgets(line,100,fp)!=NULL)
    {
        if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
        char *n=strtok(line,",-");//(ΑΡΧΕΙΟ ΠΟΥ ΔΙΑΣΠΑΕΙ,ΔΙΑΧΩΡΙΣΤΙΚΟΙ ΧΑΡΑΚΤΗΡΕΣ ΑΡΧΕΙΟΥ!!!!!).
        while(n!=NULL)
        {
            printf("%s\n",n);
            n=strtok(NULL,",-");
        }
    }
    fclose(fp);
}