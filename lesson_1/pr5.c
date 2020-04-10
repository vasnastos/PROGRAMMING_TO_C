#include <stdio.h>
#include <string.h>
int accumulate(char s[])
{
    int size=strlen(s);
    int sum=0;
    for(int i=0;i<size;i++)
    {
      if(s[i]>='0' && s[i]<='9')
      {
          sum+=s[i]-'0';
      }
    }
    return sum;
}
int main()
{
    char al[20];
    printf("Give string:");
    gets(al);
    printf("Sum of string numbers=%d\n",accumulate(al));
}