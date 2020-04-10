#include <stdio.h>
#include <string.h>
void delete_string(char k[],int j)
{
    int s=strlen(k);
    for(int i=j;i<s;i++)
    {
        k[i]=k[i+1];
    }
    k[strlen(k)]='\0';
}
int main()
{
    char s[]="delete";
    delete_string(s,3);
    printf("New String=>%s",s);
    return 0;
}