#include <stdio.h>
#include <stdlib.h>

int main()
{
    //ΔΗΛΩΣΗ ΑΚΕΡΑΙΟΥ ΔΕΙΚΤΗ
    int *a;
    int x=2;
    a=&x;
    printf("%d",*a);//2
    x=x+67;
    printf("%d",*a);//69
    (*a)--;
    printf("%d",x);//68
    printf("%d",*a);//68

    free(a);
    //printf("%d",*a);

    //ΔΥΝΑΜΙΚΗ ΔΕΣΜΕΥΣΗ ΜΝΗΜΗΣ
    int *b;
    b=(int *)malloc(sizeof(int));
    b=(int *)calloc(1,sizeof(int));

    //μέσω δείκτη να κατασκευάσω έναν πίνακα με δεκαδικούς αριθμούς 10
    double *board;
    board=(double *)malloc(10 * sizeof(double));
    board=(double *)calloc(10,sizeof(double));

    board=(double *)realloc(board,11 *sizeof(double));

    //Δισδιάστατοι πίνακες μέσω δεικτών
    int **a;
    a=(int **)malloc(row * sizeof(int *));
    for(int i=0;i<row;i++)
    {
        a[i]=(int *)malloc(col * sizeof(int));
    }

    for(int i=0;i<row;i++)
    {
        free(a[i]);//*(a+i)
    }
    free(a);    
}