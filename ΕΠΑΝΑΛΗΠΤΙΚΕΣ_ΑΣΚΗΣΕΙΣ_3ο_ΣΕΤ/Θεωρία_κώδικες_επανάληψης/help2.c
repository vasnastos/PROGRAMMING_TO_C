#include <stdio.h>
//Εύρεση μεγίστου ανά γραμμή
void maxperrow(int **board,int row,int col,int *max)
{
    for(int i=0;i<row;i++)
    {
        max[i]=board[i][0];
        for(int j=1;j<col;j++)
        {
           if(max[i]<board[i][j])
           {
               max[i]=board[i][j];
           }
        }
    }
}
//Εύρεση μέσου όρου ανά στήλη
void avgpercolumn(int **board,int row,int col,double *avg)
{
    for(int j=0;j<col;j++)
    {
        int sum=0;
        for(int i=0;i<row;i++)
        {
            sum+=board[i][j];
        }
        avg[j]=sum/(row * 1.0);
    }
}

//Εύρεση αθροίσματος ανά γραμμή 
void sumperrow(int **board,int row,int col,int *sum)
{
    for(int i=0;i<row;i++)
    {
        sum[i]=0;
        for(int j=0;j<col;j++)
        {
           sum[i]+=board[i][j];
        }
    }
}

//Εύρεση ελαχίστου στήλης
void minpercolumn(int **board,int row,int col,int *min)
{
    for(int j=0;j<col;j++)
    {
        min[j]=board[0][j];
        for(int i=1;i<row;i++)
        {
           if(min[j]>board[i][j])
           {
               min[j]=board[i][j];
           }
        }
    }
}

int main()
{
    int board[3][3]={{1,4,8},
                    {6,12,45},
                    {7,43,21}};
    int max[3];
    double avgcol[3];
    int sumperrow[3];
    int mincol[3];
    maxperrow(board,3,3,max);
    avgpercolumn(board,3,3,avgcol);
    sumperrow(board,3,3,sumperrow);
    minpercolumn(board,3,3,mincol);
}