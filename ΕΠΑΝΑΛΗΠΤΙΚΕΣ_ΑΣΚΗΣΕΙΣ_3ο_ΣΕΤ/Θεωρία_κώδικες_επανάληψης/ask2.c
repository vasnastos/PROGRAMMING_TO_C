//Υπολογισμός αθροίσματος ανά γραμμή,με την χρήση συνάρτησης
void a(int **x,int row,int col,int *pin)
{
    for(int i=0;i<row;i++)
    {
        int sum=0;
        for(int j=0;j<col;j++)
        {
            sum+=x[i][j];
        }
        pin[i]=sum/(col * 1.0);
    }
}

int main()
{
    int k[2][5]={{1,3,4,5,6},
                 {6,3,1,8,4}};
    int sum[2];
    //Κλήση συνάρτησης
    a(k,2,5,sum);
    //Αποτελέσμα που περάστηκαν από την συνάρτηση στον πίνακα sum.
    printf("%d",sum[0]);//19
    printf("%d",sum[1]);//22
}