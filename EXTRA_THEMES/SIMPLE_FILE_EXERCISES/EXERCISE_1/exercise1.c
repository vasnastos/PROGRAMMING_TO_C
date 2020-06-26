#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char filename[100];

void read_data(double argument)
{
    int cntmax=0;
    int i=0;
    double max;
    double sum=0.0;
    double number;
    FILE *fp=fopen(filename,"r");
    while(fscanf(fp,"%lf",&number)>0)
    {
        if(i==0)
        {
            max=number;
            cntmax=1;
        }
        else if(number>max)
        {
            max=number;
            cntmax=1;
        }
        else if(number==max)
        {
            cntmax++;
        }
        sum+=number;
        i++;
    }
    fclose(fp);
    double *board=(double *)malloc(i * sizeof(double));
    i=0;
    fp=fopen(filename,"r");
    while(fscanf(fp,"%lf",&number)>0)
    {
        board[i]=number;
        i++;
    }
    fclose(fp);
    int cnt_arg=0;
    printf("########RESULTS#########\n");
    printf("max found on file:%d\n",cntmax);
    for(int j=0;j<i;j++)
    {
        if(board[j]>argument)
        {
            cnt_arg++;
        }
        if(board[j]==max)
        {
           printf("Max found in position:%d\n",j+1);
        }
    }
    printf("Numbers over %.2lf argument are:%d\n",argument,cnt_arg);
    printf("SQRT of sum in file is:%.2lf\n",sqrt(sum));
    printf("########################\n");
    free(board);
}

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        perror("Please run again the program with the correct number of arguments!!!!\n");
        exit(EXIT_FAILURE);
    }
    double argument=atof(argv[1]);
    strcpy(filename,argv[2]);
    read_data(argument);
}