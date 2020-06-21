#include <stdio.h>
#include <stdlib.h>

#define s 200

typedef struct
{
    char accnum[s];
    char ownername[s];
    double balance;
}account;

char filename[s];
account *accs;
int size=-1;

int getsize()
{
    int counter=0;
    char line[s];
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        return 0;
    }
    while(fgets(line,s,fp)!=NULL)
    {
        if(line[0]=='#')
        continue;
        if(line[0]=='\n')
        continue;
       counter++;
    }
    fclose(fp);
    return counter;
}

void readata()
{
    char line[s];
    int i=0;
    FILE *fp=fopen(filename,"r");
    while(fgets(line,s,fp)!=NULL)
    {
        if(line[0]=='#') continue;
        if(line[0]=='\n') continue;

        char *token=strtok(line,"-");
        strcpy(accs[i].accnum,token);
        token=strtok(NULL,"-");
        strcpy(accs[i].ownername,token);
        token=strtok(NULL,"-");
        accs[i].balance=atof(token);
        i++;
    }
    fclose(fp);
}

void deposit(char *accn)
{
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(strcmp(accs[i].accnum,accn)==0)
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
        perror("No such account found please enter a valid account number!!!\n");
        return;    
    }
    double extra_balance;
    printf("Give the extra amount you want to add to your account:");
    scanf("%lf",&extra_balance);
    accs[pos].balance+=extra_balance;
}

void withdraw(char *accn)
{
    double available_amounts[]={20.0,40.0,60.0,100.0,200.0};
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(strcmp(accs[i].accnum,accn)==0)
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
        perror("No such account found please enter a valid account number!!!\n");
        return;    
    }
    int op;
    do{
      printf("WITHDRAW MENU::::\n");
      printf("WITHDRAW OPTIONS:::\n");
      printf("1-20\t4-100.0\n");
      printf("2-40.0\t5-200.0\n");
      printf("3-60.0\t6-Cancel Transaction\n");
      do
      {
         printf("Give option:");
         scanf("%d",&op);
         if(op==6)
         {
             return;
         }
      } while (op<1 || op>6);
      if(accs[pos].balance<available_amounts[op-1])
      {
          printf("Invalid amount of withdraw,Please choose a smaller amount");
      }
    } while (accs[pos].balance<available_amounts[op-1]);
    accs[pos].balance-=available_amounts[op-1];
}

void findbalance(char *accn)
{
    int pos=-1;
    for(int i=0;i<size;i++)
    {
        if(strcmp(accs[i].accnum,accn)==0)
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
        perror("No such account found please enter a valid account number!!!\n");
        return;    
    }
    printf("BALANCE OF ACCOUNT NUMBER:%s is:%lf\n",accn,accs[pos].balance);
}

char* getinput()
{
    char *connected=NULL;
    char accn[s];
    printf("Give your account number:");
    gets(accn);
    for(int i=0;i<size;i++)
    {
        if(strcmp(accs[i].accnum,accn)==0)
        {
            connected=(char *)malloc(s * sizeof(char));
            strcpy(connected,accs[i].accnum);
            return connected;
        }
    } 
    return connected;
}

int main_menu()
{
    int choice;
    printf("Welcome to main menu::\n");
    printf("CHOICES:\n");
    printf("#######################\n");
    printf("1-Deposit Money\n");
    printf("2-Withdraw Money\n");
    printf("3-Find Balance Inquiry\n");
    printf("4-Exit and terminate App\n");
    printf("Give your choice:");
    scanf("%d",&choice);
    return choice;
}


int main()
{
    size=getsize();
    if(size==0)
    {
        perror("No file found you don't have any valid records\n");
        exit(EXIT_SUCCESS);
    }
    accs=(account *)malloc(size * sizeof(account));
    readata(accs);
    char *conacc;
    int ch;
    while(1)
    {
        conacc=getinput();
        if(conacc==NULL)
        {
            continue;
        }
        ch=main_menu();
        printf("CLIENT:%s CONNECTED TIME:%s\n",conacc,__TIME__);
        printf("#######################################\n");
        if(ch==1)
        {
            deposit(conacc);
            printf("DEPOSIT:%s\n",__TIME__);
        }
        else if(ch==2)
        {
           withdraw(conacc);
           printf("WITHDRAW:%s\n",__TIME__);
        }
        else if(ch==3)
        {
            findbalance(conacc);
            printf("BALANCE CHECK:%s\n",__TIME__);
        }
        else if(ch==4)
        {
            free(accs);
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("invalid choice\n");
        }
        free(conacc);
        printf("CLIENT:%s DISCONNECTED TIME:%s\n",conacc,__TIME__);
        printf("#######################################\n");
    }
}