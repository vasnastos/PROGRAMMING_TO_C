#include <stdio.h>
#include <string.h>
int main()
{
    char lowcaseletters[26];
    char digits[10];
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<26;i++)
    {
       lowcaseletters[cnt1]='a'+i;
       cnt1++;
       if(i<10)
       {
           digits[cnt2]='0'+i;
           cnt2++;
       }
    }
    lowcaseletters[cnt1]='\0';
    digits[cnt2]='\0';
    printf("LOWERCASE:%s\n",lowcaseletters);
    printf("DIGITS:%s\n",digits);
}