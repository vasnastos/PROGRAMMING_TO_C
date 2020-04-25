#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    fp=fopen("files1.txt","r");
    //With fscanf
    int x;
    int cnt=0;
    while(fscanf(fp,"%d",&x)==1)
    {
        cnt++;
    }
    fclose(fp);
    int *board;
    board=(int *)malloc(cnt * sizeof(int));
    fp=fopen("files1.txt","r");
    int j=0;
    while(fscanf(fp,"%d",&x)==1)
    {
        board[j]=x;
        j++;
    }
    fclose(fp);
    if(j<cnt)
    {
        printf("Error on reading data!!!");
    }
    else
    {
        for(int i=0;i<cnt;i++)
        {
            printf("Board[%d]:%d/n",i,board[i]);
        }
    }
    free(board);
}