#include <stdio.h>
double average(double w[],int length)
{
    double s=0.0;
    for(int i=0;i<length;i++)
    {
        s+=w[i];
    } 
    return s/length;
}
int main()
{
    int s;
    printf("Give amount of cargo::");
    scanf("%d",&s);
    int id[s];  //cargo
    double weight[s]; //cargo
    for(int i=0;i<s;i++)
    {
        printf("Give Id:");
        scanf("%d",&id[i]);
        printf("Give weight of cargo:");
        scanf("%lf",&weight[i]);
        printf("\n");
    }
    //bubblesort
    for(int i=0;i<s-1;i++)
    {
        for(int j=0;j<s-i-1;j++)
        {
            if(weight[j]>weight[j+1])
            {
                double t=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=t;
                int t1=id[j];
                id[j]=id[j+1];
                id[j+1]=t1;
            }
        }
    }
    printf("SORTED LIST OF CARGOS!!!\n");
    for(int i=0;i<s;i++)
    {
        printf("ID:%d \t weight:%.2lf\n",id[i],weight[i]);
    }
    //ολοκλήρωση και εκτύπωση ταξηνομιμένου φορτίου
    printf("AVERAGE WEIGHT=%.2lf\n",average(weight,s)); //εκτύπωση μέσου όρου
    return 0;

}