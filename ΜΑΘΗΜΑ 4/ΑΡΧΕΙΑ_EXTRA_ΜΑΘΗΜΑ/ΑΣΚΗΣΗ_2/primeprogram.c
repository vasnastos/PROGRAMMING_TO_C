#include <stdio.h>
#define maxsize 100
int read_content()
{
    //to be implement
}
void store_to_file(char *name,int prime)
{
    //to be implement
}
int sumprime(int x)
{
    //to be implement
}
int main()
{
    int choice;
    char fn[maxsize];
    int number;
    printf("Give filename you want to store you data:");
    //to be implement
    while(1)
    {
        printf("1-SAVE PRIME SUM TO FILE\n");
        printf("2-DISPLAY DATA FROM FILE\n");
        printf("3-QUIT\n");
        printf("Give choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            //to be implement
        }
        else if(choice==2)
        {
            //to be implement
        }
        else if(choice==3)
        {
            //to be implement
        }
        else
        {
            printf("unavailable choice,please try again!!!");
        }
    }
}