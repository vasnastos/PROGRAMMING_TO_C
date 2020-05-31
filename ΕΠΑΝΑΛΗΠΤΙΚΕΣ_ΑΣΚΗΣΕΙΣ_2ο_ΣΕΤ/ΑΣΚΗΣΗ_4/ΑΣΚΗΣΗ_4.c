#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char alphanumeric[100];
    FILE *fp=fopen("sum.txt","a");
    fprintf(fp,"STRING \t SUM\n");
    while(1)
    {
        char splt[100];
        printf("give alphanumeric:");
        gets(alphanumeric);
        if(strcmp(alphanumeric,"quit")==0)
        int j=0;
        int sum=0;
        for(int i=0;i<strlen(alphanumeric);i++)
        {
            if(alphanumeric[i]>='0' && alphanumeric[i]<='9')
            {
                splt[j]=alphanumeric[i];
            }
            else
            {
                continue;
            }
            
            if(alphanumeric[i+1]>='0' && alphanumeric[i+1]<='9')
            {
                j++;
            }
            else
            {
                j++;
                splt[j]='\0';
                sum+=atoi(splt);
                j=0;
                strcpy(splt,"");
            }  
        }
        fprintf(fp,"STRING:%s\t SUM:%d\n",alphanumeric,sum);
    }
    fclose(fp);
}