#include <stdio.h>
#include <string.h>
void string_sort(char s[])
{
   int size=strlen(s);
   int cnt=0;
   for(int i=0;i<size;i++)
   {
       if(s[i]>='0' && s[i]<='9')
        cnt++;
   }
   int temp[cnt];
   for(int i=0;i<size;i++)
   {
       if(s[i]>='0' && s[i]<='9')
        temp[i]=s[i]-'0';
   }
   for(int i=0;i<cnt-1;i++)
   {
      for(int j=0;j<cnt-i-1;j++)
      {
          if(temp[j]>temp[j+1])
          {
              int t=temp[j+1];
              temp[j+1]=temp[j];
              temp[j]=t; 
          }
      }
   }
   int j=0;
   for(int i=0;i<size;i++)
   {
       if(s[i]>='0' && s[i]<='9')
       {
           s[i]=temp[j]+'0';
           j++;
       }
   }
   printf("New_string=%s\n",s);
}
int main()
{
    char d[20];
    printf("GIVE STRING::");
    gets(d);
    string_sort(d);
    return 0;
}