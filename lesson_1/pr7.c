#include <stdio.h>
#include <string.h>
void countelements(char s[])
{
    int countletters=0;
    int countdigits=0;
    int size=strlen(s);
    for(int i=0;i<size;i++)
    {
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')) countletters++;
        if(s[i]>='0' && s[i]<='9') countdigits++;
    }
    printf("String:%s\n",s);
    printf("letters:%d\n",countletters);
    printf("Digits:%d\n",countdigits);
}
int main()
{
    char al[20];
    printf("Give string:");
    gets(al);
    countelements(al);
}