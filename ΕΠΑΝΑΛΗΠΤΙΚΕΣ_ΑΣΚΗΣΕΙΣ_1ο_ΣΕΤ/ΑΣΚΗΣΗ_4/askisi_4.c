#include <stdio.h>
#include <stdlib.h>
int main()
{
    float *board=(float *)malloc(10 * sizeof(float));
    for(int i=0;i<10;i++)
    {
        do
        {
            printf("Give grade_%d:",i+1);
            scanf("%f",&board[i]);
        } while(board[i]<0.0 || board[i]>10.0);
    }
    int cnt=0;
    int pos=0;
    int posmin=0;
    float max=board[0];
    float min=board[0];
    for(int i=0;i<10;i++)
    {
        if(board[i]>max) 
        {
            max=board[i];
            pos=i;
        }
        if(board[i]<min)
        {
            min=board[i];
            posmin=i;
        }
        if(board[i]>=5.0)
        {
            cnt++;
        }
    }
    printf("Max:%.2f \t pos:%d\n",max,pos);
    printf("Min:%.2f \t pos:%d\n",min,posmin);
    printf("%.2lf\n",((double)cnt/10.0)*100.0);
}