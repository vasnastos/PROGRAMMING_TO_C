#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#######BANK INFORMATION####################
char type[3][100]={"SAVINGS",
                   "MONEY_MARKET",
                   "COMPANY_ACCOUNT"};
double interest_rate[3]={2.5,3,3.5};

typedef struct 
{
    char accountid[100];
    char name[100];
    double balance;
    char account_type[100];
}account;

void add_interest(account *accs,int size)
{
   for(int i=0;i<size;i++)
   {
       int pos=-1;
       for(int j=0;j<3;j++)
       {
           if(strcmp(accs[i].account_type,type[j])==0)
           {
               pos=j;
           }
       }
       accs[i].balance+=((accs[i].balance*interest_rate[pos])/100.0);
   }
}

void showbytype(account *accs,int size)
{
    for(int j=0;j<3;j++)
    {
        for(int i=0;i<size;i++)
        {
            if(strcmp(accs[i].account_type,type[j])==0)
            printf("ACCOUNT ID:%s \t ΝΑΜΕ:%s \t BALANCE:%.2lf \t ACCOUNT_TYPE:%s\n",accs[i].accountid,accs[i].name,accs[i].balance,accs[i].account_type);
        }
    }
} 

void sort(account *accs,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(accs[j].balance>accs[j].balance)
            {
                account temp=accs[j];
                accs[j]=accs[j+1];
                accs[j+1]=temp;
            }
        }
    }
    FILE *fp=fopen("accounts.txt","w");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"ACCOUNT ID:%s \t ΝΑΜΕ:%s \t BALANCE:%.2lf \t ACCOUNT_TYPE:%s\n",accs[i].accountid,accs[i].name,accs[i].balance,accs[i].account_type);
    }
    fclose(fp);
}

int main()
{
    account accounts[10];
    int j;
    for(int i=0;i<10;i++)
    {
        fflush(stdin);
        printf("Give account_Id:");
        gets(accounts[i].accountid);
        printf("Give name:");
        gets(accounts[i].name);
        printf("Give balance:");
        scanf("%lf",&accounts[i].balance);
        do {
          printf("Give number of type:");
          scanf("%d",&j);
        }while(j<0 || j>3);
        strcpy(accounts[i].account_type,type[j]);
    }
    add_interest(accounts,10);
    showbytype(accounts,10);
    sort(accounts,10);
}