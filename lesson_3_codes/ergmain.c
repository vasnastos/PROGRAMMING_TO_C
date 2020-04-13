#include <stdio.h>
#include <string.h>
void splitstring(char pr[],char w1[],char w2[],char w3[])
{
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    int cntw=0;
    for(int i=0;i<strlen(pr);i++)//LOAD R1 6
    {
        if(pr[i]!=' ' && cntw==0)//LOAD i=5
        {
            w1[cnt1]=pr[i];
            cnt1++;
        }
        else if(pr[i]!=' ' && cntw==1)
        {
          w2[cnt2]=pr[i];//R->w[0]
          cnt2++;
        }
        else if(pr[i]!=' ' && cntw==2)
        {
            w3[cnt3]=pr[i];
            cnt3++;
        }
        else if(pr[i]==' ')
        {
            cntw++;
        }
        else
        {
            continue;
        }
    }
    w1[cnt1]='\0';
    w2[cnt2]='\0';
    w3[cnt3]='\0';
}
int main()
{
    char command[20];//LOAD R1 6
    char word1[20];//BOOT
    char word2[20];
    char word3[20];//'0''1'----'9'
    while(1)
    {
        printf("Dwse entoli:");
        gets(command);
        splitstring(command,word1,word2,word3);
        if(strcmp(word1,"BOOT")==0)
        {
            boot();
        }
        else if(strcmp(word1,"LOAD")==0)
        {
            if(strlen(word3)!=1)
            {
               printf("No such register exists!!\n");
               break;
            }
            else
            {
              int adr=word3[0]-'0';//'0' '1' ---'9'-'0'->9
              if(strcmp(word2,"R1")==0)
              {
                int call=loadR1(adress,R1,adr);
                printf("Load to register r1 complete!!");
                printf("%d\n",call);
              }
            }
        }
        
    }
}