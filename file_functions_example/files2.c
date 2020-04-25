#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxs 100
int main()
{
    FILE *fp;
    fp=fopen("files1.txt","r");
    //With fscanf
    char line[maxs];
    int cnt=0;
    while(fgets(line,maxs,fp)!=NULL)
    {
        cnt++;
    }
    fclose(fp);
    int *board;
    board=(int *)malloc(cnt * sizeof(int));
    fp=fopen("files1.txt","r");
    int j=0;
    while(fgets(line,maxs,fp)!=NULL)
    {
        if(strlen(line)!=1) return 0;
        line[strlen(line)-1]='\0';
        board[j]=atoi(line);
        j++;
    }
    fclose(fp);
    for(int i=0;i<cnt;i++)
    {
      printf("Board[%d]:%d/n",i,board[i]);
    }
    free(board);
}