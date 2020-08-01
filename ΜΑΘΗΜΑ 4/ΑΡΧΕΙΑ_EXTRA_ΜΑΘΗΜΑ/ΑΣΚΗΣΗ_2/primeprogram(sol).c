#include <stdio.h>
#define maxsize 100
int read_content()
{
    int num;
    printf("Give number:");
    scanf("%d",&num);
    return num;
}
int sum_prime(int x)
{
    int sum=0;
    for(int i=2;i<x;i++)
    {
       int cnt=1;
       for(int j=2;j<=i;j++)
       {
           if(i%j==0) cnt++;
       }
       if(cnt==2)
       {
           sum+=i;
       }
    }
    return sum;
}
void store_to_file(char *name,int prime)
{
    FILE *fp;
    fp=fopen(name,"a");
    fprintf(fp,"sum of prime numbers in %d=%d\n",prime,sum_prime(prime));
    fclose(fp);
}

int main()
{
    int choice;
    char fn[maxsize];
    int number;
    printf("Give filename you want to use:");
    gets(fn);
    while(1)
    {
        printf("1-SAVE PRIME SUM TO FILE\n");
        printf("2-DISPLAY DATA FROM FILE\n");
        printf("3-QUIT\n");
        printf("Give choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            number=read_content();
            store_to_file(fn,number);
        }
        else if(choice==2)
        {
            FILE *fp;
            fp=fopen(fn,"r");
            if(fp==NULL)
            {
                printf("No number stored!!!\n");
            }
            char line[100];
            while(fgets(line,100,fp)!=NULL)
            {
                printf("%s\n",line);
            }
            fclose(fp);
        }
        else if(choice==3)
        {
            break;
        }
        else
        {
            printf("unavailable choice,please try again!!!");
        }
    }
}