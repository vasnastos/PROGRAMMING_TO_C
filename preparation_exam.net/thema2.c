#include <stdio.h>
#include <string.h>

int replaceStr(char *str,char letter)
{
    int j=0;
    for(int i=0,k=strlen(str);i<k;i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            str[i]=letter;
            j++;
        }
    }
    return j;
}
int main()
{
    char string[200];
    char letter;
    printf("Give string:");
    gets(string);
    printf("Give replace letter:");
    letter=getchar();
    fflush(stdin);
    char line[100];
    printf("Give filename:");
    gets(line);
    FILE *fp=fopen(line,"w");
    fprintf(fp,"Letters replaced:%d\n",replaceStr(string,letter));
    fprintf(fp,"NEW STRING:%s\n",string);
    fclose(fp);
}