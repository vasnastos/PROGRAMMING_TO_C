#include <stdio.h>
int main()
{
    FILE *fp;
    char fn[100];
    do
    {
      printf("give filename:");
      gets(fn);
    }while(strlen(fn)==0);  
    int a[]={0,1,2,3,4,5,6,7,8,9};
    int size=sizeof(a)/sizeof(a[0]);
    fp=fopen(fn,"w");
    for(int i=0;i<size;i++)
    {
        char ch='a'+a[i];
        fputc(ch,fp);
    }
    fclose(fp);
}