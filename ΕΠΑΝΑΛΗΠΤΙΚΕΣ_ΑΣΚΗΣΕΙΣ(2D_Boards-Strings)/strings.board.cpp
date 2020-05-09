#include <stdio.h>
#include <string.h>
int main()
{
    char s[3][20];
    for(int i=0;i<3;i++)
    {
        gets(s[i]);
    }
    for(int i=0;i<3;i++)
      printf("%s\n",s[i]);
    return 0;
}