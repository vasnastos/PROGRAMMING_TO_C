#include <stdio.h>
#include <string.h>
int k=1;
void remove_pos(char s[],int i)
{
    for(int j=i;j<strlen(s)-1;j++)
    {
        s[j]=s[j+1];
    }
    s[strlen(s)-1]='\0';
    printf("new String_%d:%s\n",k,s);
    k++;
}
int main()
{
    int p;
    char n[4][20];
    for(int i=0;i<4;i++)
    {
        printf("Give string:");
        gets(n[i]);
        printf("\n");
    }
   for(int i=0;i<4;i++)
  {
      do {
      printf("give position you want to erase:");
      scanf("%d",&p);
      }while(p<0 || p>strlen(n[i]));
      remove_pos(n[i],p);
  }
  return 0;
}