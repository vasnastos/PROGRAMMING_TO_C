#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
   char s[20];
   printf("give string:");
   gets(s);
   printf("%d\n",atoi(s));
   printf("%d\n",atoi("44"));
}