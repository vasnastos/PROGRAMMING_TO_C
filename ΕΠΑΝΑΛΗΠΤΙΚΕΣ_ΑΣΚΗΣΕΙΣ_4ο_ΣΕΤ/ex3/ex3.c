#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define row 3
//#define col 4

int sum_of_column(int **pin,int j,int rows)
{
    int sum=0;
    for(int i=0;i<rows;i++)
    {
        sum+=pin[i][j];
    }
    return sum;
}

int main()
{
    int **table;
    //Δέσμευση μνήμης για δυσδιάσττο πίνακα.
    table=(int **)malloc(3 * sizeof(int *));
    for(int i=0;i<3;i++)
    {
        table[i]=(int *)malloc(4 * sizeof(int));
    }
    //Εισαγωγή τιμών από χρήστη
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("Give table[%d][%d]:",i,j);
            scanf("%d",&table[i][j]);
        }
    }
    //Εκτύπωση αποτελεσμάτων σε αρχείο.
    FILE *fp;
    char filename[100];
    fflush(stdin);
    //όνομα αρχείου
    printf("Give filename:");
    gets(filename);
    fp=fopen(filename,"w");
    //w-->Άνοιγμα αρχελιου για γράψιμο.
    //Εκτύπωση σε αρχείο για το άθροισμα όλων των γραμμών του πίνακα.
    for(int j=0;j<4;j++)
    {
       int result=sum_of_column(table,j,3);
       fprintf(fp,"Sum of column %d:%d\n",j+1,result);
    }
    fclose(fp);
    for(int i=0;i<3;i++)
    {
        free(table[i]);
    }
    free(table);
}