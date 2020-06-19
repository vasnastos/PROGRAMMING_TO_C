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
    //implemantation
}

void deposit(char *accn)
{
    //implentation
}

void withdraw(char *accn)
{
    //implementation
}

void findbalance(char *accn)
{
    //implemantation
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
            connected=(struct char *)malloc(s * sizeof(char))
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