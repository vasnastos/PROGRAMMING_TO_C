#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define r 10
#define c 4
void boot(int addr[][c],int r1[],int r2[])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            addr[i][j]=rand()%2;
        }
    }
    for(int i=0;i<c;i++)
    {
        r1[i]=0;
        r2[i]=0;
    }
}
}
int loadR1(int addr[][c],int r1[],int address)
{
    if(address>=0 && address<=9)
    {
        for(int i=0;i<c;i++)
        {
            r1[i]=addr[address][i];
        }
        return 0;
    }
    else
    {
        return 1;
    }
    
}
int loadR2(int addr[][c],int r2[],int address)
{
    if(address>=0 && address<=9)
    {
        for(int i=0;i<c;i++)
        {
            r2[i]=addr[address][i];
        }
        return 0;
    }
    else
    {
        return 1;
    }
}
void splitstring(char cmd[],char w1[],char w2[],char w3[])
{
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    int cnts=0;
    for(int i=0;i<strlen(cmd);i++)
    {
       if(cmd[i]!=' ' && cnts==0)
       {
           w1[cntt1]=cmd[i];
           cnt1++;
       }
       else if(cmd[i]!=' ' && cnts==1)
       {
           w2[cnt2]=cmd[i];
           cnt2++;
       }
       else if(cmd[i]!=' ' && cnts==2)
       {
           w3[cnt3]=cmd[i];
           cnt3++;
       }
       else if(cmd[i]==' ')
       {
           cnts++;
       }
       else
       {
           continue;
       }
       w1[cnt1]='\0';
       w2[cnt2]='\0';
       w3[cnt3]='\0';
    }
}
int main()
{
    int address[r][c];
    int R1[c];
    int R2[c];
    char cmd[20];
    char word1[20],word2[20],word3[20];
    while(1)
    {
        printf("Give command:::");
        gets(cmd);
        splitstring(cmd,word1,word2,word3);
        if(strcmp(word1,"BOOT")==0)
        {
            boot();
        } 
        else if(strcmp(word1,"LOAD")==0)
        {
            int x;
            if(strlen(word3)!=1)
            {
               x=10;
            }
            else
            {
                x=word3[0]-'0';
            }
            if(strcmp(word2,"R1"))
            {
                int res=loadR1(address,R1,x);
                if(res==0)
                {
                    printf("Load to register R1 complete!!\n");
                }
                else{
                    printf("No such memory address found!!\n");
                }
            }
            else if(strcmp(word2,"R2"))
            {
                int res=loadR2(address,R2,x);
                if(res==0)
                {
                    printf("Load to register R2 complete!!\n");
                }
                else{
                    printf("No such memory address found!!\n");
                }
            }
            else
            {
                printf("No such register found!!!\n");
            }     
        }
        else if(strcmp(word1,"STOP"))
        {
            printf("Thank you for using microcomputer!!\n");
            break;
        }
    }
}