#include <stdio.h>
#include <string.h>
int countlowletters(char s[])
{
    int size=strlen(s);
    int cnt=0;
    for(int i=0;ii<size;i++)
    {
        if(s[i]>='a' && s[i]<='z') cnt++;
    }
    return cnt;
}
int main()
{
    char s[20];
    printf("Give string:");
    gets(s);
    printf("%d low_letters\n",countlowletters(s));
}