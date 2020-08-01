#include <stdio.h>
#include <string.h>
int sum_fromstring(char k[])
{
    int acc=0;
    int s=strlen(k);
    for(int i=0;i<s;i++)
    {
       if(k[i]>='0' && k[i]<='9')
       acc+=k[i]-'0';
    }
    return acc;
}
int main()
{
    char s[]="asdf4h5k1l9k2v";
    printf("sum of string numbers=%d",sum_fromstring(s));
    return 0;
}