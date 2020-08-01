//Να γραφεί πρόγραμμα που να διαβάζει τα δεδομένα από ένα αρχείο
//να τα ταξινομεί,να βρίσκει τον μέσο όρο του αρχειού 
//και να τα εκτυπώνει σε αρχείο.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a;
    FILE *fp;
    char fn[100];
    int x;
    int cnt=0;
    printf("Give filename:");
    gets(fn);
    fp=fopen(fn,"r");
    while(fscanf(fp,"%d",&x)==1)
    {
       cnt++;
    }
    fclose(fp);
    a=(int *)malloc(cnt * sizeof(int));
    fp=fopen(fn,"r");
    int i=0;
    while(fscanf(fp,"%d",&x)==1)
    {
        a[i]=x;
        i++;
    }
    fclose(fp);
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<cnt-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int tem=a[j];
                a[j]=a[j+1];
                a[j+1]=tem;
            }
        }
    }
    double avg;
    int sum=0;
    for(int i=0;i<cnt;i++)
    {
        sum+=a[i];
    }
    avg=(double)sum/cnt;
    char save[100];
    printf("Give filename:");
    gets(save);
    fp=fopen(save,"w");
    for(int i=0;i<cnt;i++)
    {
        fprintf(fp,"a[%d]:%d\n",i,a[i]);
    }
    fprintf(fp,"avg:%.2lf\n",avg);
    fclose(fp);
}