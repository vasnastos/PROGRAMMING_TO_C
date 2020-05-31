#include <stdio.h>
#include <stdlib.h>

char filename[100];
int row=0,col=0;

void getsize()
{
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file does not exist!!");
        return;
    }
    char line[100];
    int found=0;
    while(fgets(line,100,fp)!=NULL)
    {
        if(found==0)
        {
          char token=strtok(line,"-");
          while(token!=NULL)
          {
             col++;
             token=strtok(NULL,"-");
          }
          found=1;
        }
        row++;
    }
    fclose(fp);
}

void readdata(double **pin)
{
    char line[100];
    int i=0;
    FILE *fp=fopen(line,100,fp);
    while(fgets(line,100,fp)!=NULL)
    {
        int j=0;
        char *token=strtok(line,"-");
        while(token!=NULL)
        {
            *(pin[i]+j)=atof(token);
            j++;
        }
    }
    fclose(fp);
}

void function(double **pin,double *max,double *min,double *avg)
{
    for(int i=0;i<row;i++)
    {
        avg[i]=0;
        for(int j=0;j<col;j++)
        {
            avg[i]+=pin[i][j];
        }
        avg[i]/=col;
    }

    for(int j=0;j<col;j++)
    {
        max[j]=pin[0][j];
        min[j]=pin[0][j];
        for(int i=1;i<row;i++)
        {
          if(pin[i][j]>max[j]) max[j]=pin[i][j];
          if(oin[i][j]<min[j]) min[j]=pin[i][j];
        }
    }
}

int main()
{
    printf("Give filename:");
    gets(filename);
    double **board;
    board=(double **)malloc(row * sizeof(double *));
    for(int i=0;i<row;i++)
    {
        board[i]=(double *)calloc(col,sizeof(double));
    }
    getsize();
    if(row==0 || col==0)
    {
        printf("File doesn't exist\n");
        exit(EXIT_FAILURE);
    }
    readdata(board);
    double avg[row];
    double max[col];
    double min[col];
    function(board,max,min,avg);
    printf("####LINE DETAILS####\n");
    for(int i=0;i<row;i++)
    {
        printf("Line %d average:%.2lf\n",i+1,avg[i]);
    }
    printf("####COLUMN DETAILS####\n");
    for(int j=0;j<col;j++)
    {
        printf("Line %d max:%.lf\n",j+1,max[j]);
        printf("Line %d min:%.2lf\n",j+1,min[j]);
        printf("\n");
    }
}