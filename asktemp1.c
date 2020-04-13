#include <stdio.h>
#include <string.h>
int main()
{

  while(1)
  {
      char word[20];
      printf("Give word:");
      gets(word);
      if(strcmp(word,"stop")==0)
      {
          break;
      }
  }
}