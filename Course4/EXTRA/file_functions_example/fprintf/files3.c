#include <stdio.h>
#include <string.h>

void sort(int *a,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
double average(int *a,int s)
{
    int sum=0;
    for(int i=0;i<s;i++)
    {
        sum+=a[i];
    }
    return (double)sum/s;
}
int max(int *a,int s)
{
    int pos=0;
    int m=a[0];
    for(int i=1;i<s;i++)
    {
       if(a[i]>m)
       {
           m=a[i];
           pos=i;
       }
    }
    return pos;
}
int main()
{
    FILE *fp;
    char fn[100];
    do
    {
      printf("give filename:");
      gets(fn);
    }while(strlen(fn)==0);  
    int a[]={12,4,5,7,97,13,54,67};
    int size=sizeof(a)/sizeof(a[0]);
    //εκτύπωση μεγίστου και MO και ταξινομιμενου πίνακα
    fp=fopen(fn,"w");
    sort(a,size);
    fprintf(fp,"Sort table::\n");
    for(int i=0;i<size;i++)
    {
        fprintf("A[%d]:%d\n",i,a[i]);
    }
    fprintf(fp,"Average=%.2lf\n",average(a,size));
    fprintf(fp,"Max\t A[%d]=%d\n",max(a,size),a[max(a,size)]);
    fclose(fp);
}