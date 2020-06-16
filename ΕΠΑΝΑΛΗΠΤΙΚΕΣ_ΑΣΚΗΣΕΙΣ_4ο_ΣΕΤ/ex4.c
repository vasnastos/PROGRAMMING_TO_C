#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_mul_of_n(char *string,int N)
{
    int counter=0;
    for(int i=0;i<strlen(string);i++)
    {
        if(string[i]>='0' && string[i]<='9')
        {
            int number=string[i]+'0';
            if(number%N==0)
            {
                counter++;
            }
        }
    }
    return counter;
}

int main()
{
   char string[100];
   int n;
   printf("Give string:");
   gets(string);
   printf("Give number:");
   scanf("%d",&n);
   printf("Multiplies of %d=%d",n,count_mul_of_n(string,n));
}