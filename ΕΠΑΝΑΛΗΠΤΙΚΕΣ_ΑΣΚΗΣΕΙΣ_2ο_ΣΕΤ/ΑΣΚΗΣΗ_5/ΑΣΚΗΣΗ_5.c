#include <stdio.h>
#include <stdlib.h>

void function(int **pin,int r,int c,double *average,int *posmax,int *posmin)
{
     double max;
     double min;
     int sum=0;
     for(int i=0;i<r;i++)
     {
         max=pin[i][0];
         posmax[i]=0;
         min=pin[i][0];
         posmin[i]=0;
         for(int j=0;j<c;j++)
         {
            if(pin[i][j]>max) 
            {
                max=pin[i][j];
                posmax[i]=j;
            }
            if(pin[i][j]<min)
            {
                min=pin[i][j];
                posmin[i]=j;
            }
            sum+=pin[i][j];
         } 
     }
     *average=(double)sum/((r*c)*1.0);
}

int main()
{
    int board[5][5];
    int posmax[5];
    int posmin[5];
    double average;
    for(int i=0;i<5;i++)
    {
      for(int j=0;j<5;j++)
      {
          printf("give number:");
          scanf("%d",&board[i][j]);
      }
    }
    function(board,5,5,&average,posmax,posmin);//posmax[0]-->posmax+-->*(posmax+i)
    for(int i=0;i<5;i++)
    {
        printf("Position of max:%d\n",posmax[i]);//posmax+0
        printf("Position of min:%d\n",posmin[i]);
    }
    printf("Average:%.2lf\n",average);
}