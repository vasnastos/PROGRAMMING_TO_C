#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxs 100;
#define rep 6
int getsize()
{
    FILE *fp;
    char fn[100];
    printf("give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    char line[100];
    int cnt=0;
    while(fgets(line,100,fp)!=NULL)
    {
        cnt++;
    }
    fclose(fp);
    return cnt;
}
void filltab(char **acc_name,double *bal)
{
    FILE *fp;
    char fn[100];
    printf("give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    char line[100];
    int j=0;
    while(fgets(line,100,fp)!=NULL)
    {
        char w1[100];
        int cnw1=0;
        char w2[100];
        int cnw2=0;
        int cntp=0;
        for(int i=0;i<strlen(line);i++)
        {
            if(line[i]=='-') cntp++;
            else if(line[i]!='-' && cntp==0)
            {
                w1[cnw1]=line[i];
                cnw1++;
            }
            else if(line[i]!='-' && cntp==1)
            {
                w2[cnw2]=line[i];
                cnw2++;
            }
            else{
                printf("error occurs!!!\n");
                return;
            }
        }
        w1[cnw1]='\0';
        w2[cnw2]='\0';
        strcpy(acc_name[j],w1);
        bal[j]=atof(w2);  
        j++;
    }
    fclose(fp);
}
void withdraw(char **acc,double *bal,int size,int p)
{
    if(p==-1)
    {
        printf("No such pin found!!\n");
    }
    else{
        printf("1-20$\t");
        printf("2-50$\n");
        printf("3-70$\t");
        printf("4-100$\n");
        printf("5-120$\t");
        printf("6-150$\n");
        printf("7-170$\n");
        double am[7]={20.0,50.0,70.0,100.0,120.0,150.0,170.0};
        int x;
        printf("give choice:");
        scanf("%d",&x);
        if(x<0 || x>=7)
        {
            printf("Error unacceptable choice!!!\n");
        }
        else{
            if(bal[p]<am[x])
            {
                printf("you can't withdraw that amount of money!!\n");
            }
            else
            {
                bal[p]-=am[x];
            }
        }
    }
}
void deposit(char **acc,double *bal,int size,int p)
{
    if(p==-1)
    {
        printf("No such id exist in bankinfosystem\n");
        return;
    }
        printf("1-20$\t");
        printf("2-50$\n");
        printf("3-70$\t");
        printf("4-100$\n");
        printf("5-120$\t");
        printf("6-150$\n");
        printf("7-170$\n");
        double am[7]={20.0,50.0,70.0,100.0,120.0,150.0,170.0};
        int x;
        printf("give choice:");
        scanf("%d",&x);
        if(x<0 || x>=7)
        {
            printf("Error unacceptable choice!!!\n");
        }
        else{
            bal[p]+=am[x];
        }
}
void viewmybalance(char **acc,double *bal,int size,int p)
{
    if(p==-1)
    {
        printf("No such pin found!!\n");
        return;
    }
    else
     printf("Id:%s \t BALANCE:%.3lf\n",acc[p],bal[p]);
}
void save_to_file(char **id,double *bal,int size)
{
    FILE *fp=fopen("accounts.txt","w");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"Id:%s \t Balance:%.3lf\n",id[i],bal[i]);
    }
    fclose(fp);
}
void atm(double *bal,char **acc,int size)
{
    fflush(stdin);
    char id[100];
    printf("give id to login:");
    gets(id);
    int p=-1;
    for(int i=0;i<size;i++)
    {
        if(strcmp(id,acc[i])==0)
        {
           p=i; 
        }
    }
    printf("%d\n",p);
    int choice;
    printf("Main menu:\n");
    printf("1-Deposit\n");
    printf("2-Withdraw\n");
    printf("3-Viewmybalance\n");
    printf("Give choice:");
    scanf("%d",&choice);
    if(choice==1)
    {
       deposit(acc,bal,size,p);
    }
    else if(choice==2)
    {
        withdraw(acc,bal,size,p);
    }
    else if(choice==3){
           viewmybalance(acc,bal,size,p);
    }
    else printf("unnacceptable choice!!!\n");
}
void run()
{
    double *balance;
    char **id;
    int size=getsize();
    balance=(double *)malloc(size * sizeof(double));
    id=(char **)malloc(size * sizeof(char *));
    for(int i=0;i<size;i++)
    {
        id[i]=(char *)malloc(size * sizeof(char));
    }
    filltab(id,balance);
    for(int j=0;j<rep;j++)
    {
        atm(balance,id,size);
    }
    save_to_file(id,balance,size);
    for(int i=0;i<size;i++)
    {
        free(id[i]);
    }
    free(id);
    free(balance);
}
int main()
{
    run();
}