#include <stdio.h>
#include <string.h>
#define maxs 100
void sort(int *a,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void tobinary(int *a,char bin[][maxs],int size)
{
    sort(a,size);
    for(int i=0;i<size;i++)
    {
       int temp=a[i];
       char temp1[maxs];
       int j=0;
       while(temp!=0)
       {
           temp1[j]=(temp%2)+'0';
           temp/=2;
           j++;
       }
       while(j<8)
       {
           temp1[j]='0';
           j++;
       }
       temp1[j]='\0';
      int k=0;
      for(int l=strlen(temp1)-1;l>=0;l--)
      {
          bin[i][k]=temp1[l];
          k++;
      }
      bin[i][k]='\0';
    }
}
void printtofile(int *a,char bin[][maxs],int size)
{
    FILE *fp;
    char fn[maxs];
    fflush(stdin);
    printf("give filename:");
    gets(fn);
    fp=fopen(fn,"w");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"%d-%s\n",*(a+i),bin[i]);
    }
    fclose(fp);
}
void fillnumber(int *a,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
}
void run()
{
    int pin[6];
    char bin[6][maxs];
    fillnumber(pin,6);
    tobinary(pin,bin,6);
    printtofile(pin,bin,6);
}
int main()
{
   run();
}