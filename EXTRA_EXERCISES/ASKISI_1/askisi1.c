#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int alldigits(char *k)
{
    int cnt=0;
    int s=strlen(k);
    for(int i=0;i<s;i++)
    {
        if(*(k+i)>='0' && *(k+i)<='9')
        cnt++;
    }
    if(cnt==s) return 0;
    return 1;
}
int dates(char s[][20],int size)
{
    int cnt=0;
    for(int i=0;i<size;i++)
    {
      char day[20];
      char month[20];
      char year[20];
      int cd=0;
      int cm=0;
      int cy=0;
      int split=0;
      int size=strlen(s[i]);
      int j=0;
      while(j<size)
      {
         if(s[i][j]=='/') split++;
         else if(s[i][j]!='/' && split==0)
         {
             day[cd]=*(s[i]+j);
             cd++;
         }
         else if(s[i][j]!='/' && split==1)
         {
             month[cm]=*(s[i]+j);
             cm++;
         }
         else if(s[i][j]!='/' && split==2)
         {
             year[cy]=*(s[i]+j);
             cy++;
         }
         j++;
      }
      day[cd]='\0';
      month[cm]='\0';
      year[cy]='\0';
      int invalid=1;
      if(strlen(day)!=2 || strlen(month)!=2 || strlen(year)!=4)
      {
          invalid=0;
          printf("%s/%s/%s:invalid date\n",day,month,year);
      }
      if((alldigits(day)==1 || alldigits(month)==1 || alldigits(year)==1) && invalid==1)
      {
          invalid=0;
          printf("%s/%s/%s:invalid date\n",day,month,year);
      }
      int d=atoi(day);
      int m=atoi(month);
      int y=atoi(year);
      if((d>30 || d<0 || m<0 || m>12 || y>2020 || y<1900) && invalid==1)
      {
          invalid=0;
          printf("%s/%s/%s:invalid date\n",day,month,year);
      }
      else{
          if(invalid==1)
          {
            cnt++;
            printf("%s/%s/%s:valid date\n",day,month,year);
          }
      }
    }
    return cnt;
}
int main()
{
    char dat[8][20];
    printf("CHECK DATE PROGRAM::\n");
    for(int i=0;i<8;i++)
    {
        printf("give date:");
        gets(dat[i]);
    }
    printf("%d valid dates\n",dates(dat,8));
}