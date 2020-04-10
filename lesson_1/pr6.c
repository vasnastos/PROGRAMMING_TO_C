#include <stdio.h>
#include <string.h>
int countlower(char s[])
{
    int cnt=0;
    int size=strlen(s);
    for(int i=0;i<size;i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    char al[20];
    printf("Give string:");
    gets(al);
    printf("%d lower letters\n",countlower(al));
}