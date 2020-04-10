#include <stdio.h>
#include <string.h>
void deletepos(char s[],int p)
{
    for(int i=p;i<strlen(s)-1;i++)
    {
        s[i]=s[i+1];
    }
    s[strlen(s)-1]='\0';
}
int main()
{
    char al[20];
    printf("Give string:");
    gets(al);
    int pos;
    do {
      printf("give position you want to erase:");
      scanf("%d",&pos);
    }while(pos<0 || pos>=strlen(al));
    deletepos(al,pos);
    printf("%s\n",al);
}